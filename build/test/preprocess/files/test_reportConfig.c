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

 adcInit_CMockExpectAndReturn(21, paramsADCReport.targetADC, 0);

 timerInit_CMockExpectAndReturn(22, paramsADCReport.interval, 0);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((configADCReport(paramsADCReport))), (

((void *)0)

), (UNITY_UINT)(23), UNITY_DISPLAY_STYLE_INT);

}



void test_reportStart(void) {

 timerStart_CMockExpectAndReturn(27, 0, 0);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((startADCReport(0))), (

((void *)0)

), (UNITY_UINT)(28), UNITY_DISPLAY_STYLE_INT);

}



void test_reportStop(void) {

 timerStop_CMockExpectAndReturn(32, 0, 0);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((stopADCReport(0))), (

((void *)0)

), (UNITY_UINT)(33), UNITY_DISPLAY_STYLE_INT);

}
