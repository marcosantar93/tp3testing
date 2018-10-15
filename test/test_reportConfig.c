#include "unity.h"
#include "reportConfig.h"
#include "Mockadc.h"

void setUp(void) {

}

void tearDown(void) {

}

void test_reportConfig(void) {
	paramsADCReport_t paramsADCReport={
		.targetADC 			= 0,
		.sensorType			= 0,
		.interval			= 600,
		.reportableChange	= 1
	};
	adcInit_ExpectAndReturn(paramsADCReport.targetADC, 0);
	timerInit_ExpectAndReturn(paramsADCReport.interval, 0);
	TEST_ASSERT_EQUAL(0, configADCReport(paramsADCReport));
}

void test_reportStart(void) {
	timerStart_ExpectAndReturn(0, 0)
	TEST_ASSERT_EQUAL(0, startADCReport(0));
}

void test_reportStop(void) {
	timerStop_ExpectAndReturn(0, 0)
	TEST_ASSERT_EQUAL(0, stopADCReport(0));
}