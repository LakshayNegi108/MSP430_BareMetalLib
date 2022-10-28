//#include <msp430.h>
#include "BML_Driver.h"

int main(void)
{
    WDT_OFF();

    P1_PINCONFIG(BIT7, OUTPUT_MODE, 0, 0);
    P1_PINCONFIG(BIT3, INPUT_MODE, RENABLE, PULLUP);

    while (1)
    {
        volatile unsigned long i;

//        if(P1_READ(BIT3, PULLUP) == HIGH){
//            P1_WRITE(BIT7, HIGH);
//        }
//        else  if(P1_READ(BIT3, PULLUP) == LOW){
//            P1_WRITE(BIT7, LOW);
//        }
        P1_TOGGLE(BIT7);

        __delay_cycles(100000);
    }
}
