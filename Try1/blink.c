//#include <msp430.h>
#include "BML_Driver.h"
/**
 * @brief
 * These settings are wrt enabling uart on Lunchbox
 **/

uint8_t txData[100] = { 0 };
uint16_t i = 0;

void UART_TRANSMIT(uint8_t *txData, uint16_t len)
{
//    register_settings_for_UART();

    if (len == 1)
    {
        while (!(IFG2 & UCA0TXIFG))
            ;          // Check if TX is ongoing
        UCA0TXBUF = *txData;          // TX -> Received Char + 1
        return;
    }
    for (i = 0; i < len; i++)
    {
        while (!(IFG2 & UCA0TXIFG))
            ;          // Check if TX is ongoing
        UCA0TXBUF = txData[i];
    }
}

void register_settings_for_UART()
{
//    DCOCTL = 0;
    BCSCTL3 |= LFXT1S0;
    BCSCTL2 |= SELS;

    P1SEL = BIT1 + BIT2;              // Select UART RX/TX function on P1.1,P1.2
    P1SEL2 = BIT1 + BIT2;

    UCA0CTL1 |= UCSSEL_1;               // UART Clock -> ACLK
    UCA0BR0 = 3;                        // Baud Rate Setting for 32kHz 9600
    UCA0BR1 = 0;                        // Baud Rate Setting for 32kHz 9600
    UCA0MCTL = UCBRS_3;       // Modulation Setting for 32kHz 9600
    UCA0CTL1 &= ~UCSWRST;               // Initialize UART Module
//    IE2 |= UCA0RXIE;                    // Enable RX interrupt
}

/*@brief entry point for the code*/
void main(void)
{
    WDT_OFF();
    CLOCK_CONFIG(DCO_8Mhz);

    register_settings_for_UART();

    UART_TRANSMIT("Working\n", 8);

//    __bis_SR_register(GIE); // Enter LPM0, Enable Interrupt
    while (1)
    {
        UART_TRANSMIT("Working\n", 8);
        __delay_cycles(1000000);
    }

}

/**
 * @brief
 * Interrupt Vector for UART on LunchBox
 **/
//#pragma vector=USCIAB0RX_VECTOR         // UART RX Interrupt Vector
//__interrupt void USCI0RX_ISR(void)
//{
//    while (!(IFG2 & UCA0TXIFG))
//        ;          // Check if TX is ongoing
//    UCA0TXBUF = UCA0RXBUF;          // TX -> Received Char + 1
//
//}
