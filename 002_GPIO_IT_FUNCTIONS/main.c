//#include <msp430.h>
#include "BML_Driver.h"
/**
 * blink.c
 */
int main(void)
{
    WDT_OFF();

    P1_PINCONFIG(BIT7, OUTPUT_MODE, 0, 0);
    P1_PINCONFIG(BIT3, INPUT_MODE, RENABLE, PULLUP);

    P1_IT_EN(BIT3, FALLING_EDGE);    // Select Interrupt on Rising Edge, Enable Interrupt on SW pin

    EN_INTERRUPTS();

    while (1)
    {

    }
}

void P1_ITHandler()
{
    if (P1_IT_READ(BIT3))                      // If SW is Pressed
    {
//        P1OUT ^= RED;                   // Toggle RED LED
        __delay_cycles(50000);
        P1_TOGGLE(BIT7);
        __delay_cycles(50000);
        P1IFG &= ~BIT3;                   // Clear SW interrupt flag
    }
}
