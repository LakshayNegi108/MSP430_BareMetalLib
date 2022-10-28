/*
 * BML_Driver.c
 *
 *  Created on: 13-Oct-2022
 *      Author: hp
 */
#include "BML_Driver.h"


void WDT_OFF()
{
    WDTCTL = WDTPW | WDTHOLD; //! Stop Watchdog (Not recommended for code in production and devices working in field)
}

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
}





