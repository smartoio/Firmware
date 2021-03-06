/*
 *
 * Filename: set_motor_output.c
 * Authors: Luca De Luigi, Paolo Di Febbo
 *
 * Description:
 * Demone che si occupa di applicare l'output ai motori prelevandolo
 * direttamente dal topic uORB motor_output
 *
 * NOTE:
 * prima di avviarlo e' necessario eseguire
 *		uorb start
 * in piu', vanno caricati i driver per l'output pwm:
 * nel caso di PX4FMU (pin servo on-board):
 *		fmu mode_pwm
 * nel caso di PX4IO:
 *		px4io start
 *
 */

#include <nuttx/config.h>
#include <nuttx/sched.h>

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <poll.h>
#include <sys/mount.h>
#include <sys/ioctl.h>
#include <sys/stat.h>

#include <stdbool.h>
#include <uORB/uORB.h>
#include <uORB/topics/motor_output.h>

#include <nuttx/i2c.h>
#include <nuttx/mtd.h>
#include <nuttx/fs/nxffs.h>
#include <nuttx/fs/ioctl.h>

#include <drivers/drv_pwm_output.h>

#if !defined(ATECH) && !defined(IRIS)
	#error "You must define ATECH or IRIS macros"
#endif

// numero di motori effettivamente collegati
#ifdef ATECH
	#define MOTORS_START 4
	#define MOTORS_NUMBER 8
#endif
#ifdef IRIS
	#define MOTORS_START 0
	#define MOTORS_NUMBER 4
#endif

/* Deamon libraries? */
#include <systemlib/systemlib.h>
#include <systemlib/err.h>
// globali per thread
static bool unibomo_thread_should_exit = false;
static bool unibomo_thread_running = false;
static int unibomo_unibo_motor_task;

// fd globale per scrittura su pwm
static int pwm_fd;

/* create topic metadata */
//ORB_DEFINE(motor_output, motor_output_s);

__EXPORT int unibo_motor_output_main(int argc, char *argv[]);

int unibo_motor_output_thread_main(int argc, char *argv[]);

static void usage(const char *reason)
{
	if (reason)
	{
		warnx("%s\n", reason);
	}
	warnx("usage: unibo_motor_output {start|stop|status|test}\n");
	exit(1);
}

// inizializzazione servo
void unibo_motor_output_init()
{
	int ret = 0;

	pwm_fd = open("/dev/pwm_output", O_RDWR);
	if (pwm_fd < 0)
	{
		warnx("cannot open fd\n");
		exit(1);
	}

	// eventuale impostazione PWM_SERVO_SET_UPDATE_RATE, vedi pwm.c

	ret = ioctl(pwm_fd, PWM_SERVO_ARM, 0);
	if (ret != OK)
	{
		warnx("errore arm\n");
		exit(1);
	}
	int i;
	for(i = MOTORS_START; i < MOTORS_NUMBER; i++)
	{
		ioctl(pwm_fd, PWM_SERVO_SET(i), 900);
	}
}

// deinizializzazione servo
void unibo_motor_output_deinit()
{
	int ret;
	ret = ioctl(pwm_fd, PWM_SERVO_DISARM, 0);
	if (ret != OK)
	{
		warnx("errore disarm\n");
		exit(1);
	}
}

// test dei pin di output
void unibo_motor_output_test()
{
	warnx("[unibo_motor_output] testing... you should see 6 sec of output \"blinking\"\n");

	unibo_motor_output_init();

	int i, k;
	for(i = 0; i < 3; i++)
	{
		for(k = MOTORS_START; k < MOTORS_NUMBER; k++)
		{
			ioctl(pwm_fd, PWM_SERVO_SET(k), 0);
		}
		sleep(1);

		for(k = MOTORS_START; k < MOTORS_NUMBER; k++)
		{
			ioctl(pwm_fd, PWM_SERVO_SET(k), 1200);
		}
		sleep(1);
	}

	unibo_motor_output_deinit();

	warnx("[unibo_motor_output] test completed.\n");
}


