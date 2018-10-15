#include "build/temp/_test_msgRcv.c"
#include "mock_reportConfig.h"
#include "messageRcv.h"
#include "unity.h"


void setUp(void) {



}



void tearDown(void) {



}



void test_MessageRcvBasic(void) {

 paramsADCReport_t paramsADCReport={

  .targetADC = 0,

  .sensorType = 0,

  .interval = 600,

  .reportableChange = 1,

 };

 configADCReport_CMockExpectAndReturn(20, paramsADCReport, 0);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((msgProcess("00:0,0,600,1"))), (

((void *)0)

), (UNITY_UINT)(21), UNITY_DISPLAY_STYLE_INT);

 startADCReport_CMockExpectAndReturn(22, paramsADCReport.targetADC, 0);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((msgProcess("01:0"))), (

((void *)0)

), (UNITY_UINT)(23), UNITY_DISPLAY_STYLE_INT);

 stopADCReport_CMockExpectAndReturn(24, paramsADCReport.targetADC, 0);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((msgProcess("02:0"))), (

((void *)0)

), (UNITY_UINT)(25), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((255)), (UNITY_INT)((msgProcess("Invalid"))), (

((void *)0)

), (UNITY_UINT)(26), UNITY_DISPLAY_STYLE_INT);

}



void test_MessageRcvCode0(void) {

 UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((msgProcess("00:X,0,600,1"))), (

((void *)0)

), (UNITY_UINT)(30), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((msgProcess("00:0,X,600,1"))), (

((void *)0)

), (UNITY_UINT)(31), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((msgProcess("00:0,0,X,1"))), (

((void *)0)

), (UNITY_UINT)(32), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((msgProcess("00:0,0,600,X"))), (

((void *)0)

), (UNITY_UINT)(33), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((4)), (UNITY_INT)((msgProcess("00:0,0,600"))), (

((void *)0)

), (UNITY_UINT)(34), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((msgProcess("00:0,0,600,1,X"))), (

((void *)0)

), (UNITY_UINT)(35), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((msgProcess("00:,0,600,1"))), (

((void *)0)

), (UNITY_UINT)(36), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((msgProcess("00:0,,600,1"))), (

((void *)0)

), (UNITY_UINT)(37), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((msgProcess("00:0,0,,1"))), (

((void *)0)

), (UNITY_UINT)(38), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((msgProcess("00:0,0,600,"))), (

((void *)0)

), (UNITY_UINT)(39), UNITY_DISPLAY_STYLE_INT);

}



void test_MessageRcvCode1(void) {

 startADCReport_CMockExpectAndReturn(43, 1, 0);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((msgProcess("01:1"))), (

((void *)0)

), (UNITY_UINT)(44), UNITY_DISPLAY_STYLE_INT);

 startADCReport_CMockExpectAndReturn(45, 2, 0);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((msgProcess("01:2"))), (

((void *)0)

), (UNITY_UINT)(46), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((msgProcess("01:X"))), (

((void *)0)

), (UNITY_UINT)(47), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((4)), (UNITY_INT)((msgProcess("01:1,2"))), (

((void *)0)

), (UNITY_UINT)(48), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((msgProcess("01:,"))), (

((void *)0)

), (UNITY_UINT)(49), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((msgProcess("01:"))), (

((void *)0)

), (UNITY_UINT)(50), UNITY_DISPLAY_STYLE_INT);



}



void test_MessageRcvCode2(void) {

 stopADCReport_CMockExpectAndReturn(55, 1, 0);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((msgProcess("02:1"))), (

((void *)0)

), (UNITY_UINT)(56), UNITY_DISPLAY_STYLE_INT);

 stopADCReport_CMockExpectAndReturn(57, 2, 0);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((msgProcess("02:2"))), (

((void *)0)

), (UNITY_UINT)(58), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((msgProcess("02:X"))), (

((void *)0)

), (UNITY_UINT)(59), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((4)), (UNITY_INT)((msgProcess("02:1,2"))), (

((void *)0)

), (UNITY_UINT)(60), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((msgProcess("02:,"))), (

((void *)0)

), (UNITY_UINT)(61), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((msgProcess("02:"))), (

((void *)0)

), (UNITY_UINT)(62), UNITY_DISPLAY_STYLE_INT);

}



void test_Ranges(void){

 UnityAssertEqualNumber((UNITY_INT)((253)), (UNITY_INT)((msgProcess("99:0,0,600,1"))), (

((void *)0)

), (UNITY_UINT)(66), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((253)), (UNITY_INT)((msgProcess("99:0"))), (

((void *)0)

), (UNITY_UINT)(67), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((msgProcess("01:5"))), (

((void *)0)

), (UNITY_UINT)(68), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((6)), (UNITY_INT)((msgProcess("00:0,4,600,1"))), (

((void *)0)

), (UNITY_UINT)(69), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((7)), (UNITY_INT)((msgProcess("00:0,0,0,1"))), (

((void *)0)

), (UNITY_UINT)(70), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((8)), (UNITY_INT)((msgProcess("00:0,0,66000,1"))), (

((void *)0)

), (UNITY_UINT)(71), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((8)), (UNITY_INT)((msgProcess("00:0,0,40000,1"))), (

((void *)0)

), (UNITY_UINT)(72), UNITY_DISPLAY_STYLE_INT);

}
