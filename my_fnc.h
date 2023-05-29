#ifndef _MY_FNC_H_
#define _MY_FNC_H_

#include "SPI_Defs.h"

#include <stdint.h>
#include <stdbool.h>

//Account delay
void delay(uint16_t);

//Start timer#0
void timer_start(void);

//Delat 1ms
void timectl(void);

//Write to DDS chip freq
void freq_gen(uint16_t* ,
							uint8_t, 
							struct BlockStat* StatData);

//Write to fine division DAC
void DACD(uint16_t, struct BlockStat* StatData);

//Write to OS DAC
void DACOS(uint16_t, struct BlockStat* StatData);

//Write to coarse division MUX 
void dev_mux(uint8_t i, struct BlockStat* StatData);

//Choice output signal
void out_mux(uint8_t i, struct BlockStat* StatData);



#endif


