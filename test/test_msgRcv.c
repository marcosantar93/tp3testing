#include "unity.h"
#include "messageRcv.h"

void setUp(void) {

}

void tearDown(void) {

}

void test_MessageRcvBasic(void) {
	uint8_t retVal;
	uint8_t * msg00 = "00:0,PRESSURE,600,1";
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
	TEST_ASSERT_EQUAL(1, retVal);
}

void test_MessageRcvCode0(void) {
	uint8_t retVal;
	uint8_t * msg00 = "00:X,PRESSURE,600,1";
	retVal = msgProcess(msg00);
	TEST_ASSERT_EQUAL(1, retVal);
	uint8_t * msg01 = "00:0,X,600,1";
	retVal = msgProcess(msg01);
	TEST_ASSERT_EQUAL(1, retVal);
	uint8_t * msg02 = "00:0,PRESSURE,X,1";
	retVal = msgProcess(msg02);
	TEST_ASSERT_EQUAL(1, retVal);
	uint8_t * msg03 = "00:0,PRESSURE,600,X";
	retVal = msgProcess(msg03);
	TEST_ASSERT_EQUAL(1, retVal);
	uint8_t * msg04 = "00:0,NOTADEVICE,600";
	retVal = msgProcess(msg04);
	TEST_ASSERT_EQUAL(1, retVal);
	uint8_t * msg05 = "00:0,PRESSURE,600,1,X";
	retVal = msgProcess(msg05);
	TEST_ASSERT_EQUAL(1, retVal);
}