/*
 * BML_Driver.c
 *
 *  Created on: 13-Oct-2022
 *      Author: hp
 */
#include "BML_Driver.h"

//=========================================== Watch Dog Timer ========================================================//
void WDT_OFF()
{
    WDTCTL = WDTPW | WDTHOLD; //! Stop Watchdog (Not recommended for code in production and devices working in field)
}
//====================================================================================================================//

void delay(uint16_t t)
{
    uint16_t i;
    for(i=t; i > 0; i--)
        __delay_cycles(1);
}

//=========================================== PORT 1 Functions =======================================================//
void P1_DIR(uint16_t BIT, uint8_t DIR)
{
    if (DIR == OUTPUT_MODE)
    {
        P1DIR |= (BIT);
    }
    else if (DIR == INPUT_MODE)
    {
        P1DIR &= ~(BIT);
    }
}

void P1_REN(uint16_t BIT)
{
    P1REN |= BIT;
}

void P1_PUPDREN(uint16_t BIT, uint8_t PUPD)
{
    P1_REN(BIT);
    if (PUPD == PULLUP)
    {
        P1_WRITE(BIT, HIGH);
    }
    else if (PUPD == PULLDOWN)
    {
        P1_WRITE(BIT, LOW);
    }
}

void P1_PINCONFIG(uint16_t BIT, uint8_t MODE, uint8_t REN, uint8_t PUPD)
{
    P1_DIR(BIT, MODE);
    if ((MODE == INPUT_MODE) && REN == HIGH)
    {
        P1_PUPDREN(BIT, PUPD);
    }
}

void P1_WRITE(uint16_t BIT, uint8_t STATE)
{
    if (STATE == HIGH)
    {
        P1OUT |= (BIT);
    }
    else if (STATE == LOW)
    {
        P1OUT &= ~(BIT);
    }
}

void P1_TOGGLE(uint16_t BIT)
{
    P1OUT ^= (BIT);
}

uint8_t P1_READ(uint16_t BIT, uint8_t PUPD)
{
    if (PUPD == PULLDOWN)
    {
        return (P1IN & BIT);
    }
    else if (PUPD == PULLUP)
    {
        return (!(P1IN & BIT));
    }
    return LOW;
}
//====================================================================================================================//

//=========================================== PORT 2 Functions =======================================================//
void P2_DIR(uint16_t BIT, uint8_t DIR)
{
    if (DIR == OUTPUT_MODE)
    {
        P2DIR |= (BIT);
    }
    else if (DIR == INPUT_MODE)
    {
        P2DIR &= ~(BIT);
    }
}

void P2_REN(uint16_t BIT)
{
    P2REN |= BIT;
}

void P2_PUPDREN(uint16_t BIT, uint8_t PUPD)
{
    P2_REN(BIT);
    if (PUPD == PULLUP)
    {
        P2_WRITE(BIT, HIGH);
    }
    else if (PUPD == PULLDOWN)
    {
        P2_WRITE(BIT, LOW);
    }
}

void P2_PINCONFIG(uint16_t BIT, uint8_t MODE, uint8_t REN, uint8_t PUPD)
{
    P2_DIR(BIT, MODE);
    if ((MODE == INPUT_MODE) && REN == HIGH)
    {
        P2_PUPDREN(BIT, PUPD);
    }
}

void P2_WRITE(uint16_t BIT, uint8_t STATE)
{
    if (STATE == HIGH)
    {
        P2OUT |= (BIT);
    }
    else if (STATE == LOW)
    {
        P2OUT &= ~(BIT);
    }
}

void P2_TOGGLE(uint16_t BIT)
{
    P2OUT ^= (BIT);
}

uint8_t P2_READ(uint16_t BIT, uint8_t PUPD)
{
    if (PUPD == PULLDOWN)
    {
        return (P2IN & BIT);
    }
    else if (PUPD == PULLUP)
    {
        return (!(P2IN & BIT));
    }
    return LOW;
}
//====================================================================================================================//

//=========================================== GPIO IT Functions ======================================================//

void P1_IT_EN(uint16_t BIT, uint8_t EDGE){
    P1IE |= BIT3;
    if(EDGE == RISING_EDGE){
        P1IES &= ~(BIT);
    }
    else if(EDGE == FALLING_EDGE){
        P1IES |= (BIT);
    }
}

uint8_t P1_IT_READ(uint16_t BIT){
    return (P1IFG & BIT);
}

void P2_IT_EN(uint16_t BIT, uint8_t EDGE){
    P1IE |= BIT3;
    if(EDGE == RISING_EDGE){
        P2IES &= ~(BIT);
    }
    else if(EDGE == FALLING_EDGE){
        P2IES |= (BIT);
    }
}

uint8_t P2_IT_READ(uint16_t BIT){
    return (P2IFG & BIT);
}

//====================================================================================================================//

//void EN_INTERRUPTS(){
//    __bis_SR_register(GIE);             // Enable CPU Interrupt
//}
//
//void __attribute__((weak))  P1_ITHandler(){
//    return;
//}
//
//#pragma vector=PORT1_VECTOR
//__interrupt void Port_1(void)
//{
//   P1_ITHandler();
//}


