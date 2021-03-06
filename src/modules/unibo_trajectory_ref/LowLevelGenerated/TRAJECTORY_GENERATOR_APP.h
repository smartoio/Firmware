/*
 * TRAJECTORY_GENERATOR_APP.h
 *
 * Code generation for model "TRAJECTORY_GENERATOR_APP".
 *
 * Model version              : 1.3955
 * Simulink Coder version : 8.3 (R2012b) 20-Jul-2012
 * C source code generated on : Thu May 08 13:03:55 2014
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */
#ifndef RTW_HEADER_TRAJECTORY_GENERATOR_APP_h_
#define RTW_HEADER_TRAJECTORY_GENERATOR_APP_h_
#ifndef TRAJECTORY_GENERATOR_APP_COMMON_INCLUDES_
# define TRAJECTORY_GENERATOR_APP_COMMON_INCLUDES_
#include <math.h>
#include <string.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#endif                                 /* TRAJECTORY_GENERATOR_APP_COMMON_INCLUDES_ */

#include "TRAJECTORY_GENERATOR_APP_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->ModelData.blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->ModelData.blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->ModelData.constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->ModelData.constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ()
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ()
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->ModelData.defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->ModelData.defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ()
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ()
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ()
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ()
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ()
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ()
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ()
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ()
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ()
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ()
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->ModelData.prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->ModelData.prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ()
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ()
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->Work.dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->Work.dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ()
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ()
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->ModelData.inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->ModelData.inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->ModelData.outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->ModelData.outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->ModelData.zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->ModelData.zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->Work.dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->Work.dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
# define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
# define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define TRAJECTORY_GENERATOR_APP_rtModel RT_MODEL_TRAJECTORY_GENERATOR_A

/* Block signals for system '<S13>/SWITCH LAT MODE' */
typedef struct {
  real_T MODE;                         /* '<S13>/SWITCH LAT MODE' */
} rtB_SWITCHLATMODE_TRAJECTORY_GE;

