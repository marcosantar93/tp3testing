#include "unity.h"
#include "reportConfig.h"

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
	TEST_ASSERT_EQUAL(0, configADCReport(paramsADCReport));
}