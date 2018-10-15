#include "messageRcv.h"
uint8_t msgProcess(uint8_t * msg){
	if(msg[0] == '0')
		return 0;
	else
		return 1;
}