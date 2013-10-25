/*
 * Copyright (c) 1990-2002 The MathWorks, Inc.
 *
 * File: simstruc_types.h     $Revision: 1.1.6.28 $
 *
 * Abstract:
 *   The embedded RTW code formats do not include simstruc.h, but
 *   needs these common types.
 *   Generated from simstruc_types.tpl.
 */

#ifndef __SIMSTRUC_TYPES_H__
#define __SIMSTRUC_TYPES_H__

#include "tmwtypes.h"
#include "sl_types_def.h"

/* Additional types required for Simulink External Mode */
#ifndef fcn_call_T
# define fcn_call_T real_T
#endif
#ifndef action_T
# define action_T real_T
#endif


/*
 * UNUSED_PARAMETER(x)
 *   Used to specify that a function parameter (argument) is required but not
 *   accessed by the function body.
 */
#ifndef UNUSED_PARAMETER
# if defined(__LCC__)
#   define UNUSED_PARAMETER(x)  /* do nothing */
# else
/*
 * This is the semi-ANSI standard way of indicating that a
 * unused function parameter is required.
 */
#   define UNUSED_PARAMETER(x) (void) (x)
# endif
#endif

#define UNUSED_ARG(arg)  UNUSED_PARAMETER(arg)

typedef enum {
  SS_SIMMODE_NORMAL,            /* Running a "normal" Simulink simulation     */
  SS_SIMMODE_SIZES_CALL_ONLY,   /* Block edit eval to obtain number of ports  */
  SS_SIMMODE_RTWGEN,            /* Generating code                            */
  SS_SIMMODE_EXTERNAL          /* External mode simulation                   */
} SS_SimMode;

typedef enum {
    SS_SIMTYPE_UNKNOWN = -1,
    SS_SIMTYPE_COMMAND_LINE,
    SS_SIMTYPE_MENU
} SS_SimType;

/* Must be used when SS_SimMode is SS_SIMMODE_RTWGEN */
typedef enum {
    SS_RTWGEN_UNKNOWN,
    SS_RTWGEN_RTW_CODE,           /* Code generation for RTW */
    SS_RTWGEN_ACCELERATOR,         /* Code generation for accelerator */
    SS_RTWGEN_MODELREFERENCE_SIM_TARGET, /*Code Generation for Model Reference Sim Target*/
    SS_RTWGEN_MODELREFERENCE_RTW_TARGET /*Code Generation for Model Reference RTW Target*/		
} RTWGenMode;

/*=====================================*
 * Simulation Status                   *
 *=====================================*/

typedef enum {
    SIMSTATUS_STOPPED,
    SIMSTATUS_UPDATING,
    SIMSTATUS_INITIALIZING,
    SIMSTATUS_RUNNING,
    SIMSTATUS_PAUSED,
    SIMSTATUS_TERMINATING,

    /* Must be last */
    SIMSTATUS_EXTERNAL
} SS_SimStatus;


/*
 * This structure is used by model reference to 
 * communicate timing information through the hierarchy.
 */
typedef struct _rtTimingBridge_tag rtTimingBridge;

struct _rtTimingBridge_tag {

    uint32_T     nTasks;

    uint32_T**   clockTick;
    uint32_T**   clockTickH;

    uint32_T*    taskCounter;

    real_T*       taskTime;

    boolean_T**  rateTransition;
    
    boolean_T    *firstInitCond;
};


/* Trigger directions: falling, either, and rising */
typedef enum {
    FALLING_ZERO_CROSSING = -1,
    ANY_ZERO_CROSSING     = 0,
    RISING_ZERO_CROSSING  = 1
} ZCDirection;

/* Previous state of a trigger signal */
typedef uint8_T  ZCSigState;

/* Initial value of a trigger zero crossing signal */
#define    UNINITIALIZED_ZCSIG     0x03U
#define    NEG_ZCSIG               0x02U
#define    POS_ZCSIG               0x01U
#define    ZERO_ZCSIG              0x00U
  
/* Detail zerocrossing event for removing double detection */
#define ZC_EVENT_NUL  0x00
#define ZC_EVENT_N2P  0x01
#define ZC_EVENT_N2Z  0x02
#define ZC_EVENT_Z2P  0x04
#define ZC_EVENT_P2N  0x08
#define ZC_EVENT_P2Z  0x10
#define ZC_EVENT_Z2N  0x20
#define ZC_EVENT_ALL_UP  (ZC_EVENT_N2P | ZC_EVENT_N2Z | ZC_EVENT_Z2P )
#define ZC_EVENT_ALL_DN  (ZC_EVENT_P2N | ZC_EVENT_P2Z | ZC_EVENT_Z2N )
#define ZC_EVENT_ALL     (ZC_EVENT_ALL_UP | ZC_EVENT_ALL_DN )

/* Current state of a trigger signal */
typedef enum {
    FALLING_ZCEVENT = -1,
    NO_ZCEVENT      = 0,
    RISING_ZCEVENT  = 1
} ZCEventType;

