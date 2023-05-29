
#include "my_fnc.h"
#include "SPI_Defs.h"



extern const uint8_t xdata gw[4];
extern const uint8_t xdata mask[4]; 
extern const uint8_t xdata mac[6] ;
extern const uint8_t xdata ipadr[4]; 	
extern uint8_t  tmp1[6];



void timer_start()			/* Timer0 delay function */
{
	TH0 = 0xE1;			/* Load 8-bit in TH0 (here Timer0 used) */
	TL0 = 0x05;			/* Load 5-bit in TL0 */
	TR0 = 1;			/* Start timer0 */
	//while(TF0 == 0);		/* Wait until timer0 flag set */
	//TR0 = 0;			/* Stop timer0 */
	//TF0 = 0;			/* Clear timer0 flag */
}

void timectl()
{
	while(!TF0);
	TF0 = 0;
}

void SPI_DDS_Write(uint16_t SPI_byte)
{
	unsigned char SPI_count;
	for (SPI_count = 0; SPI_count < 16; SPI_count++)
		{
			SCLK = 1;		
			SDIH = (SPI_byte & 0x8000);						
			SPI_byte = (SPI_byte << 1);				
			SCLK = 0;
	 }		
}

void freq_gen(uint16_t *freqs,
							uint8_t addr,
							struct BlockStat* StatData)
{
	
	uint16_t F0RWM = ((*(freqs+addr) & 0xF000) >> 12) | 0x4000;
	uint16_t F0RWL =	((*(freqs+addr) & 0x0FFF) >> 0) | 0x4000;
	
	PG_CSL = 0;
	SPI_DDS_Write(RESET);
	SPI_DDS_Write(F0RWL);
	SPI_DDS_Write(F0RWM);
	SPI_DDS_Write(PHASE);
	SPI_DDS_Write(DISRESET);
	PG_CSL = 1;	
	
	StatData->PG = addr;
}

void SPI_DAC_Write(uint16_t SPI_2byte)
{
	uint16_t SPI_count;
	for (SPI_count = 0; SPI_count < 16; SPI_count++)
		{
			SCLK = 0;			
			SDIH = (SPI_2byte & 0x8000);							
			SPI_2byte = (SPI_2byte << 1);				
			SCLK = 1;
	 }		
}

void DACD(uint16_t pr, struct BlockStat* StatData) // -1...1
{
	DACD_CSL = 0;
	SPI_DAC_Write(pr);
	DACD_CSL = 1;
	StatData->DACD = (pr);
} 

void DACOS(uint16_t pr, struct BlockStat* StatData) //-66mV ... +66mV
{
	DACOS_CSL = 0;
	SPI_DAC_Write(pr);
	DACOS_CSL = 1;
	StatData->DACOS = (pr);
	} 



void dev_mux(uint8_t i, struct BlockStat* StatData)
{
	P2 &= i;
	StatData->devMUX = (i & 0x07);
}

void out_mux(uint8_t i, struct BlockStat* StatData)
{
	P2 &= i;
	StatData->outMUX = (i & 0x38);
}





		




























