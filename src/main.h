/*
 * main.h
 *
 *  Created on: Apr 26, 2013
 *      Author: Kaan
 */
/**
  ******************************************************************************
  * @file    Mems TFT
  * @author  Ahmet
  * @version V1.1.0
  * @date    18.04.2012
  * @brief   Header for main.c module
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H
/* Includes ------------------------------------------------------------------*/
#include "stm32f4_discovery.h"
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"
#include "stm32f4xx_it.h"
#include "stm32f4_discovery_lis302dl.h"
#include "tft_lcd.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define DOUBLECLICK_Z                    ((uint8_t)0x60)
#define SINGLECLICK_Z                    ((uint8_t)0x50)

/* TIM2 Autoreload and Capture Compare register values */
#define TIM_ARR                          ((uint16_t)1900)
#define TIM_CCR                          ((uint16_t)1000)
/* Exported macro ------------------------------------------------------------*/
#define ABS(x)                           (x < 0) ? (-x) : x
#define MAX(a,b)                         (a < b) ? (b) : a


void TimingDelay_Decrement(void);
void Delay(__IO uint32_t nTime);


#endif /* __MAIN_H */
