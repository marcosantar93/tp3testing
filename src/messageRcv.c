#include "messageRcv.h"

static uint8_t getParamsFromPayload(uint8_t * msgPayload, const uint8_t paramCount, uint16_t * params);

const uint8_t NUM_OF_PARAMS_PER_CODE[] = {4,1,1};
const uint8_t CODES_NUMBER = sizeof(NUM_OF_PARAMS_PER_CODE) / sizeof(NUM_OF_PARAMS_PER_CODE[0]);

uint8_t msgProcess(uint8_t * msg){
	uint8_t indexMsgPos=0;
	
	while((msg[indexMsgPos] != 0) && (msg[indexMsgPos] != CODE_FROM_PAYLOAD_DIVIDER))
		indexMsgPos++;
	
	if(msg[indexMsgPos] == 0)
		return CODE_FROM_PAYLOAD_DIVIDER_NOT_FOUND;
	if(msg[2] != CODE_FROM_PAYLOAD_DIVIDER)
		return CODE_FROM_PAYLOAD_DIVIDER_NOT_FOUND_AT_POSITION;
	
	indexMsgPos++;
	
	code_t code = (msg[0]-'0')*10 + msg[1]-'0';
	uint8_t paramCount = NUM_OF_PARAMS_PER_CODE[code];
	uint16_t params[paramCount];
	
	if((code>=0)&&(code<=CODES_NUMBER)){
		uint8_t retVal = getParamsFromPayload(msg+indexMsgPos,paramCount,params);
		if(retVal!=0){
			return retVal;
		}
	}
	
	if(params[0]>3)
		return ADC_OUT_OF_RANGE; 
	
	switch(code){
		case REPORT_CONFIG:{		
			if(params[1] > 2)
				return SENSOR_TYPE_OUT_OF_RANGE;
			if(params[2] < MIN_TIME)
				return TIME_INTERVAL_TOO_SHORT; 
			if(params[2] > MAX_TIME)
				return TIME_INTERVAL_TOO_LONG; 
			paramsADCReport_t paramsADCReport={
				.targetADC 			= 0,
				.sensorType			= 0,
				.interval			= 600,
				.reportableChange	= 1,
			};
			return configADCReport(paramsADCReport);

		}
		case REPORT_START:{
			return startADCReport(params[0]);
		}
		case REPORT_STOP:{
			return stopADCReport(params[0]);
		}
		default:{
			return UNKNOWN_CODE;
		}
	}
}

static uint8_t getParamsFromPayload(uint8_t * msgPayload, const uint8_t paramCount, uint16_t * params) {
	uint8_t paramCountLocal = 0;
	uint8_t index = 0;
	uint8_t charCount = 0;
	uint32_t aux = 0;
	do{
		if((msgPayload[index] != PARAMS_DIVIDER) && (msgPayload[index] != 0) ){
			charCount++;
			if((msgPayload[index] > '9')||(msgPayload[index] < '0'))
				return NOT_A_NUMBER; 
			else{
				aux *= 10;
				aux += msgPayload[index]-'0';
			}
		}
		else {
			if(0 == charCount) 
				return EMPTY_PARAM;
			else {
				charCount = 0;
				if(aux > UINT16_MAX)
					aux = UINT16_MAX;
				params[paramCountLocal]=(uint16_t)aux;
				aux = 0;
				paramCountLocal++;
			}
		}
	} while(msgPayload[index++] != 0);
	
	if(paramCount==paramCountLocal)
		return ERR_OK;
	else
		return WRONG_PARAM_COUNT;
}