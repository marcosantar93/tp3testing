#include "messageRcv.h"

static uint8_t getParamsFromPayload(uint8_t * msgPayload, const uint8_t paramCount, uint16_t * params);

const uint8_t NUM_OF_PARAMS_PER_CODE[] = {4,1,1};
const uint8_t CODES_NUMBER = sizeof(NUM_OF_PARAMS_PER_CODE) / sizeof(NUM_OF_PARAMS_PER_CODE[0]);

uint8_t msgProcess(uint8_t * msg){
	uint8_t indexMsgPos=0;
	while((msg[indexMsgPos] != 0) && (msg[indexMsgPos] != ':'))
		indexMsgPos++;
	if(msg[indexMsgPos] == 0)
		return 255;
	if(msg[2] != ':')
		return 254;
	indexMsgPos++;
	uint8_t code = (msg[0]-'0')*10 + msg[1]-'0';
	uint8_t paramCount = NUM_OF_PARAMS_PER_CODE[code];
	uint16_t params[paramCount];
	if((code>=0)&&(code<=CODES_NUMBER)){
		uint8_t retVal = getParamsFromPayload(msg+indexMsgPos,paramCount,params);
		if(retVal!=0){
			return retVal;
		}
	}
	if(params[0]>3)
		return 5; //ADC out of range
	switch(code){
		case 0:{		
			if(params[1]>2)
				return 6; //Sensor type out of range
			if(params[2]<60)
				return 7; //Time interval too short
			if(params[2]>36000)
				return 8; //Time interval too long
			return 0;

		}
		case 1:{

			return 0;
		}
		case 2:{

			return 0;
		}
		default:{
			return 253;
		}
	}
}
//"99:0,0,600,1"
static uint8_t getParamsFromPayload(uint8_t * msgPayload, const uint8_t paramCount, uint16_t * params) {
	uint8_t paramCountLocal = 0;
	uint8_t index = 0;
	uint8_t charCount = 0;
	uint32_t aux = 0;
	do{
		if((msgPayload[index] != ',') && (msgPayload[index] != 0) ){
			charCount++;
			if((msgPayload[index] > '9')||(msgPayload[index] < '0'))
				return 2; //not a number
			else{
				aux *= 10;
				aux += msgPayload[index]-'0';
			}
		}
		else {
			if(0 == charCount) //empty param
				return 3;
			else {
				charCount = 0;
				if(aux > 65535)
					aux = 65535;
				params[paramCountLocal]=(uint16_t)aux;
				aux = 0;
				paramCountLocal++;
			}
		}
	} while(msgPayload[index++] != 0);
	
	if(paramCount==paramCountLocal)
		return 0;
	else
		return 4;
}