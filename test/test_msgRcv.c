#include "unity.h"
#include "messageRcv.h"

void setUp(void) {

}

void tearDown(void) {

}

void test_MessageRcv(void) {
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