/* Block signals (auto storage) */
typedef struct {
  real_T Memory1;                      /* '<S9>/Memory1' */
  real_T X_REF;                        /* '<S34>/X_REF' */
  real_T Y_REF;                        /* '<S34>/Y_REF' */
  real_T Z_REF;                        /* '<S34>/Z_REF' */
  real_T Memory;                       /* '<S2>/Memory' */
  real_T Memory5;                      /* '<S14>/Memory5' */
  real_T Switch;                       /* '<S2>/Switch' */
  real_T Memory_e[3];                  /* '<S1>/Memory' */
  real_T DiscreteTransferFcn7;         /* '<S26>/Discrete Transfer Fcn7' */
  real_T DiscreteTransferFcn7_o;       /* '<S27>/Discrete Transfer Fcn7' */
  real_T DiscreteTransferFcn7_a;       /* '<S29>/Discrete Transfer Fcn7' */
  real_T Derivative[3];                /* '<S25>/Derivative' */
  real_T Derivative1[3];               /* '<S25>/Derivative1' */
  real_T DiscreteTransferFcn7_e;       /* '<S28>/Discrete Transfer Fcn7' */
  real_T Memory5_d;                    /* '<S13>/Memory5' */
  real_T Memory5_f;                    /* '<S15>/Memory5' */
  real_T DiscreteTransferFcn;          /* '<S26>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn1;         /* '<S26>/Discrete Transfer Fcn1' */
  real_T DiscreteTransferFcn2;         /* '<S26>/Discrete Transfer Fcn2' */
  real_T DiscreteTransferFcn3;         /* '<S26>/Discrete Transfer Fcn3' */
  real_T DiscreteTransferFcn4;         /* '<S26>/Discrete Transfer Fcn4' */
  real_T DiscreteTransferFcn5;         /* '<S26>/Discrete Transfer Fcn5' */
  real_T DiscreteTransferFcn6;         /* '<S26>/Discrete Transfer Fcn6' */
  real_T DiscreteTransferFcn_m;        /* '<S27>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn1_h;       /* '<S27>/Discrete Transfer Fcn1' */
  real_T DiscreteTransferFcn2_i;       /* '<S27>/Discrete Transfer Fcn2' */
  real_T DiscreteTransferFcn3_e;       /* '<S27>/Discrete Transfer Fcn3' */
  real_T DiscreteTransferFcn4_j;       /* '<S27>/Discrete Transfer Fcn4' */
  real_T DiscreteTransferFcn5_e;       /* '<S27>/Discrete Transfer Fcn5' */
  real_T DiscreteTransferFcn6_j;       /* '<S27>/Discrete Transfer Fcn6' */
  real_T DiscreteTransferFcn_b;        /* '<S28>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn1_f;       /* '<S28>/Discrete Transfer Fcn1' */
  real_T DiscreteTransferFcn2_c;       /* '<S28>/Discrete Transfer Fcn2' */
  real_T DiscreteTransferFcn3_a;       /* '<S28>/Discrete Transfer Fcn3' */
  real_T DiscreteTransferFcn4_b;       /* '<S28>/Discrete Transfer Fcn4' */
  real_T DiscreteTransferFcn5_i;       /* '<S28>/Discrete Transfer Fcn5' */
  real_T DiscreteTransferFcn6_n;       /* '<S28>/Discrete Transfer Fcn6' */
  real_T DiscreteTransferFcn_d;        /* '<S29>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn1_g;       /* '<S29>/Discrete Transfer Fcn1' */
  real_T DiscreteTransferFcn2_b;       /* '<S29>/Discrete Transfer Fcn2' */
  real_T DiscreteTransferFcn3_f;       /* '<S29>/Discrete Transfer Fcn3' */
  real_T DiscreteTransferFcn4_o;       /* '<S29>/Discrete Transfer Fcn4' */
  real_T DiscreteTransferFcn5_j;       /* '<S29>/Discrete Transfer Fcn5' */
  real_T DiscreteTransferFcn6_g;       /* '<S29>/Discrete Transfer Fcn6' */
  real_T p_ref[3];                     /* '<S1>/Trajectory' */
  real_T yaw_pi;                       /* '<S34>/[-pi , pi]' */
  real_T moving;                       /* '<S24>/moving___z' */
  real_T moving_f;                     /* '<S24>/moving___yaw' */
  real_T moving_k;                     /* '<S24>/moving___y' */
  real_T moving_e;                     /* '<S24>/moving___x' */
  real_T dx_i;                         /* '<S5>/BODY to INERTIAL' */
  real_T dy_i;                         /* '<S5>/BODY to INERTIAL' */
  real_T nextState;                    /* '<S9>/STATE_TRANSITIONS' */
  real_T nextResetState;               /* '<S9>/STATE_TRANSITIONS' */
  boolean_T DataTypeConversion1;       /* '<S7>/Data Type Conversion1' */
  boolean_T Compare;                   /* '<S18>/Compare' */
  boolean_T Uk1;                       /* '<S11>/Delay Input1' */
  boolean_T Uk1_n;                     /* '<S10>/Delay Input1' */
  boolean_T Compare_c;                 /* '<S17>/Compare' */
  boolean_T Uk1_d;                     /* '<S12>/Delay Input1' */
  boolean_T Compare_l;                 /* '<S19>/Compare' */
  rtB_SWITCHLATMODE_TRAJECTORY_GE sf_SWITCHLATMODE_i;/* '<S15>/SWITCH LAT MODE' */
  rtB_SWITCHLATMODE_TRAJECTORY_GE sf_SWITCHLATMODE;/* '<S14>/SWITCH LAT MODE' */
  rtB_SWITCHLATMODE_TRAJECTORY_GE sf_SWITCHLATMODE_p;/* '<S13>/SWITCH LAT MODE' */
} BlockIO_TRAJECTORY_GENERATOR_AP;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T X_REF_DSTATE;                 /* '<S34>/X_REF' */
  real_T Y_REF_DSTATE;                 /* '<S34>/Y_REF' */
  real_T Z_REF_DSTATE;                 /* '<S34>/Z_REF' */
  real_T DiscreteTransferFcn7_states;  /* '<S26>/Discrete Transfer Fcn7' */
  real_T DiscreteTransferFcn7_states_a;/* '<S27>/Discrete Transfer Fcn7' */
  real_T DiscreteTransferFcn7_states_f;/* '<S29>/Discrete Transfer Fcn7' */
  real_T PSI_REF_DSTATE;               /* '<S34>/PSI_REF' */
  real_T DiscreteTransferFcn7_states_c;/* '<S28>/Discrete Transfer Fcn7' */
  real_T DiscreteTransferFcn_states;   /* '<S26>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn1_states;  /* '<S26>/Discrete Transfer Fcn1' */
  real_T DiscreteTransferFcn2_states;  /* '<S26>/Discrete Transfer Fcn2' */
  real_T DiscreteTransferFcn3_states;  /* '<S26>/Discrete Transfer Fcn3' */
  real_T DiscreteTransferFcn4_states;  /* '<S26>/Discrete Transfer Fcn4' */
  real_T DiscreteTransferFcn5_states;  /* '<S26>/Discrete Transfer Fcn5' */
  real_T DiscreteTransferFcn6_states;  /* '<S26>/Discrete Transfer Fcn6' */
  real_T DiscreteTransferFcn_states_c; /* '<S27>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn1_states_o;/* '<S27>/Discrete Transfer Fcn1' */
  real_T DiscreteTransferFcn2_states_l;/* '<S27>/Discrete Transfer Fcn2' */
  real_T DiscreteTransferFcn3_states_f;/* '<S27>/Discrete Transfer Fcn3' */
  real_T DiscreteTransferFcn4_states_c;/* '<S27>/Discrete Transfer Fcn4' */
  real_T DiscreteTransferFcn5_states_i;/* '<S27>/Discrete Transfer Fcn5' */
  real_T DiscreteTransferFcn6_states_j;/* '<S27>/Discrete Transfer Fcn6' */
  real_T DiscreteTransferFcn_states_cv;/* '<S28>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn1_states_b;/* '<S28>/Discrete Transfer Fcn1' */
  real_T DiscreteTransferFcn2_states_b;/* '<S28>/Discrete Transfer Fcn2' */
  real_T DiscreteTransferFcn3_states_j;/* '<S28>/Discrete Transfer Fcn3' */
  real_T DiscreteTransferFcn4_states_n;/* '<S28>/Discrete Transfer Fcn4' */
  real_T DiscreteTransferFcn5_states_k;/* '<S28>/Discrete Transfer Fcn5' */
  real_T DiscreteTransferFcn6_states_g;/* '<S28>/Discrete Transfer Fcn6' */
  real_T DiscreteTransferFcn_states_cb;/* '<S29>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn1_states_k;/* '<S29>/Discrete Transfer Fcn1' */
  real_T DiscreteTransferFcn2_states_a;/* '<S29>/Discrete Transfer Fcn2' */
  real_T DiscreteTransferFcn3_states_a;/* '<S29>/Discrete Transfer Fcn3' */
  real_T DiscreteTransferFcn4_states_j;/* '<S29>/Discrete Transfer Fcn4' */
  real_T DiscreteTransferFcn5_states_iv;/* '<S29>/Discrete Transfer Fcn5' */
  real_T DiscreteTransferFcn6_states_a;/* '<S29>/Discrete Transfer Fcn6' */
  real_T Memory1_PreviousInput;        /* '<S9>/Memory1' */
  real_T Memory3_PreviousInput;        /* '<S9>/Memory3' */
  real_T Memory_PreviousInput;         /* '<S2>/Memory' */
  real_T Memory5_PreviousInput;        /* '<S14>/Memory5' */
  real_T Memory_PreviousInput_o[3];    /* '<S1>/Memory' */
  real_T Memory5_PreviousInput_i;      /* '<S13>/Memory5' */
  real_T Memory5_PreviousInput_n;      /* '<S15>/Memory5' */
  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA[3];
    real_T TimeStampB;
    real_T LastUAtTimeB[3];
  } Derivative_RWORK;                  /* '<S25>/Derivative' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA[3];
    real_T TimeStampB;
    real_T LastUAtTimeB[3];
  } Derivative1_RWORK;                 /* '<S25>/Derivative1' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA[3];
    real_T TimeStampB;
    real_T LastUAtTimeB[3];
  } Derivative2_RWORK;                 /* '<S25>/Derivative2' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative3_RWORK;                 /* '<S25>/Derivative3' */

  boolean_T DelayInput1_DSTATE;        /* '<S11>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_m;      /* '<S10>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_p;      /* '<S12>/Delay Input1' */
  int8_T X_REF_PrevResetState;         /* '<S34>/X_REF' */
  int8_T Y_REF_PrevResetState;         /* '<S34>/Y_REF' */
  int8_T Z_REF_PrevResetState;         /* '<S34>/Z_REF' */
  int8_T PSI_REF_PrevResetState;       /* '<S34>/PSI_REF' */
  uint8_T X_REF_IC_LOADING;            /* '<S34>/X_REF' */
  uint8_T Y_REF_IC_LOADING;            /* '<S34>/Y_REF' */
  uint8_T Z_REF_IC_LOADING;            /* '<S34>/Z_REF' */
  uint8_T PSI_REF_IC_LOADING;          /* '<S34>/PSI_REF' */
} D_Work_TRAJECTORY_GENERATOR_APP;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  int16_T JOYSTICK[5];                 /* '<Root>/JOYSTICK' */
  real_T PSI;                          /* '<Root>/PSI' */
  boolean_T BODY_INERT;                /* '<Root>/BODY_INERT' */
  real_T Position[3];                  /* '<Root>/Position' */
  uint32_T TSTAMP;                     /* '<Root>/TSTAMP' */
} ExternalInputs_TRAJECTORY_GENER;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T REF_POS[15];                  /* '<Root>/REF_POS' */
  real_T REF_YAW[3];                   /* '<Root>/REF_YAW' */
  uint16_T REF_BUTTONS;                /* '<Root>/REF_BUTTONS' */
  uint32_T REF_TSTAMP;                 /* '<Root>/REF_TSTAMP' */
} ExternalOutputs_TRAJECTORY_GENE;

