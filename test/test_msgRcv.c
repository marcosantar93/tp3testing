#include "unity.h"
#include "messageRcv.h"

void setUp(void) {

}

void tearDown(void) {

}

void test_MessageRcvBasic(void) {

	TEST_ASSERT_EQUAL(0, msgProcess("00:0,0,600,1"));
	TEST_ASSERT_EQUAL(0, msgProcess("01:0"));
	TEST_ASSERT_EQUAL(0, msgProcess("02:0"));
	TEST_ASSERT_EQUAL(255, msgProcess("Invalid"));
}

void test_MessageRcvCode0(void) {
	TEST_ASSERT_EQUAL(2, msgProcess("00:X,0,600,1"));
	TEST_ASSERT_EQUAL(2, msgProcess("00:0,X,600,1"));
	TEST_ASSERT_EQUAL(2, msgProcess("00:0,0,X,1"));
	TEST_ASSERT_EQUAL(2, msgProcess("00:0,0,600,X"));
	TEST_ASSERT_EQUAL(4, msgProcess("00:0,0,600"));
	TEST_ASSERT_EQUAL(2, msgProcess("00:0,0,600,1,X"));
	TEST_ASSERT_EQUAL(3, msgProcess("00:,0,600,1"));
	TEST_ASSERT_EQUAL(3, msgProcess("00:0,,600,1"));
	TEST_ASSERT_EQUAL(3, msgProcess("00:0,0,,1"));
	TEST_ASSERT_EQUAL(3, msgProcess("00:0,0,600,"));
}

void test_MessageRcvCode1(void) {
	TEST_ASSERT_EQUAL(0, msgProcess("01:1"));
	TEST_ASSERT_EQUAL(0, msgProcess("01:2"));
	TEST_ASSERT_EQUAL(2, msgProcess("01:X"));
	TEST_ASSERT_EQUAL(4, msgProcess("01:1,2"));
	TEST_ASSERT_EQUAL(3, msgProcess("01:,"));
	TEST_ASSERT_EQUAL(3, msgProcess("01:"));

}

void test_MessageRcvCode2(void) {
	TEST_ASSERT_EQUAL(0, msgProcess("02:1"));
	TEST_ASSERT_EQUAL(0, msgProcess("02:2"));
	TEST_ASSERT_EQUAL(2, msgProcess("02:X"));
	TEST_ASSERT_EQUAL(4, msgProcess("02:1,2"));
	TEST_ASSERT_EQUAL(3, msgProcess("02:,"));
	TEST_ASSERT_EQUAL(3, msgProcess("02:"));
}

void test_Ranges(void){
	TEST_ASSERT_EQUAL(253, msgProcess("99:0,0,600,1"));
	TEST_ASSERT_EQUAL(253, msgProcess("99:0"));
	TEST_ASSERT_EQUAL(5, msgProcess("01:5"));
	TEST_ASSERT_EQUAL(6, msgProcess("00:0,4,600,1"));
	TEST_ASSERT_EQUAL(7, msgProcess("00:0,0,0,1"));
	TEST_ASSERT_EQUAL(8, msgProcess("00:0,0,66000,1"));
	TEST_ASSERT_EQUAL(8, msgProcess("00:0,0,40000,1"));
}

