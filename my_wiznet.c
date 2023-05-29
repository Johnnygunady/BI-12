#include "my_wiznet.h"
#include "SPI_Defs.h"
#include "W5500/w5500.h"


#include <string.h>

void delay(uint16_t i1)
{
	while(i1 != 0) i1--;
}

void my_cs_sel()
{
	NSS = 0;
}

void my_cs_desel()
{
	NSS = 1;
}

uint8_t my_spi_rb(void)
{
	uint8_t cnt;
	uint16_t d=0;  
	for(cnt = 0; cnt < 8; cnt++)
	{
		CLK = 0;
		d |= MISO;
		d<<=1;
		CLK = 1;
	}

	d>>=1;
	d = (uint8_t)d;
	return(d);
}
	
void my_spi_wb(uint8_t d)
{
	uint8_t cnt;
	for(cnt = 0; cnt < 8; cnt++)
	{
		CLK = 0;
		MOSI = ((1<<7) & d);
		d<<=1;
		CLK =1;
	}
}

void my_cris_en()
{
	IE &= ~(1<<7);   //MSB in IE = 0 == Disable All Interrupts 
}

void my_cris_ex()
{
	IE |= (1<<7);   //MSB in IE = 1 == Enable All Interrupts 
}

void read_buf(uint8_t* pBuf, uint16_t len)
{
	uint8_t cnt;
	for(cnt = 0; cnt < len; cnt++)
	{
		*pBuf++	= my_spi_rb();
	}
}

void write_buf(uint8_t* pBuf, uint16_t len)
{
	uint8_t cnt;
	for(cnt = 0; cnt < len; cnt++)
	{
		my_spi_wb(*pBuf++);
	}	
}

uint8_t passADDR(uint8_t* gw, uint8_t* mask, uint8_t* mac, uint8_t* ipadr)
{
	uint8_t tmp[6] = {0, 0, 0, 0, 0 ,0 };
	uint8_t check_gw, 
					check_mask, 
					check_mac, 
					check_ip;
	
	setGAR(gw);
	delay(100);
	setSUBR(mask);
	delay(100);
	setSHAR(mac);
	delay(100);
	setSIPR(ipadr);
	delay(100);
	
	//Check addresses
	getGAR(tmp);
	check_gw = (memcmp(gw, tmp, 4) == 0) ? 1 : 0;
	getSUBR(tmp);
	check_mask = (memcmp(mask, tmp, 4) == 0) ? 1 : 0;
	getSHAR(tmp);
	check_mac = (memcmp(mac, tmp, 6) == 0) ? 1 : 0;
	getSIPR(tmp);
	check_ip = (memcmp(ipadr, tmp, 4) == 0) ? 1 : 0;
	if (check_gw && check_mask && check_mac && check_ip) return 1;
	return 0;
}


uint8_t wiz_init(uint8_t* gw, uint8_t* mask, uint8_t* mac, uint8_t* ipadr)
{
	reg_wizchip_cs_cbfunc(my_cs_sel, my_cs_desel);
	reg_wizchip_spi_cbfunc(my_spi_rb, my_spi_wb);
	reg_wizchip_spiburst_cbfunc(read_buf, write_buf);
	reg_wizchip_cris_cbfunc(my_cris_en, my_cris_ex);
	wizchip_init(NULL, NULL);							

	return passADDR(gw, mask, mac, ipadr);
}





