#include "build/temp/_test_msgRcv.c"
#include "messageRcv.h"
#include "unity.h"


void setUp(void) {



}



void tearDown(void) {



}



void test_MessageRcv(void) {

 uint8_t * msg = "0:0,PRESSURE,600,1";

 uint8_t retVal = msgProcess(msg);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((retVal)), (

((void *)0)

), (UNITY_UINT)(15), UNITY_DISPLAY_STYLE_INT);

}
