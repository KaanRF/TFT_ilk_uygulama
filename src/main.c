#include "stm32f4xx.h"
#include "delay.h"
#include "tft_lcd.h"
#include "touch.h"
//#include "Julija.h"

extern u8 gImage_sil[];
void tft_yaz(void);
extern unsigned int xxx,yyy;
extern unsigned char flag;


char stringas[8];
int xold,yold;


int main(void)
{

	//float x1,y1	;
	//	float x2,y2;
  Delay(0x3FFFFF);
  LCD_Init();
  Delay(0x3FFFFF);
  touch_init();
  LCD_Clear(BLACK);
  //LCD_SetTextColor(BLUE);

  tft_yaz();

  Read_Ads7846();
                Pen_Point.X0=(int)((Pen_Point.Y-103)/7.7);
                Pen_Point.Y0=(int)((Pen_Point.X-104)/5.56);
                if(Pen_Point.X0>240)
                {
                  Pen_Point.X0=240;
                }
                if(Pen_Point.Y0>320)
                {
                  Pen_Point.X0=320;
                }

while(1)
 {
	DON:

	 Convert_Pos();

	 if ((Pen_Point.X0>180) && (Pen_Point.X0<210) && ( Pen_Point.Y0>304) && ( Pen_Point.Y0<320))
		{
							LCD_Clear(LCD_COLOR_MAGENTA);
							LCD_SetBackColor(GREEN);
									  LCD_SetTextColor(CYAN);
							          LCD_StringLine(215,300,"SIL");
							          LCD_StringLine(172,300,"YENI");
							goto DON ;
							}



	  if((Pen_Point.X0>220) && (Pen_Point.X0<239) && (Pen_Point.Y0>304)&&(Pen_Point.Y0<320))
	  {

		  LCD_Clear(RED);
		  LCD_BackLight(100);

		  LCD_SetBackColor(GREEN);
		  LCD_SetTextColor(CYAN);
          LCD_StringLine(215,300,"SIL");
          LCD_StringLine(172,300,"YENI");


         goto DON;
	  }
	  if ((Pen_Point.X0>0) && (Pen_Point.Y0>0))
	 		 						{
		  Pixel(Pen_Point.X0,Pen_Point.Y0,YELLOW);
		    Pixel(Pen_Point.X0,Pen_Point.Y0+1,YELLOW);
		    Pixel(Pen_Point.X0+1,Pen_Point.Y0,YELLOW);
		    Pixel(Pen_Point.X0+1,Pen_Point.Y0+1,YELLOW);
	 		 						}

  }
 }


void tft_yaz(void)
{
	LCD_SetTextColor(GREEN);

	  LCD_SetBackColor(LCD_COLOR_BLUE);
	  LCD_BackLight(100);
	  LCD_StringLine(100,30, "Kaan");
	  LCD_StringLine(85,45, "Kandemir");
	  LCD_StringLine(30,80,"NAMIK KEMAL UNIVERSITESI");
	  LCD_StringLine(15,100,"CORLU MUHENDISLIK FAKULTESI");
	  LCD_StringLine(8,120,"ELEKTRONIK VE HABERLESME MUH.");
	  LCD_StringLine(15,170,"**3.2' TFT LCD UYGULAMASI**");
	  LCD_StringLine(45,190,"SSD1289 VE XPT2046 ");

}



uint16_t EVAL_AUDIO_GetSampleCallBack(void)
{
    return 0; // ses çipini kullanýyorsanýz tek sample veriyi burada return ile döndürün.
}
void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size)
{
    return; // ses çipini kullanýyorsanýz  burada çipe veri aktarýmý DMA sona ermiþ
}