#define SS_START_MTH_PORT_ACCESS_UNSET 2
#include "rtw_matlogging.h"
#include "rtw_extmode.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "sysran_types.h"

typedef int_T CSignal_T;

/* DimsInfo_T structure is for S-functions */
#ifndef _DIMSINFO_T
#define _DIMSINFO_T
struct DimsInfo_tag{
    int                        width;        /* number of elements    */
    int                        numDims;      /* number of dimensions  */
    int                        *dims;        /* dimensions            */
    struct DimsInfo_tag        *nextSigDims; /* for composite signals */
};

typedef struct DimsInfo_tag DimsInfo_T;

typedef int_T ssFcnCallErr_T;

/*
 * DECL_AND_INIT_DIMSINFO(variableName):
 *    Macro for setting up a DimsInfo in an S-function to DYNAMIC_DIMENSION.
 *    This macro must be placed at the start of a deceleration, for example:
 *
 *           static void mdlInitializeSizes(SimStruct *S)
 *           {
 *               DECL_AND_INIT_DIMSINFO(diminfo1);
 *
 *               ssSetNumSFcnParams(S, 0);
 *               <snip>
 *           }
 *
 *    The reason that this macro must be placed in the deceleration section of a
 *    function or other scope is that this macro **creates** a local variable of
 *    the specified name with type DimsInfo_T. The variable is initialized
 *    to DYNAMIC_DIMENSION.
 */
#define DECL_AND_INIT_DIMSINFO(variableName) \
   DimsInfo_T variableName = {-1,-1,NULL,NULL}
#endif /* _DIMSINFO_T */


/*
 * Enumeration of work vector used as flag values.
 */
typedef enum {
    SS_DWORK_USED_AS_DWORK  = 0,  /* default */
    SS_DWORK_USED_AS_DSTATE,      /* will be logged, loaded, etc */
    SS_DWORK_USED_AS_SCRATCH,     /* will be reused */
    SS_DWORK_USED_AS_MODE         /* replace mode with dwork */
} ssDWorkUsageType;

#define SS_NUM_DWORK_USAGE_TYPES 3

/*
 * DWork structure for S-Functions, one for each dwork.
 */
struct _ssDWorkRecord {
    int_T            width;
    DTypeId          dataTypeId;
    CSignal_T        complexSignal;
    void             *array;
    const char_T     *name;
    ssDWorkUsageType usedAs;
};

/*
 * INHERITED_SAMPLE_TIME      - Specify for blocks that inherit their sample
 *                              time from the block that feeds their input.
 *
 * CONTINUOUS_SAMPLE_TIME     - A continuous sample time indicates that the
 *                              block executes every simulation step.
 *
 * VARIABLE_SAMPLE_TIME       - Specifies that this sample time is discrete
 *                              with a varying period.
 *
 * FIXED_IN_MINOR_STEP_OFFSET - This can be specified for the offset of either
 *                              the inherited or continuous sample time
 *                              indicating that the output does not change
 *                              in minor steps.
 */

#define INHERITED_SAMPLE_TIME      ((real_T)-1.0)
#define CONTINUOUS_SAMPLE_TIME     ((real_T)0.0)
#define VARIABLE_SAMPLE_TIME       ((real_T)-2.0)
#define FIXED_IN_MINOR_STEP_OFFSET ((real_T)1.0)


/* ========================================================================== */

/*
 * Lightweight structure for holding a real, sparse matrix
 * as used by the analytical Jacobian methods.
 */
typedef struct SparseHeader_Tag {
    int_T   mRows;                  /* number of rows   */
    int_T   nCols;                  /* number of cols   */
    int_T   nzMax;                  /* size of *pr, *ir */
    int_T   *Ir;                    /* row indices      */
    int_T   *Jc;                    /* column offsets   */
#ifndef NO_FLOATS
    real_T  *Pr;                    /* nonzero entries  */
#else
    void    *Pr;
#endif
} SparseHeader;

/*========================*
 * Setup for multitasking *
 *========================*/

/*
 * Let MT be synonym for MULTITASKING (to shorten command line for DOS)
 */
#if defined(MT)
# if MT == 0
#   undef MT
# else
#   define MULTITASKING 1
# endif
#endif

#if defined(MULTITASKING) && MULTITASKING == 0
# undef MULTITASKING
#endif

#if defined(MULTITASKING) && !defined(TID01EQ)
# define TID01EQ 0
#endif

/*
 * Undefine MULTITASKING if there is only one task or there are two
 * tasks and the sample times are equal (case of continuous and one discrete
 * with equal rates).
 */
#if defined(NUMST) && defined(MULTITASKING)
# if NUMST == 1 || (NUMST == 2 && TID01EQ == 1)
#  undef MULTITASKING
# endif
#endif

#endif /* __SIMSTRUC_TYPES_H__ */
