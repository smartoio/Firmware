/****************************************************************************
 *
 *   Copyright (C) 2012 PX4 Development Team. All rights reserved.
 *   Author: @author UNIBO Team <mail@example.com>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/**
 * @file unibo_control.c
 * UNIBO autopilot for PX4 framework.
 */

#include <nuttx/config.h>
#include <nuttx/sched.h>
#include <stdio.h>
#include <errno.h>

#include <unistd.h>
#include <poll.h>
#include <stdbool.h>
#include <uORB/uORB.h>
#include <uORB/topics/sensor_combined.h>
#include <uORB/topics/vehicle_attitude.h>
#include <uORB/topics/motor_output.h>
#include <uORB/topics/unibo_reference.h>
#include <uORB/topics/unibo_parameters.h>
#include <uORB/topics/unibo_optitrack.h>
#include <uORB/topics/unibo_telemetry.h>

/* Deamon libraries? */
#include <systemlib/systemlib.h>
#include <systemlib/err.h>
/* Deamon variables */
static bool uniboc_thread_should_exit = false;		/**< daemon exit flag */
static bool uniboc_thread_running = false;		/**< daemon status flag */
static int uniboc_unibo_control_task;				/**< Handle of daemon task / thread */


//#include <mavlink\mavlink_bridge_header.h>
//#include <mavlink_onboard\mavlink_bridge_header.h>
//#include <uORB/topics/sensor_combined.h>

/**
 * daemon management function.
 */
__EXPORT int unibo_control_main(int argc, char *argv[]);

/**
 * Mainloop of daemon.
 */
int unibo_control_thread_main(int argc, char *argv[]);


/* create custom topic metadata */
//ORB_DEFINE(motor_output, struct motor_output_s);
//topic definito nel file objects_common.cpp (assieme agli altri)

/*
 * |-----------------------------------------------------|
 * |                 CUSTOM INCLUDES!                    |
 * |-----------------------------------------------------|
 */

#include "main_includes.h"
#include "main_procedures.h"
#include "utils.h"

// Variabili globali, usate anche dalle procedure in main_procedures.cpp
//int serial_PX4, serial_XBee;
int sdParameters, sdCINPUTS, sdOptitrack, sdGS, sdIMU;
struct timeval tv;
//struct sigaction sact;
//timeval cTime;
RT_MODEL_Model_GS* model;



/**
 * Print the correct usage.
 */
static void usage(const char *reason);

static void
usage(const char *reason)
{
	if (reason)
		warnx("%s\n", reason);
	errx(1, "usage: unibo_control {start|stop|status} [-p <additional params>]\n\n");
}

/**
 * The daemon app only briefly exists to start
 * the background job. The stack size assigned in the
 * Makefile does only apply to this management task.
 *
 * The actual stack size should be set in the call
 * to task_create().
 */
int unibo_control_main(int argc, char *argv[])
{
	if (argc < 1)
		usage("missing command");

	if (!strcmp(argv[1], "start")) {

		if (uniboc_thread_running) {
			warnx("daemon already running\n");
			/* this is not an error */
			exit(0);
		}

		uniboc_thread_should_exit = false;
		uniboc_unibo_control_task = task_spawn_cmd("unibo_control",
					 SCHED_DEFAULT,
					 //SCHED_PRIORITY_DEFAULT,
					 SCHED_PRIORITY_MAX - 15,
					 4096*2,
					 unibo_control_thread_main,
					 (argv) ? (const char **)&argv[2] : (const char **)NULL);
		warnx("Thread started PID: %d",uniboc_unibo_control_task);
		exit(0);
	}

	if (!strcmp(argv[1], "stop")) {
		uniboc_thread_should_exit = true;
		exit(0);
	}

	if (!strcmp(argv[1], "status")) {
		if (uniboc_thread_running) {
			warnx("\trunning\n");
		} else {
			warnx("\tnot started\n");
		}
		exit(0);
	}

	usage("unrecognized command");
	exit(1);
}

/**
 * Main execution thread
 */