/* Backward compatible GRT Identifiers */
#define rtB                            TRAJECTORY_GENERATOR_APP_B
#define BlockIO                        BlockIO_TRAJECTORY_GENERATOR_AP
#define rtU                            TRAJECTORY_GENERATOR_APP_U
#define ExternalInputs                 ExternalInputs_TRAJECTORY_GENER
#define rtY                            TRAJECTORY_GENERATOR_APP_Y
#define ExternalOutputs                ExternalOutputs_TRAJECTORY_GENE
#define rtDWork                        TRAJECTORY_GENERATOR_APP_DWork
#define D_Work                         D_Work_TRAJECTORY_GENERATOR_APP

/* Real-time Model Data Structure */
struct tag_RTM_TRAJECTORY_GENERATOR_AP {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    void *blockIO;
    const void *constBlockIO;
    void *defaultParam;
    ZCSigState *prevZCSigState;
    real_T *contStates;
    real_T *derivs;
    void *zcSignalValues;
    void *inputs;
    void *outputs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;

  /*
   * Work:
   * The following substructure contains information regarding
   * the work vectors in the model.
   */
  struct {
    void *dwork;
  } Work;
};

/* Block signals (auto storage) */
extern BlockIO_TRAJECTORY_GENERATOR_AP TRAJECTORY_GENERATOR_APP_B;

