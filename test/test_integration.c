#include "unity.h"

void setUp(void) {

}

void tearDown(void) {

}

void test_MessageRcvAndReportConfigIntegrationCode0(void) {

	paramsADCReport_t paramsADCReport={
		.targetADC 			= 0,
		.sensorType			= 0,
		.interval			= 600,
		.reportableChange	= 1,
	};
	uint8_t timerId, timerIdPostInit=0;
	adcInit_ExpectAndReturn(paramsADCReport.targetADC, 0);
	timerInit_ExpectAndReturn(paramsADCReport.interval, &timerId, 0);
	timerInit_ReturnThruPtr_timerId(&timerIdPostInit);
	
	TEST_ASSERT_EQUAL(0, msgProcess("00:0,0,600,1"));
}