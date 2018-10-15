#include "build/temp/_test_msgRcv.c"
#include "messageRcv.h"
#include "unity.h"


void setUp(void) {



}



void tearDown(void) {



}



void test_MessageRcvBasic(void) {

 uint8_t retVal;

 uint8_t * msg00 = "00:0,0,600,1";

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



void test_MessageRcvCode0(void) {

 uint8_t retVal;

 uint8_t * msg00 = "00:X,0,600,1";

 retVal = msgProcess(msg00);

 UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((retVal)), (

((void *)0)

), (UNITY_UINT)(32), UNITY_DISPLAY_STYLE_INT);

 uint8_t * msg01 = "00:0,X,600,1";

 retVal = msgProcess(msg01);

 UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((retVal)), (

((void *)0)

), (UNITY_UINT)(35), UNITY_DISPLAY_STYLE_INT);

 uint8_t * msg02 = "00:0,0,X,1";

 retVal = msgProcess(msg02);

 UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((retVal)), (

((void *)0)

), (UNITY_UINT)(38), UNITY_DISPLAY_STYLE_INT);

 uint8_t * msg03 = "00:0,0,600,X";

 retVal = msgProcess(msg03);

 UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((retVal)), (

((void *)0)

), (UNITY_UINT)(41), UNITY_DISPLAY_STYLE_INT);

 uint8_t * msg04 = "00:0,0,600";

 retVal = msgProcess(msg04);

 UnityAssertEqualNumber((UNITY_INT)((4)), (UNITY_INT)((retVal)), (

((void *)0)

), (UNITY_UINT)(44), UNITY_DISPLAY_STYLE_INT);

 uint8_t * msg05 = "00:0,0,600,1,X";

 retVal = msgProcess(msg05);

 UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((retVal)), (

((void *)0)

), (UNITY_UINT)(47), UNITY_DISPLAY_STYLE_INT);

 uint8_t * msg06 = "00:,0,600,1";

 retVal = msgProcess(msg06);

 UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((retVal)), (

((void *)0)

), (UNITY_UINT)(50), UNITY_DISPLAY_STYLE_INT);

 uint8_t * msg07 = "00:0,,600,1";

 retVal = msgProcess(msg07);

 UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((retVal)), (

((void *)0)

), (UNITY_UINT)(53), UNITY_DISPLAY_STYLE_INT);

 uint8_t * msg08 = "00:0,0,,1";

 retVal = msgProcess(msg08);

 UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((retVal)), (

((void *)0)

), (UNITY_UINT)(56), UNITY_DISPLAY_STYLE_INT);

 uint8_t * msg09 = "00:0,0,600,";

 retVal = msgProcess(msg09);

 UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((retVal)), (

((void *)0)

), (UNITY_UINT)(59), UNITY_DISPLAY_STYLE_INT);

}