// gestore demone
int unibo_motor_output_main(int argc, char *argv[])
{
	// controllo argomenti
	/* OLD
	if(argc != 2 && argc != 3)
	{
		usage("wrong arguments length");
	}

	if(argc == 2 && (strcmp(argv[1], "start") == 0 || strcmp(argv[1], "test") == 0))
	{
		usage("start and test commands require {fmu|io}");
	}

	if(argc == 3 && (strcmp(argv[2], "fmu") != 0 && strcmp(argv[2], "io") != 0))
	{
		usage("second argument must be 'fmu' or 'io'");
	}
	*/
	if(argc != 2)
	{
		usage("wrong arguments length");
	}

	if (strcmp(argv[1], "start") == 0)
	{
		if (unibomo_thread_running)
		{
			warnx("daemon already running\n");
			exit(0);
		}

		unibomo_thread_should_exit = false;

		unibomo_unibo_motor_task = task_spawn_cmd("unibo_motor_output",
					SCHED_DEFAULT,//SCHED_RR,
					SCHED_PRIORITY_MAX - 11, //SCHED_PRIORITY_DEFAULT,
					1024,
					unibo_motor_output_thread_main,
					(argv) ? (const char **)&argv[2] : (const char **)NULL);

		warnx("Thread started PID: %d",unibomo_unibo_motor_task);
		exit(0);
	}

	if (strcmp(argv[1], "stop") == 0)
	{
		unibomo_thread_should_exit = true;
		exit(0);
	}

	if (strcmp(argv[1], "status") == 0)
	{
		if (unibomo_thread_running)
		{
			warnx("\tunibo_motor_output is running\n");
		}
		else
		{
			warnx("\tunibo_motor_output not started\n");
		}
		exit(0);
	}

	if (strcmp(argv[1], "test") == 0)
	{
		unibo_motor_output_test();
		exit(0);
	}

	usage("unrecognized command");
	exit(1);
}

// thread principale con loop
int unibo_motor_output_thread_main(int argc, char *argv[])
{
	int count=0;
	warnx("[unibo_motor_output] starting\n");
	unibomo_thread_running = true;

	// subscribe a ORB
	int motor_output_fd = orb_subscribe(ORB_ID(motor_output));
	orb_set_interval(motor_output_fd, 3);

	struct pollfd fds[] = { { .fd = motor_output_fd, .events = POLLIN } };

	unibo_motor_output_init();

	int i;
	int motor_mapping; // mapping dei motori differente fra l'IRIS e il quadrotor UNIBO
	struct motor_output_s pwm_values;

	// PWM to 0 initially
//	for(i = MOTORS_START; i < MOTORS_NUMBER; i++)
//	{
//		ioctl(pwm_fd, PWM_SERVO_SET(i), 0);
//	}

	// loop dell'applicazione
	while (!unibomo_thread_should_exit)
	{
		// controllo se ci sono nuovi dati
		int poll_ret = poll(fds, 1, 100);     //forse si pu� mettere (fds, 3, 1000) per andare a 333Hz
		if(poll_ret > 0)
		{
			if(fds[0].revents & POLLIN)
			{
				// lettura ORB
				//warnx("Nuovo valore pwm: %d %d %d %d %d %d %d %d", pwm_values.outputs[0], pwm_values.outputs[1], pwm_values.outputs[2], pwm_values.outputs[3],pwm_values.outputs[4], pwm_values.outputs[5], pwm_values.outputs[6], pwm_values.outputs[7]);
				orb_copy(ORB_ID(motor_output), motor_output_fd, &pwm_values);

				// scrittura su pin output
				count++;
				for(i = MOTORS_START; i < MOTORS_NUMBER; i++)
				{
#ifdef ATECH
					motor_mapping = i;
#endif
#ifdef IRIS
					switch (i){
						case 0:
							motor_mapping = 2;
							break;
						case 1:
							motor_mapping = 0;
							break;
						case 2:
							motor_mapping = 3;
							break;
						case 3:
							motor_mapping = 1;
							break;
					}
#endif
					ioctl(pwm_fd, PWM_SERVO_SET(motor_mapping), pwm_values.outputs[i]);
				}
			}
		}
	}

    unibo_motor_output_deinit();

    warnx("[unibo_motor_output] exiting.\n");

    unibomo_thread_running = false;

	return 0;
}

