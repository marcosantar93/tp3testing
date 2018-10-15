#include "build/temp/_test_integration.c"
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

 adcInit_ExpectAndReturn(paramsADCReport.targetADC, 0);

 timerInit_ExpectAndReturn(paramsADCReport.interval, &timerId, 0);

 timerInit_ReturnThruPtr_timerId(&timerIdPostInit);



 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((msgProcess("00:0,0,600,1"))), (

((void *)0)

), (UNITY_UINT)(24), UNITY_DISPLAY_STYLE_INT);

}
