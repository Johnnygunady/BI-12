 /////////////////////////////////////
//  Generated Initialization File  //
/////////////////////////////////////

#include "Device_Init.h"


// Peripheral specific initialization functions,
// Called from the Init_Device() function
void PCA_Init()
{
    PCA0MD    &= ~0x40; //Watchdog timer is off
    PCA0MD    = 0x00;   //?
}

//void Timer_Init()
//{
//    TMOD      = 0x20; //Mode 2: 8-bit counter/timer with auto-reload
//    CKCON     = 0x08; //Timer 1 Clock Select.
//    TH1       = 0xBB; //High byte of 16-bit Timer is 10111011
//}

/*void UART_Init()
{
    SBRLL1    = 0x98;
    SBRLH1    = 0xFF;
    SCON1     = 0x10;
    SBCON1    = 0x43;
}*/

/*void SPI_Init()/*
{
    SPI0CFG   = 0x40;
    SPI0CN    = 0x01;
}*/

void Port_IO_Init()
{
    // P0.0  -  Unassigned,  Open-Drain, Digital
    // P0.1  -  Unassigned,  Open-Drain, Digital
    // P0.2  -  Unassigned,  Open-Drain, Digital
    // P0.3  -  Unassigned,  Open-Drain, Digital
    // P0.4  -  Unassigned,  Open-Drain, Digital
    // P0.5  -  Unassigned,  Open-Drain, Digital
    // P0.6  -  Unassigned,  Open-Drain, Digital
    // P0.7  -  Unassigned,  Open-Drain, Digital

    // P1.0  -  Unassigned,  Open-Drain, Digital
    // P1.1  -  Unassigned,  Open-Drain, Digital
    // P1.2  -  Unassigned,  Open-Drain, Digital
    // P1.3  -  Unassigned,  Push-Pull,  Digital
    // P1.4  -  Unassigned,  Push-Pull,  Digital
    // P1.5  -  Unassigned,  Push-Pull,  Digital
    // P1.6  -  Unassigned,  Push-Pull,  Digital
    // P1.7  -  Unassigned,  Open-Drain, Digital

    // P2.0  -  Unassigned,  Push-Pull,  Digital
    // P2.1  -  Unassigned,  Push-Pull,  Digital
    // P2.2  -  Unassigned,  Push-Pull,  Digital
    // P2.3  -  Unassigned,  Push-Pull,  Digital
    // P2.4  -  Unassigned,  Push-Pull,  Digital
    // P2.5  -  Unassigned,  Push-Pull,  Digital
    // P2.6  -  Unassigned,  Open-Drain, Digital
    // P2.7  -  Unassigned,  Open-Drain, Digital

    // P3.0  -  Unassigned,  Push-Pull,  Digital
    // P3.1  -  Unassigned,  Push-Pull,  Digital
    // P3.2  -  Unassigned,  Push-Pull,  Digital
    // P3.3  -  Unassigned,  Open-Drain, Digital
    // P3.4  -  Unassigned,  Open-Drain, Digital
    // P3.5  -  Unassigned,  Push-Pull,  Digital
    // P3.6  -  Unassigned,  Open-Drain, Digital
    // P3.7  -  Unassigned,  Open-Drain, Digital

    P1MDOUT   = 0x78;
    P2MDOUT   = 0x3F;
    P3MDOUT   = 0x27;
    P4MDOUT   = 0xF8;
    XBR1      = 0x40;
}

void Oscillator_Init()
{
//    int i = 0;
//    CLKMUL    = 0x80;              // Clock Multiplier Enable
//    for (i = 0; i < 20; i++);      // Wait 5us for initialization
//    CLKMUL    |= 0xC0;             // Crystal Oscillator Mode
//    while ((CLKMUL & 0x20) == 0);  // Wait while Clock Multiplier not ready
//    CLKSEL    = 0x02;              //External Oscillator  4x Clock Multiplier / 2
    OSCICN    = 0x83;              //Crystal Oscillator Mode & SYSCLK derived from Internal H-F Oscillator divided by 1.
}

// Initialization function for device,
// Call Init_Device() from your main program
void Device_Init (void)
{
    PCA_Init();
		//Timer_Init();
    //UART_Init();
    //SPI_Init();
    Port_IO_Init();
    Oscillator_Init();
}
