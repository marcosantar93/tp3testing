#include "unity.h"
#include "messageRcv.h"

void setUp(void) {

}

void tearDown(void) {

}

void test_MessageRcv(void) {
	uint8_t * msg = "0:0,PRESSURE,600,1";
	uint8_t retVal = msgProcess(msg);
	TEST_ASSERT_EQUAL(0, retVal);
}