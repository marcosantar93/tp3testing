#include "reportConfig.h"

uint8_t configADCReport(paramsADCReport_t paramsADCReport){
	uint8_t retVal = adcInit(paramsADCReport.targetADC);
	if(retVal!=0)
		return retVal;
	uint8_t timerId;
	retVal = timerInit(paramsADCReport.interval, &timerId);
	return retVal;
}
uint8_t startADCReport(uint8_t timerId){
	return timerStart(timerId);
}
uint8_t stopADCReport(uint8_t timerId){
	return timerStop(timerId);
}