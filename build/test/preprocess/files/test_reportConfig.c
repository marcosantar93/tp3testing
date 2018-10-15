#include "build/temp/_test_reportConfig.c"
#include "mock_timer.h"
#include "mock_adc.h"
#include "reportConfig.h"
#include "unity.h"


void setUp(void) {



}



void tearDown(void) {



}



void test_reportConfig(void) {

 paramsADCReport_t paramsADCReport={

  .targetADC = 0,

  .sensorType = 0,

  .interval = 600,

  .reportableChange = 1

 };

 uint8_t timerId, timerIdPostInit=0;

 adcInit_CMockExpectAndReturn(22, paramsADCReport.targetADC, 0);

 timerInit_CMockExpectAndReturn(23, paramsADCReport.interval, &timerId, 0);

 timerInit_CMockReturnMemThruPtr_timerId(24, &timerIdPostInit, sizeof(*&timerIdPostInit));

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((configADCReport(paramsADCReport))), (

((void *)0)

), (UNITY_UINT)(25), UNITY_DISPLAY_STYLE_INT);

}



void test_reportStart(void) {

 uint8_t timerId=0;

 timerStart_CMockExpectAndReturn(30, timerId, 0);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((startADCReport(0))), (

((void *)0)

), (UNITY_UINT)(31), UNITY_DISPLAY_STYLE_INT);

}



void test_reportStop(void) {

 uint8_t timerId=0;

 timerStop_CMockExpectAndReturn(36, timerId, 0);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((stopADCReport(0))), (

((void *)0)

), (UNITY_UINT)(37), UNITY_DISPLAY_STYLE_INT);

}
