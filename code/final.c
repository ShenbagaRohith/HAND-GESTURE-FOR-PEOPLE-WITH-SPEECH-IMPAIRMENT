#define LCD_RS_PIN      PIN_C0                                   
#define LCD_RW_PIN      PIN_C1 
#define LCD_ENABLE_PIN  PIN_C2 
#define LCD_DATA4       PIN_C3                                    
#define LCD_DATA5       PIN_C4                                    
#define LCD_DATA6       PIN_C5                           
#define LCD_DATA7       PIN_C6

#include<16F877A.h>
#device ADC=10
#use delay(crystal=8000000)
#include<lcd.c>

unsigned int16 a0,a1,a2,a3,a4;
void main()
{
   int i=0;
   set_tris_b(0x00);
   lcd_init();
   setup_adc(ADC_CLOCK_DIV_32);
   setup_adc_ports(AN0_AN1_AN2_AN3_AN4);
   delay_ms(100);
   lcd_gotoxy(3,1);
   lcd_putc("Welcome.....");
   delay_ms(2000);
   lcd_putc('\f');
   output_high(PIN_D2);
   while(TRUE){
      set_adc_channel(0);
      a0=read_adc();
      delay_ms(100);
      set_adc_channel(1);
      a1=read_adc();
      delay_ms(100);
      set_adc_channel(2);
      a2=read_adc();
      delay_ms(100);
      set_adc_channel(3);
      a3=read_adc();
      delay_ms(100);
      set_adc_channel(4);
      a4=read_adc();
      
      
      output_bit(PIN_B0, 1);
      output_bit(PIN_B1, 1);
      output_bit(PIN_B2, 1);
      output_bit(PIN_B3, 1);
      output_bit(PIN_B4, 1);
      output_bit(PIN_B5, 1);
      output_bit(PIN_B6, 1);
      output_bit(PIN_B7, 1);

      if(i==0){

         if(a0>600 && a1<600 && a2<600 && a3<600 && a4<600 && i==0){
            Lcd_putc("HAI");
            output_bit(PIN_B0, 0);
            delay_ms(2000);
            output_bit(PIN_B0, 1);
            lcd_putc('\f');
            output_low(PIN_D2);
            i=1;
         }
         if(a0<600 && a1<600 && a2>600 && a3>600 && a4<600 && i==0){
            Lcd_putc("Good Morning");
            output_bit(PIN_B1, 0);
            delay_ms(2000);
            output_bit(PIN_B1, 1);
            lcd_putc('\f');
            output_low(PIN_D2);
            i=1;
         }
         if(a0<600 && a1<600 && a2<600 && a3>600 && a4<600 && i==0){
            Lcd_putc("HELP");
            output_bit(PIN_B2, 0);
            delay_ms(2000);
            output_bit(PIN_B2, 1);
            lcd_putc('\f');
            output_low(PIN_D2);
            i=1;
         }
         if(a0<600 && a1>600 && a2>600 && a3>600 && a4<600 && i==0){
            Lcd_putc("Good Night");
            output_bit(PIN_B3, 0);
            delay_ms(2000);
            output_bit(PIN_B3, 1);
            lcd_putc('\f');
            output_low(PIN_D2);
            i=1;
         }
         if(a0<600 && a1<600 && a2<600 && a3>600 && a4>600 && i==0){
            Lcd_putc("Hungry");
            output_bit(PIN_B4, 0);
            delay_ms(2000);
            output_bit(PIN_B4, 1);
            lcd_putc('\f');
            output_low(PIN_D2);
            i=1;
         }
         if(a0<600 && a1>600 && a2>600 && a3>600 && a4>600 && i==0){
            Lcd_putc("Water");
            output_bit(PIN_B5, 0);
            delay_ms(2000);
            output_bit(PIN_B5, 1);
            lcd_putc('\f');
            output_low(PIN_D2);
            i=1;
         }
         if(a0<600 && a1<600 && a2>600 && a3>600 && a4>600 && i==0){
            Lcd_putc("No");
            output_bit(PIN_B6, 0);
            delay_ms(2000);
            output_bit(PIN_B6, 1);
            lcd_putc('\f');
            output_low(PIN_D2);
            i=1;
         }
         if(a0>600 && a1>600 && a2>600 && a3>600 && a4>600 && i==0){
            Lcd_putc("Do It");
            output_bit(PIN_B7, 0);
            delay_ms(2000);
            output_bit(PIN_B7, 1);
            lcd_putc('\f');
            output_low(PIN_D2);
            i=1;
         }
      }
      else if(a0<600 && a1<600 && a2<600 && a3<600 && a4<600){
         i=0;
         output_high(PIN_D2);
      }
      else if(a0>600 || a1>600 || a2>600 || a3>600 || a4>600){
         Lcd_putc("Change to stable");
         delay_ms(2000);
         lcd_putc('\f');
      }
         
   }
}
