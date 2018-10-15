#include "unity.h"
#include "messageRcv.h"

void setUp(void) {

}

void tearDown(void) {

}

void test_MessageRcvBasic(void) {
	uint8_t retVal;
	uint8_t * msg00 = "00:0,0,600,1";
	retVal = msgProcess(msg00);
	TEST_ASSERT_EQUAL(0, retVal);
	uint8_t * msg01 = "01:0";
	retVal = msgProcess(msg01);
	TEST_ASSERT_EQUAL(0, retVal);
	uint8_t * msg02 = "02:0";
	retVal = msgProcess(msg02);
	TEST_ASSERT_EQUAL(0, retVal);
	uint8_t * msgErr = "Invalid";
	retVal = msgProcess(msgErr);
	TEST_ASSERT_EQUAL(255, retVal);
}

void test_MessageRcvCode0(void) {
	uint8_t retVal;
	uint8_t * msg00 = "00:X,0,600,1";
	retVal = msgProcess(msg00);
	TEST_ASSERT_EQUAL(2, retVal);
	uint8_t * msg01 = "00:0,X,600,1";
	retVal = msgProcess(msg01);
	TEST_ASSERT_EQUAL(2, retVal);
	uint8_t * msg02 = "00:0,0,X,1";
	retVal = msgProcess(msg02);
	TEST_ASSERT_EQUAL(2, retVal);
	uint8_t * msg03 = "00:0,0,600,X";
	retVal = msgProcess(msg03);
	TEST_ASSERT_EQUAL(2, retVal);
	uint8_t * msg04 = "00:0,0,600";
	retVal = msgProcess(msg04);
	TEST_ASSERT_EQUAL(4, retVal);
	uint8_t * msg05 = "00:0,0,600,1,X";
	retVal = msgProcess(msg05);
	TEST_ASSERT_EQUAL(2, retVal);
	uint8_t * msg06 = "00:,0,600,1";
	retVal = msgProcess(msg06);
	TEST_ASSERT_EQUAL(3, retVal);
	uint8_t * msg07 = "00:0,,600,1";
	retVal = msgProcess(msg07);
	TEST_ASSERT_EQUAL(3, retVal);
	uint8_t * msg08 = "00:0,0,,1";
	retVal = msgProcess(msg08);
	TEST_ASSERT_EQUAL(3, retVal);
	uint8_t * msg09 = "00:0,0,600,";
	retVal = msgProcess(msg09);
	TEST_ASSERT_EQUAL(3, retVal);
}