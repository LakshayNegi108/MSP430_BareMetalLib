/*
 * BML_Driver.h
 *
 *  Created on: 13-Oct-2022
 *      Author: hp
 */

#ifndef LIBRARIES_BML_DRIVER_INC_BML_DRIVER_H_
#define LIBRARIES_BML_DRIVER_INC_BML_DRIVER_H_

#include <stdint.h>
#include <msp430.h>

#define INPUT_MODE      0
#define OUTPUT_MODE     1

#define LOW             0
#define HIGH            1

#define PULLDOWN        0
#define PULLUP          1

#define RDISABLE         0
#define RENABLE          1

#define RISING_EDGE     0
#define FALLING_EDGE    1

void WDT_OFF();
void delay(uint16_t t);
void P1_DIR(uint16_t BIT, uint8_t DIR);
void P1_REN(uint16_t BIT);
void P1_PUPDREN(uint16_t BIT, uint8_t PUPD);
void P1_PINCONFIG(uint16_t BIT, uint8_t MODE, uint8_t REN, uint8_t PUPD);
void P1_WRITE(uint16_t BIT, uint8_t STATE);
void P1_TOGGLE(uint16_t BIT);
uint8_t P1_READ(uint16_t BIT, uint8_t PUPD);

void P2_DIR(uint16_t BIT, uint8_t DIR);
void P2_REN(uint16_t BIT);
void P2_PUPDREN(uint16_t BIT, uint8_t PUPD);
void P2_PINCONFIG(uint16_t BIT, uint8_t MODE, uint8_t REN, uint8_t PUPD);
void P2_WRITE(uint16_t BIT, uint8_t STATE);
void P2_TOGGLE(uint16_t BIT);
uint8_t P2_READ(uint16_t BIT, uint8_t PUPD);

void P1_IT_EN(uint16_t BIT, uint8_t EDGE);
uint8_t P1_IT_READ(uint16_t BIT);

void P2_IT_EN(uint16_t BIT, uint8_t EDGE);
uint8_t P2_IT_READ(uint16_t BIT);

#endif /* LIBRARIES_BML_DRIVER_INC_BML_DRIVER_H_ */
