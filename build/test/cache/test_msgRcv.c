#include "build/temp/_test_msgRcv.c"
#include "messageRcv.h"
#include "unity.h"


void setUp(void) {



}



void tearDown(void) {



}



void test_MessageRcv(void) {

 uint8_t retVal;

 uint8_t * msg00 = "00:0,PRESSURE,600,1";

 retVal = msgProcess(msg00);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((retVal)), (

((void *)0)

), (UNITY_UINT)(16), UNITY_DISPLAY_STYLE_INT);

 uint8_t * msg01 = "01:0";

 retVal = msgProcess(msg01);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((retVal)), (

((void *)0)

), (UNITY_UINT)(19), UNITY_DISPLAY_STYLE_INT);

 uint8_t * msg02 = "02:0";

 retVal = msgProcess(msg02);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((retVal)), (

((void *)0)

), (UNITY_UINT)(22), UNITY_DISPLAY_STYLE_INT);

 uint8_t * msgErr = "Invalid";

 retVal = msgProcess(msgErr);

 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((retVal)), (

((void *)0)

), (UNITY_UINT)(25), UNITY_DISPLAY_STYLE_INT);

}