/* Block states (auto storage) */
extern D_Work_TRAJECTORY_GENERATOR_APP TRAJECTORY_GENERATOR_APP_DWork;

/* External inputs (root inport signals with auto storage) */
extern ExternalInputs_TRAJECTORY_GENER TRAJECTORY_GENERATOR_APP_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExternalOutputs_TRAJECTORY_GENE TRAJECTORY_GENERATOR_APP_Y;

/* Real-time Model object */
extern RT_MODEL_TRAJECTORY_GENERATOR_A *const TRAJECTORY_GENERATOR_APP_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'TRAJECTORY_GENERATOR_APP'
 * '<S1>'   : 'TRAJECTORY_GENERATOR_APP/REFERENCES'
 * '<S2>'   : 'TRAJECTORY_GENERATOR_APP/REFERENCES/Clock RESET'
 * '<S3>'   : 'TRAJECTORY_GENERATOR_APP/REFERENCES/LOW LEVEL SUPERVISOR'
 * '<S4>'   : 'TRAJECTORY_GENERATOR_APP/REFERENCES/REFERENCES_TIME'
 * '<S5>'   : 'TRAJECTORY_GENERATOR_APP/REFERENCES/REF_GEN'
 * '<S6>'   : 'TRAJECTORY_GENERATOR_APP/REFERENCES/Trajectory'
 * '<S7>'   : 'TRAJECTORY_GENERATOR_APP/REFERENCES/LOW LEVEL SUPERVISOR/LOW_LEVEL_SUPERVISOR'
 * '<S8>'   : 'TRAJECTORY_GENERATOR_APP/REFERENCES/LOW LEVEL SUPERVISOR/LOW_LEVEL_SUPERVISOR/Embedded MATLAB Function'
 * '<S9>'   : 'TRAJECTORY_GENERATOR_APP/REFERENCES/LOW LEVEL SUPERVISOR/LOW_LEVEL_SUPERVISOR/STATE_MACHINE'
 * '<S10>'  : 'TRAJECTORY_GENERATOR_APP/REFERENCES/LOW LEVEL SUPERVISOR/LOW_LEVEL_SUPERVISOR/STATE_MACHINE/Detect Rise'
 * '<S11>'  : 'TRAJECTORY_GENERATOR_APP/REFERENCES/LOW LEVEL SUPERVISOR/LOW_LEVEL_SUPERVISOR/STATE_MACHINE/Detect Rise1'
 * '<S12>'  : 'TRAJECTORY_GENERATOR_APP/REFERENCES/LOW LEVEL SUPERVISOR/LOW_LEVEL_SUPERVISOR/STATE_MACHINE/Detect Rise2'
 * '<S13>'  : 'TRAJECTORY_GENERATOR_APP/REFERENCES/LOW LEVEL SUPERVISOR/LOW_LEVEL_SUPERVISOR/STATE_MACHINE/HOLD'
 * '<S14>'  : 'TRAJECTORY_GENERATOR_APP/REFERENCES/LOW LEVEL SUPERVISOR/LOW_LEVEL_SUPERVISOR/STATE_MACHINE/HOLD1'
 * '<S15>'  : 'TRAJECTORY_GENERATOR_APP/REFERENCES/LOW LEVEL SUPERVISOR/LOW_LEVEL_SUPERVISOR/STATE_MACHINE/HOLD2'
 * '<S16>'  : 'TRAJECTORY_GENERATOR_APP/REFERENCES/LOW LEVEL SUPERVISOR/LOW_LEVEL_SUPERVISOR/STATE_MACHINE/STATE_TRANSITIONS'
 * '<S17>'  : 'TRAJECTORY_GENERATOR_APP/REFERENCES/LOW LEVEL SUPERVISOR/LOW_LEVEL_SUPERVISOR/STATE_MACHINE/Detect Rise/Positive'
 * '<S18>'  : 'TRAJECTORY_GENERATOR_APP/REFERENCES/LOW LEVEL SUPERVISOR/LOW_LEVEL_SUPERVISOR/STATE_MACHINE/Detect Rise1/Positive'
 * '<S19>'  : 'TRAJECTORY_GENERATOR_APP/REFERENCES/LOW LEVEL SUPERVISOR/LOW_LEVEL_SUPERVISOR/STATE_MACHINE/Detect Rise2/Positive'
 * '<S20>'  : 'TRAJECTORY_GENERATOR_APP/REFERENCES/LOW LEVEL SUPERVISOR/LOW_LEVEL_SUPERVISOR/STATE_MACHINE/HOLD/SWITCH LAT MODE'
 * '<S21>'  : 'TRAJECTORY_GENERATOR_APP/REFERENCES/LOW LEVEL SUPERVISOR/LOW_LEVEL_SUPERVISOR/STATE_MACHINE/HOLD1/SWITCH LAT MODE'
 * '<S22>'  : 'TRAJECTORY_GENERATOR_APP/REFERENCES/LOW LEVEL SUPERVISOR/LOW_LEVEL_SUPERVISOR/STATE_MACHINE/HOLD2/SWITCH LAT MODE'
 * '<S23>'  : 'TRAJECTORY_GENERATOR_APP/REFERENCES/REF_GEN/BODY to INERTIAL'
 * '<S24>'  : 'TRAJECTORY_GENERATOR_APP/REFERENCES/REF_GEN/INPUTS'
 * '<S25>'  : 'TRAJECTORY_GENERATOR_APP/REFERENCES/REF_GEN/REFERENCES'
 * '<S26>'  : 'TRAJECTORY_GENERATOR_APP/REFERENCES/REF_GEN/INPUTS/LPF'
 * '<S27>'  : 'TRAJECTORY_GENERATOR_APP/REFERENCES/REF_GEN/INPUTS/LPF1'
 * '<S28>'  : 'TRAJECTORY_GENERATOR_APP/REFERENCES/REF_GEN/INPUTS/LPF2'
 * '<S29>'  : 'TRAJECTORY_GENERATOR_APP/REFERENCES/REF_GEN/INPUTS/LPF3'
 * '<S30>'  : 'TRAJECTORY_GENERATOR_APP/REFERENCES/REF_GEN/INPUTS/moving___x'
 * '<S31>'  : 'TRAJECTORY_GENERATOR_APP/REFERENCES/REF_GEN/INPUTS/moving___y'
 * '<S32>'  : 'TRAJECTORY_GENERATOR_APP/REFERENCES/REF_GEN/INPUTS/moving___yaw'
 * '<S33>'  : 'TRAJECTORY_GENERATOR_APP/REFERENCES/REF_GEN/INPUTS/moving___z'
 * '<S34>'  : 'TRAJECTORY_GENERATOR_APP/REFERENCES/REF_GEN/REFERENCES/POSITION REF'
 * '<S35>'  : 'TRAJECTORY_GENERATOR_APP/REFERENCES/REF_GEN/REFERENCES/POSITION REF/[-pi , pi]'
 */
#endif                                 /* RTW_HEADER_TRAJECTORY_GENERATOR_APP_h_ */
