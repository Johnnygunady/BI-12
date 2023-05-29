#ifndef _MY_FNC_H_
#define _MY_FNC_H_

#include "stdint.h"

//Initialization W5500
uint8_t wiz_init(uint8_t* gw, uint8_t* mask, uint8_t* mac, uint8_t* ipadr);

#endif