#ifndef _SPI_DEFS_
#define _SPI_DEFS_

#include <c8051F340.h>
#include <stdint.h>

//Peripherial BUS
sbit SDIH    = P3^0; //PG/DACD/DACOS Data Input
sbit SCLK    = P3^1; //PG/DACD/DACOS Serial Clock

//DDS chip
sbit PG_CSL  = P3^2; //PG Chip Select 
//Defs for DDS chip
/*Frequencies map
   0.1Hz = 0x000A; F0RWL = 0x400A ; F0RWM = 0x4000 ;
   2.0Hz = 0x00C8; F0RWL = 0x40C8 ; F0RWM = 0x4000 ;
	 3.0Hz = 0x012C; F0RWL = 0x412C ; F0RWM = 0x4000 ;
	10.0Hz = 0x03E8; F0RWL = 0x43E8 ; F0RWM = 0x4000 ;
	20.0Hz = 0x07D0; F0RWL = 0x47D0 ; F0RWM = 0x4000 ;
	25.0Hz = 0x09C4; F0RWL = 0x49C4 ; F0RWM = 0x4000 ;
	30.0Hz = 0x0BB8; F0RWL = 0x4BB8 ; F0RWM = 0x4000 ;
	49.5Hz = 0x1356; F0RWL = 0x4356 ; F0RWM = 0x4001 ;
	50.0Hz = 0x1388; F0RWL = 0x4388 ; F0RWM = 0x4001 ;
	50.5Hz = 0x13BA; F0RWL = 0x43BA ; F0RWM = 0x4001 ;
 100.0Hz = 0x2710; F0RWL = 0x4710 ; F0RWM = 0x4002 ;
 210.0Hz = 0x5208; F0RWL = 0x4208 ; F0RWM = 0x4005 ;
*/
#define RESET         0x2100
#define DISRESET     	0x2000
#define PHASE					0xC000



#define _0.1Hz_     	 0
#define _2.0Hz_     	 1
#define _3.0Hz_     	 2
#define _10.0Hz_     	 3
#define _20.0Hz_     	 4
#define _25.0Hz_       5
#define _30.0Hz_    	 6
#define _49.5Hz_   		 7
#define _500Hz_     	 8
#define _50.5Hz_     	 9
#define _100.0Hz_    	10
#define _210.0Hz_     11

//ROM & W5500
sbit MISO    = P1^7; //ROM/W5500 Serial Output
sbit CLK     = P1^5; //ROM/W5500 Serial Clock
sbit NSSR   = P1^6;  //ROM Chip Select
sbit MOSI    = P1^4; //ROM/W500 Serial Input
sbit NSS     = P3^3; //W5500 Chip Select  

//DACD  
sbit DACD_CSL  = P3^4;
//Defs for DACD
#define devFINE(pr) = DACD(pr)

//DACOS
sbit DACOS_CSL = P3^5;
//Defs for DACOS
#define setOS(pr) = DACOS(pr)

//Division MUX
sbit TS1_DA0H =	P2^0;
sbit TS1_DA1H =	P2^1;
sbit TS1_DA2H =	P2^2;
//Defs for division MUX
#define devCOARSE1 		= dev_mux(0xF8)
#define devCOARSE2		= dev_mux(0xF9)
#define devCOARSE4		= dev_mux(0xFA)
#define devCOARSE8		= dev_mux(0xFB)
#define devCOARSE16		= dev_mux(0xFC)
#define devCOARSE32		= dev_mux(0xFD)
#define devCOARSE64		= dev_mux(0xFE)
#define devCOARSE128	= dev_mux(0xFF)

//Output MUX
sbit TS1_TA0H = P2^3;
sbit TS1_TA1H = P2^4;
sbit TS1_TA2H = P2^5;
//Defs for output MUX
#define outAGND 	 \ out_mux(0xE3)             
#define outGEXT    \ out_mux(0xE7)                     `
#define outVREF    \ out_mux(0xEB)                    
#define outTS2     \ out_mux(0xEF)                  
#define outTS1.1   \ out_mux(0xF3)   

struct BlockStat
{
	uint8_t PG ;
	uint8_t DACD;
	uint8_t DACOS;
	uint16_t devMUX;
	uint16_t outMUX;
	uint8_t WIZNET;

}; 

#endif






//sbit V0_VRFL = P3^5;
//sbit V0DIRL  = P2^2;
//sbit V0INVL  = P2^3;
//sbit SIMI_ONL = P1^3;
//sbit V0RR_MSRL = P2^5;
//sbit V0_MSRL   = P2^4;
//sbit TSD_A0H   = P3^7;

/*Frequencies
   0.1Hz = 0x000A; F0RWL = 0x400A ; F0RWM = 0x4000 ;
   2.0Hz = 0x00C8; F0RWL = 0x40C8 ; F0RWM = 0x4000 ;
	 3.0Hz = 0x012C; F0RWL = 0x412C ; F0RWM = 0x4000 ;
	10.0Hz = 0x03E8; F0RWL = 0x43E8 ; F0RWM = 0x4000 ;
	20.0Hz = 0x07D0; F0RWL = 0x47D0 ; F0RWM = 0x4000 ;
	25.0Hz = 0x09C4; F0RWL = 0x49C4 ; F0RWM = 0x4000 ;
	30.0Hz = 0x0BB8; F0RWL = 0x4BB8 ; F0RWM = 0x4000 ;
	49.5Hz = 0x1356; F0RWL = 0x4356 ; F0RWM = 0x4001 ;
	50.0Hz = 0x1388; F0RWL = 0x4388 ; F0RWM = 0x4001 ;
	50.5Hz = 0x13BA; F0RWL = 0x43BA ; F0RWM = 0x4001 ;
 100.0Hz = 0x2710; F0RWL = 0x4710 ; F0RWM = 0x4002 ;
 210.0Hz = 0x5208; F0RWL = 0x4208 ; F0RWM = 0x4005 ;
*/

/*uint8_t WREN = 0x06;
uint8_t WRDI = 0x04;
uint8_t RDSR = 0x05;
uint8_t READ = 0x03;
uint8_t WRITE= 0x02;
uint8_t ADDR = 0x02; //Something Addres*/

