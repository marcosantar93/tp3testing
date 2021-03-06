#ifndef MESSAGE_RCV_H_
#define MESSAGE_RCV_H_

#include <stdint.h>
#include "reportConfig.h"

#define CODE_FROM_PAYLOAD_DIVIDER ':'
#define PARAMS_DIVIDER ','

#define ERR_OK 0
#define NOT_A_NUMBER 2
#define EMPTY_PARAM 3
#define WRONG_PARAM_COUNT 4
#define ADC_OUT_OF_RANGE 5
#define SENSOR_TYPE_OUT_OF_RANGE 6
#define TIME_INTERVAL_TOO_SHORT 7
#define TIME_INTERVAL_TOO_LONG 8

#define UNKNOWN_CODE 253
#define CODE_FROM_PAYLOAD_DIVIDER_NOT_FOUND_AT_POSITION 254
#define CODE_FROM_PAYLOAD_DIVIDER_NOT_FOUND 255

#define MIN_TIME 60 
#define MAX_TIME 36000

typedef enum {
	REPORT_CONFIG = 0x00,
	REPORT_START,
	REPORT_STOP
} code_t;

uint8_t msgProcess(uint8_t * msg);


#endif /* MESSAGE_RCV_H_ */