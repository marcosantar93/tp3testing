#include "timer.h"
#include "adc.h"








typedef struct {

 uint8_t targetADC;

 uint8_t sensorType;

 uint16_t interval;

 uint8_t reportableChange;

} paramsADCReport_t;



uint8_t configADCReport(paramsADCReport_t paramsADCReport);

uint8_t startADCReport(uint8_t timerId);

uint8_t stopADCReport(uint8_t timerId);
