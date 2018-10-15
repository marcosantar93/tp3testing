#include "messageRcv.h"
uint8_t msgProcess(uint8_t * msg){
	uint8_t indexMsgPos;
	while((msg[indexMsgPos] != 0) && (msg[indexMsgPos] != ':'))
		indexMsgPos++;
	if(msg[indexMsgPos] == 0)
		return 1;
	if(msg[2] != ':')
		return 1;
	indexMsgPos++;
	uint8_t code = (msg[0]-'0')*10 + msg[1]-'0';
	switch(code){
		case 0:{
			while(msg[indexMsgPos] != 0){
				while (msg[indexMsgPos] != ',')
					indexMsgPos++;
			}
			
			return 0;
		}
		case 1:{
			return 0;
		}
		case 2:{
			return 0;
		}
		default:{
			return 1;
		}
	}
}

static uint8_t getParamsFromPayload(uint8_t msgPayload) {
	uint8_t paramCount = 0;
	uint8_t charCount;
	while(msg[indexMsgPos] != 0){
		charCount = 0;
		if(msg[indexMsgPos] != ',')
			charCount++;
		else
			
}