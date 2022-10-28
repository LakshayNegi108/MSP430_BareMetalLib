/*
 * BML_IT.c
 *
 *  Created on: 13-Oct-2022
 *      Author: hp
 */
#include "BML_IT.h"

void EN_INTERRUPTS(){
    __bis_SR_register(GIE);             // Enable CPU Interrupt
}

void __attribute__((weak))  P1_ITHandler(){
    return;
}

#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{
   P1_ITHandler();
}

void __attribute__((weak))  P2_ITHandler(){
    return;
}

#pragma vector=PORT2_VECTOR
__interrupt void Port_2(void)
{
   P2_ITHandler();
}