int unibo_control_thread_main(int argc, char *argv[])
//int simple_test_app_main(int argc, char *argv[])
{
	warnx("[unibo_control] starting\n");

	uniboc_thread_running = true;

	warnx("Hello Sky!\n");
	model = Model_GS(); //Init model!

	/* subscribe to attitude topic */
	int sensor_sub_fd = orb_subscribe(ORB_ID(vehicle_attitude));
	/* set data to 1Hz */
	orb_set_interval(sensor_sub_fd, 5); //1000 = 1Hz (ms)

	/* subscribe to reference topic */
	int reference_sub_fd = orb_subscribe(ORB_ID(unibo_reference));

	/* subscribe to Optitrack topic */
	int optitrack_sub_fd = orb_subscribe(ORB_ID(unibo_optitrack));

	/* subscribe to unibo_parameters topic */
	int parameters_sub_fd = orb_subscribe(ORB_ID(unibo_parameters));

	/* advertize telemetry topic */
	struct unibo_telemetry_s telem;
	memset(&telem, 0, sizeof(telem));
	int unibo_telem_pub_fd = orb_advertise(ORB_ID(unibo_telemetry), &telem);




	/* advertise attitude topic */
//	struct vehicle_attitude_s att;
//	memset(&att, 0, sizeof(att));
//	int att_pub_fd = orb_advertise(ORB_ID(vehicle_attitude), &att);

	/* advertise motor output topic */
	struct motor_output_s mout;
	memset(&mout, 0, sizeof(mout));
	int mout_pub_fd = orb_advertise(ORB_ID(motor_output), &mout);

	/* one could wait for multiple topics with this technique, just using one here */
	struct pollfd fds[] = {
		{ .fd = sensor_sub_fd,   .events = POLLIN },
		/* there could be more file descriptors here, in the form like:
		 * { .fd = other_sub_fd,   .events = POLLIN },
		 */
	};

	int error_counter = 0;


	/*
	 * |-----------------------------------------------------|
	 * |                  INIT VARIABLES!                    |
	 * |-----------------------------------------------------|
	 */

	int len;
	static char udp_receive_buffer[LENGTH]; // buffer di lettura UDP

	// init function to initialize the ports and the sockets
	//init(argc, argv);                                                 CHANGED SEEMS USELESS

	// inizializzazione middle-layer
	//static PacketREFERENCES_s pkgRef;
	//PacketIMU_s pkgIMU;
	struct vehicle_attitude_s ahrs;
//	static PacketPARAMETERS_s pkgPar;
//	static PacketTELEMETRY_s pkgTel;
//	static PacketOFLOW_s pkgOflow;
//	static PacketSTATE_s pkgState;
//	static PacketACK_s pkgAck;
//	static PacketOPTITRACK_s pkgOpti;

	cInputs_s cinputs;

	//printf("STARTING...\n");
	LLFFC_start();
	//PacketIMU_loadPacketIMU(&pkgIMU);
//	utils_loadAHRSPacket(ahrs);
	//pkgIMU.loadPacketIMU();
//	PacketREFERENCES_loadPacketREFERENCES(&pkgRef);
//	PacketPARAMETERS_loadPacketPARAMETERS(&pkgPar);
//	PacketTELEMETRY_loadPacketTELEMETRY(&pkgTel);
//	PacketOFLOW_loadPacketOFLOW(&pkgOflow);
//	PacketOPTITRACK_loadPacketOPTITRACK(&pkgOpti);
//	LLFFC_control();


	static int optitrack_counter = 0;
	static int parameters_counter = 0;
	static int print_counter = 0;
	static int print_counter2 = 0;
	static int gs_counter = 0;
	static int log_counter = 0;
	//len = sizeof(struct sockaddr_in);
	static int writtenChars = 0;
	static unsigned long tAtom = 0;
	static unsigned long tTime = 0;
	static unsigned long tTimeOld = 0;
	static unsigned long tTimeDiff = 0;
	static int count_missed = 0;

	// variabili input serial PX4
	//mavlink_status_t px4_lastStatus;
	//px4_lastStatus.packet_rx_drop_count = 0;
	//uint8_t px4_input_char;
	//mavlink_message_t px4_input_message;
	//mavlink_status_t px4_input_status;
	//uint8_t px4_msgReceived = false;

	// variabili output serial PX4
	//mavlink_message_t px4_output_message;
	//mavlink_servo_output_raw_t px4_output;
	//unsigned px4_output_len;
	//char px4_output_buffer[300];

	// Round Buffer for REF packet
	static char round_buffer_REF[LENGTH*4];
	static char packet_REF[LENGTH];
	static int pos_REF=0;
	static int start_REF=0;
	static int lastSidx_REF = -1;
	static bool REF_packet_ready = false;

	memset(round_buffer_REF,0,sizeof(round_buffer_REF));
	memset(packet_REF,0,LENGTH);

	static long AckDiff[ACKDLEN];
	memset(AckDiff,0,sizeof(AckDiff));
	static long AckDiffMin = 1000000000L;
	static long AckDiffMax = 0;
	// int ackbcount = 0; TODO usata da ACK

	static unsigned long loopMaxTime = 0;
	static int resetTimeCounter = 0;

	static long imuTime[ACKDLEN];
	memset(imuTime,0,sizeof(imuTime));
	static long imuTimeMin = 1000000000L;
	static long imuTimeMax = 0;

	int counter_ref_pack=0;
	int counter_opti_pack=0;
	int telemetry_counter=0;

	/* Bool for topics update */
	bool updated;


	//printf("READY\n\n");
	warnx("READY\n");

	static bool FirstFlg = true;

	/*
	 * |-----------------------------------------------------|
	 * |                MAIN THREAD LOOP!                    |
	 * |-----------------------------------------------------|
	 */


	int txtcounter = 0;

	while (!uniboc_thread_should_exit) {
		/* wait for sensor update of 1 file descriptor for 1000 ms (1 second) */
		//Imposto solo 10 ms
		int poll_ret = poll(fds, 1, 10); //filedescr, number of file descriptor to wait for, timeout in ms
		//TODO: INSERIRE QUI INIZIALIZZAZIONI PRE-LOOP AD OGNI LOOP

		/* handle the poll result */
		if (poll_ret == 0) {
			/* this means none of our providers is giving us data */
			//warnx("[unibo_control_thread] Got no data within poll interval\n"); //i 10 ms impostati poco sopra, il topic cmq dovrebbe arrivare a 500hz (2ms)
		} else if (poll_ret < 0) {
			/* this is seriously bad - should be an emergency */
			if (error_counter < 10 || error_counter % 50 == 0) {
				/* use a counter to prevent flooding (and slowing us down) */
				warnx("[unibo_control_thread] ERROR return value from poll(): %d\n"
					, poll_ret);
			}
			error_counter++;
		} else {
			if (fds[0].revents & POLLIN) {
				//TECNICAMENTE SIAMO GIA' A 333HZ, freq del topic di assetto   (o 200???)
				log_counter++;
				telemetry_counter++;
				txtcounter++;

				/* copy sensors raw data into local buffer */
				orb_copy(ORB_ID(vehicle_attitude), sensor_sub_fd, &ahrs);
				/* copy sensors local buffer to Simulink Model */
				Model_GS_U.Attitude[0] = ahrs.q[0];           //multipliyng for simulink and to send int data instead of float without precision loss
				Model_GS_U.Attitude[1] = ahrs.q[1];
				Model_GS_U.Attitude[2] = ahrs.q[2];
				Model_GS_U.Attitude[3] = ahrs.q[3];
				Model_GS_U.AngSpeed[0] = ahrs.rollspeed;
				Model_GS_U.AngSpeed[1] = ahrs.pitchspeed;
				Model_GS_U.AngSpeed[2] = ahrs.yawspeed;
				if (txtcounter>3330){
//					warnx("RPY:\t%1.4f %1.4f %1.4f - %1.4f %1.4f %1.4f %1.4f\n",
//						(double)ahrs.roll,
//						(double)ahrs.pitch,
//						(double)ahrs.yaw,
//						(double)ahrs.q[0],
//						(double)ahrs.q[1],
//						(double)ahrs.q[2],
//						(double)ahrs.q[3]);
					warnx(".");
					txtcounter = 0;
				}

				/*
				 * |-----------------------------------------------------|
				 * |                CONTROL LOOP!                        |
				 * |-----------------------------------------------------|
				 */

				print_counter++;
				// XXX copiate
				if (resetTimeCounter > RST_TCOUNT){
					AckDiffMin = 1000000000L;
					AckDiffMax = 0;
					loopMaxTime = 0;
					imuTimeMin = 1000000000L;
					imuTimeMax = 0;

					resetTimeCounter = 0;
				}

//				tTime = getMyTime();
//				tAtom = tTime/1000 % 30000;
//				LLFFC_updateModelAtomTime(tAtom);
//				tTime=utils_getCurrentTime();
//				tTimeDiff = tTime - tTimeOld;
//				tTimeOld = tTime;
//				LLFFC_updateModelAtomTime(tAtom);
				// XXX FINE copiate

				if (FirstFlg)
				{
					warnx("START.\n");
					FirstFlg = false;
				}

				// TODO eventuali benchmark di tempo

				// se viene stampato un messaggio circa ogni secondo vuol dire che va tutto bene
				if (print_counter++ >= 333)
				{
					//warnx(".");
					//warnx("pkgimu (length, type, gyro xyz, acc xyz, mag xyz, deltat, time, crc):\n %s\n", PacketIMU_toString(&pkgIMU));
					print_counter = 0;
				}


				if(DEBUG_MODE) // TODO sistemare
				{

				}

				// gestione pacchetto REFERENCES ricevuto dal Topic unibo_reference
				orb_check(reference_sub_fd, &updated);
				if (updated){
					struct unibo_reference_s temp_ref;
					orb_copy(ORB_ID(unibo_reference),reference_sub_fd,&temp_ref);
					Model_GS_U.REF_TIME[0] = temp_ref.length;
					Model_GS_U.REF_TIME[1] = temp_ref.type;
					Model_GS_U.REF_TIME[2] = temp_ref.p_x;
					Model_GS_U.REF_TIME[3] = temp_ref.p_y;
					Model_GS_U.REF_TIME[4] = temp_ref.p_z;
					Model_GS_U.REF_TIME[5] = temp_ref.dp_x;
					Model_GS_U.REF_TIME[6] = temp_ref.dp_y;
					Model_GS_U.REF_TIME[7] = temp_ref.dp_z;
					Model_GS_U.REF_TIME[8] = temp_ref.ddp_x;
					Model_GS_U.REF_TIME[9] = temp_ref.ddp_y;
					Model_GS_U.REF_TIME[10] = temp_ref.ddp_z;
					Model_GS_U.REF_TIME[11] = temp_ref.psi;
					Model_GS_U.REF_TIME[12] = temp_ref.d_psi;
					Model_GS_U.REF_TIME[13] = temp_ref.dd_psi;
					Model_GS_U.REF_TIME[14] = temp_ref.q;
					Model_GS_U.REF_TIME[15] = temp_ref.button;
					Model_GS_U.REF_TIME[16] = temp_ref.timestamp;
					Model_GS_U.REF_TIME[17] = temp_ref.CRC;
					//warnx("Position reference from topic: %d %d %d\n",temp_ref.p_x,temp_ref.p_y,temp_ref.p_z);
//					counter_ref_pack++;
//					if (counter_ref_pack>=20){
//						warnx("Ricevuti 20 pacchetti reference.");
//						counter_ref_pack=0;
//					}
				}

				// gestione pacchetto OPTITRACK ricevuto dal Topic unibo_optitrack
				orb_check(optitrack_sub_fd, &updated);
				if (updated){
					struct unibo_optitrack_s temp_opti;
					orb_copy(ORB_ID(unibo_optitrack),optitrack_sub_fd,&temp_opti);
					Model_GS_U.OPTITRACK[0] = temp_opti.length;
					Model_GS_U.OPTITRACK[1] = temp_opti.type;
					Model_GS_U.OPTITRACK[2] = temp_opti.pos_x;
					Model_GS_U.OPTITRACK[3] = temp_opti.pos_y;
					Model_GS_U.OPTITRACK[4] = temp_opti.pos_z;
					Model_GS_U.OPTITRACK[5] = temp_opti.q0;
					Model_GS_U.OPTITRACK[6] = temp_opti.q1;
					Model_GS_U.OPTITRACK[7] = temp_opti.q2;
					Model_GS_U.OPTITRACK[8] = temp_opti.q3;
					Model_GS_U.OPTITRACK[9] = temp_opti.err;
					Model_GS_U.OPTITRACK[10] = temp_opti.timestamp;
					Model_GS_U.OPTITRACK[11] = temp_opti.CRC;
					//warnx("Optitrack from topic: %d %d %d\n",temp_opti.pos_x,temp_opti.pos_y,temp_opti.pos_z);
//					counter_opti_pack++;
//					if (counter_opti_pack>=50){
//						warnx("Ricevuti 50 pacchetti OPTITRACK.");
//						counter_opti_pack=0;
//					}
				}

				// gestione pacchetto parameters ricevuto dal Topic unibo_optitrack
				orb_check(parameters_sub_fd, &updated);
				if (updated){
					struct unibo_parameters_s temp_PAR;
					orb_copy(ORB_ID(unibo_parameters),parameters_sub_fd,&temp_PAR);
					Model_GS_U.PARAMETERS[0] = temp_PAR.length;
					Model_GS_U.PARAMETERS[1] = temp_PAR.type;
					Model_GS_U.PARAMETERS[2] = temp_PAR.in1;
					Model_GS_U.PARAMETERS[3] = temp_PAR.in2;
					Model_GS_U.PARAMETERS[4] = temp_PAR.in3;
					Model_GS_U.PARAMETERS[5] = temp_PAR.in4;
					Model_GS_U.PARAMETERS[6] = temp_PAR.in5;
					Model_GS_U.PARAMETERS[7] = temp_PAR.in6;
					Model_GS_U.PARAMETERS[8] = temp_PAR.in7;
					Model_GS_U.PARAMETERS[9] = temp_PAR.in8;
					Model_GS_U.PARAMETERS[10] = temp_PAR.in9;
					Model_GS_U.PARAMETERS[11] = temp_PAR.in10;
					Model_GS_U.PARAMETERS[12] = temp_PAR.in11;
					Model_GS_U.PARAMETERS[13] = temp_PAR.in12;
					Model_GS_U.PARAMETERS[14] = temp_PAR.in13;
					Model_GS_U.PARAMETERS[15] = temp_PAR.in14;
					Model_GS_U.PARAMETERS[16] = temp_PAR.in15;
					Model_GS_U.PARAMETERS[17] = temp_PAR.in16;
					Model_GS_U.PARAMETERS[18] = temp_PAR.in17;
					Model_GS_U.PARAMETERS[19] = temp_PAR.in18;
					Model_GS_U.PARAMETERS[20] = temp_PAR.in19;
					Model_GS_U.PARAMETERS[21] = temp_PAR.in20;
					Model_GS_U.PARAMETERS[22] = temp_PAR.in21;
					Model_GS_U.PARAMETERS[23] = temp_PAR.in22;
					Model_GS_U.PARAMETERS[24] = temp_PAR.in23;
					Model_GS_U.PARAMETERS[25] = temp_PAR.in24;
					Model_GS_U.PARAMETERS[26] = temp_PAR.timestamp;
					Model_GS_U.PARAMETERS[27] = temp_PAR.CRC;
					//warnx("Parameters from topic: %d %d %d\n",temp_PAR.in1,temp_PAR.in2,temp_PAR.in3);
				}


				// ----------- CONTROLLO -----------
				LLFFC_control();

				// ---- Riempio oggetto CInputs con i valori generati in output dal controllo ----
				CInputs_readCInputs(&cinputs);


				// riempimento del pacchetto mavlink servo_output_raw a partire dall'output del controllo (cinputs)
				// la funzione comprende anche la scalatura dal range 0..4095 di cinputs a 900..2100 dei microsecondi pwm (usati da px4)
				scale_cinputs_to_px4pwm(&mout, &cinputs);

				// ---- INVIO OUTPUTS ----
				// codifica e invio del pacchetto mavlink
				//mavlink_msg_servo_output_raw_encode(200, 0, &px4_output_message, &px4_output);
				//px4_output_len = mavlink_msg_to_send_buffer((uint8_t*)px4_output_buffer, &px4_output_message);
				//write(serial_PX4, px4_output_buffer, px4_output_len);
				//Invio topic orb motor_output!
				/* set att and publish this information for other apps */
				//mout.outputs = cinputs.u; --> Imposto i valori di mout dentro la funzione di scale!
				orb_publish(ORB_ID(motor_output), mout_pub_fd, &mout);

				//tcflush(serial_PX4, TCOFLUSH);


				//TELEMETRIA UART
				if (telemetry_counter >= 50){                     //4Hz if running at 200 Hz
					telemetry_counter=0;
					telem.x = Model_GS_Y.STATE[0];
					telem.y = Model_GS_Y.STATE[1];
					telem.z = Model_GS_Y.STATE[2];
					telem.dx = Model_GS_Y.STATE[3];
					telem.dy = Model_GS_Y.STATE[4];
					telem.dz = Model_GS_Y.STATE[5];
					telem.phi = Model_GS_Y.STATE[6];
					telem.theta = Model_GS_Y.STATE[7];
					telem.psi = Model_GS_Y.STATE[8];
					telem.wx = Model_GS_Y.STATE[9];
					telem.wy = Model_GS_Y.STATE[10];
					telem.wz = Model_GS_Y.STATE[11];
					telem.cinput1 = cinputs.u[0];
					telem.cinput2 = cinputs.u[1];
					telem.cinput3 = cinputs.u[2];
					telem.cinput4 = cinputs.u[3];
					//warnx("Cinputs: %u %u %u %u", telem.cinput1,telem.cinput2,telem.cinput3,telem.cinput4);
					//warnx("Attitude: Roll: %d----- Pitch: %d ------- Yaw: %d", telem.phi,telem.theta,telem.psi);
					//warnx("Attitude quaternion: %.4f %.4f %.4f %.4f", ahrs.q[0],ahrs.q[1],ahrs.q[2],ahrs.q[3]);
					orb_publish(ORB_ID(unibo_telemetry), unibo_telem_pub_fd, &telem);
					//warnx("Publishing telemetry topic.\n");
				}



				if (log_counter>=200){
					//warnx("CINPUTS: %d %d %d %d\n",CInputs_getU0(&cinputs),CInputs_getU1(&cinputs),CInputs_getU2(&cinputs),CInputs_getU3(&cinputs));
					//warnx("PWMOUTPUTS: %d %d %d %d %d %d %d %d\n",mout.outputs[0],mout.outputs[1],mout.outputs[2],mout.outputs[3],mout.outputs[4],mout.outputs[5],mout.outputs[6],mout.outputs[7]);
					log_counter=0;
				}


				/*
				QUI DA IMPLEMENTARE EVENTUALI ALTRI CASE PER I SEGUENTI PACCHETTI (che arriveranno da PX4 via mavlink):

				//  LLSENSORS
				Model_GS_U.LLSenable = 0;
				if (TELE_packet_ready) {
					pkgTel.readPacketTELEMETRY(packet_TELE);
					memset(packet_TELE,0,LENGTH);
					if(pkgTel.isValid()){
						Model_GS_U.LLSenable = 1;
						pkgTel.loadPacketTELEMETRY();
						TELE_packet_ready = false;
					}
				}

				//  OPTICALFLOW
				if (OFLOW_packet_ready) {
					pkgOflow.readPacketOFLOW(packet_OFLOW);
					memset(packet_OFLOW,0,LENGTH);
					if(pkgOflow.isValid()){
						pkgOflow.loadPacketOFLOW();
						OFLOW_packet_ready = false;
					}
				}

				//  ACK
				if (ACK_packet_ready) {
					pkgAck.readPacketACK(packet_ACK);
					memset(packet_ACK,0,LENGTH);
					if(pkgAck.isValid()){
						//TODP: CAlcolo il tempo
						long diff = tAtom-pkgAck.getTstamp();
	//					printf("DIFF: %d %d %d \n", tAtom, pkgAck.getTstamp(), diff);
						if (diff>0){
							if (AckDiffMax<diff){
								AckDiffMax=diff;
							}
							if (AckDiffMin>diff){
								AckDiffMin=diff;
							}
							AckDiff[ackbcount] = diff;
							ackbcount++;
							if (ackbcount==ACKDLEN){
								//Calcolo la media
								unsigned long mean = 0;
								for (int meani= 0; meani<ACKDLEN; meani++){
									mean += AckDiff[meani];
								}
								mean = mean / ACKDLEN;
	//							printf("TEMPO: %ld %ld %ld %ld \n", AckDiffMin, AckDiffMax, mean, loopMaxTime);
								ackbcount = 0;
							}
						}
						ACK_packet_ready = false;
					}
				}

				*/
				print_counter2++;
				if(print_counter2 >= 1)
				{
					usleep(200);
					print_counter2 = 0;
				}

			} //End of file descriptor [SENSOR COMBINED id=1]


			/* there could be more file descriptors here, in the form like:
			 * if (fds[1..n].revents & POLLIN) {}
			 */
		}
	}

	warnx("[unibo_control_daemon] exiting.\n");

	uniboc_thread_running = false;

	return 0;

}
