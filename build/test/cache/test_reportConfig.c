#include "build/temp/_test_reportConfig.c"
#include "reportConfig.h"
#include "unity.h"


void setUp(void) {



}



void tearDown(void) {



}



void test_reportConfig(void) {

 paramsADCReport_t paramsADCReport={

  targetADC = 0,

  sensorType = 0,

  interval = 600,

  reportableChange = 1

 }

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((configADCReport(paramsADCReport))), (

((void *)0)

), (UNITY_UINT)(19), UNITY_DISPLAY_STYLE_INT);

}
