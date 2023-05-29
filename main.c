#include <stddef.h>
#include <stdint.h>
//#include <C51S.LIB>

#include "my_wiznet.h"
#include "my_fnc.h"
#include "W5500/w5500.h"
#include "Device_Init.h"

#include "SPI_Defs.h"

const uint8_t xdata gw[4] = {172,20,215,254};
const uint8_t xdata mask[4] = {255,255,255,0};
const uint8_t xdata mac[6] = {0x7C,0x8A,0xE1,0x76,0x5E,0x4D};
const uint8_t xdata ipadr[4] = {172,20,215,250};	

uint8_t a;
uint8_t   rx_buf[20] = {0};
uint16_t len, actual_len;
struct BlockStat StatData = {2, 2, 2, 2, 2, 2};
const uint16_t freqs[12] = {0x000A, 0x00C8, 0x012C, 0x03E8, 0x07D0, 0x09C4, 0x0BB8, 0x1356, 0x1388, 0x13BA, 0x2710, 0x5208};

void wizchip_recv_data(struct BlockStat* StatData) {
	len = getSn_RX_RSR(0);
	actual_len = (len > getSn_RXBUF_SIZE(0)) ? getSn_RXBUF_SIZE(0) : len;
	wiz_recv_data(0, rx_buf, actual_len);
	wiz_send_data(0, &StatData, sizeof(StatData));
	setSn_CR(0, Sn_CR_SEND);
}

void main(void)
{
	//Init 80c51
	Device_Init();
	
	//Timer 0 init as 13-bit counter
	TMOD = 0x00;
	timer_start();
	
	//Init w5500
	wiz_init(gw, mask, mac, ipadr);

	while(1) {
		switch(getSn_SR(0)) {
			case(SOCK_CLOSED):
				//START TCP SERVER
				setSn_MR(0, Sn_MR_TCP);
				setSn_PORT(0, 9999);
				timectl();
				setSn_CR(0, Sn_CR_OPEN);
				timectl();
			case(SOCK_INIT): 
				//LISTEN
				setSn_CR(0, Sn_CR_LISTEN);
				timectl();
				break;
			case(SOCK_CLOSE_WAIT):
				//CHECK DISCONNECT-REQUEST AND DISCINNECT PROCESS
				setSn_CR(0, Sn_CR_DISCON);
				setSn_CR(0, Sn_CR_CLOSE);
			case(SOCK_ESTABLISHED):
				//ESTABLISHMENT
				if(!getSn_RX_RSR(0)) {
					wizchip_recv_data(&StatData);
				} 				
			}
	}	
	
}