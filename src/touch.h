/*
 * touch.h
 *
 *  Created on: Apr 26, 2013
 *      Author: Kaan
 */

#ifndef __TOUCH_7846_H
#define __TOUCH_7846_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f4xx.h"
typedef struct
{
   u16 X0;
   u16 Y0;
   u16 X;
   u16 Y;
   u8  Key_Sta;
   u8  Key_LSta;

   float xfac;
   float yfac;
   short xoff;
   short yoff;
}Pen_Holder;
extern Pen_Holder Pen_Point;
#define TOUCH_CS_PORT    GPIOB
#define TOUCH_CS_PIN    GPIO_Pin_12

#define T_CS()   GPIO_ResetBits(TOUCH_CS_PORT, TOUCH_CS_PIN);
#define T_DCS()  GPIO_SetBits(TOUCH_CS_PORT, TOUCH_CS_PIN);

#define CMD_RDY 0X90  //0B10010000
#define CMD_RDX   0XD0  //0B11010000

#define PEN  GPIOD->IDR&(1<<6) //
#define NPEN !(0x0080&PEN)      //!PEN

unsigned char SPI_WriteByte(u8 num);
void SpiDelay(unsigned int DelayCnt);
u16 TPReadX(void);
u16 TPReadY(void);
u8 read_once(void);
u8 Read_Ads7846(void);

void EXTI9_5_IRQHandler(void);
void NVIC_TOUCHConfiguration(void);
void touch_init(void);
void LCD_ShowNum(uint8_t x,uint16_t y,uint16_t data);

void Touch_Adjust(void);
#ifdef __cplusplus
}
#endif

#endif



















