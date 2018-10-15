#include "build/temp/_test_integration.c"
#include "mock_timer.h"
#include "mock_adc.h"
#include "reportConfig.h"
#include "messageRcv.h"
#include "unity.h"


void setUp(void) {



}



void tearDown(void) {



}



void test_MessageRcvAndReportConfigIntegrationCode0(void) {



 paramsADCReport_t paramsADCReport={

  .targetADC = 0,

  .sensorType = 0,

  .interval = 600,

  .reportableChange = 1,

 };

 uint8_t timerId, timerIdPostInit=0;

 adcInit_CMockExpectAndReturn(24, paramsADCReport.targetADC, 0);

 timerInit_CMockExpectAndReturn(25, paramsADCReport.interval, &timerId, 0);

 timerInit_CMockReturnMemThruPtr_timerId(26, &timerIdPostInit, sizeof(*&timerIdPostInit));



 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((msgProcess("00:0,0,600,1"))), (

((void *)0)

), (UNITY_UINT)(28), UNITY_DISPLAY_STYLE_INT);

}



void test_MessageRcvAndReportConfigIntegrationCode1(void) {



 uint8_t timerId=0;

 timerStart_CMockExpectAndReturn(34, timerId, 0);



 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((msgProcess("01:0"))), (

((void *)0)

), (UNITY_UINT)(36), UNITY_DISPLAY_STYLE_INT);

}



void test_MessageRcvAndReportConfigIntegrationCode2(void) {



 uint8_t timerId=0;

 timerStop_CMockExpectAndReturn(42, timerId, 0);



 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((msgProcess("02:0"))), (

((void *)0)

), (UNITY_UINT)(44), UNITY_DISPLAY_STYLE_INT);

}
