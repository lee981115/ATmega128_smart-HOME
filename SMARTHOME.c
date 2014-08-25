//
//power_save_time --> 시간기준
//servo motter 90도 열림기준
//

#include <mega128.h>
#include <ds1302.h>
#include <lcd.h>
#include <stdio.h>

#asm
.equ __lcd_port=0x12
.equ __ds1302_port=0x1b
.equ __eclk_port=0;
.equ __sklc_port=2;
.equ __dtl_port=1;
#endasm

#define LD 6348
#define LE 6033
#define LED1_ON 'A'
#define LED1_OFF 'a'
#define LED2_ON 'B'
#define LED2_OFF 'b'
#define STOVE_OFF 'c'
#define STOVE1_ON 'C'
#define STOVE2_ON 'D'
#define POWER_SAVE_ON 'S'
#define WINDOW_OPEN 'D'
#define WINDOW_CLOSE 'd'
#define GAS_BELV_OPEN 'F'
#define GAS_BELV_CLOSE 'f'

int power_save_time=0;

void servo_motter(short);
void lcd_display(void);
char char_rx(void);
void rtc_init(void);
void adc_senser(char);
void lamp_bright(char);
void power_disable(void);
void play_music(void);
void play_note(char);
void power_save_time_set(char);

int char_rx(void)
{
  char data;
  while((UACR0&0x08)!=1);
  dara=UDR0;
  if((data>='0')&&(data<='9'))
    return(data-'0');
  else return data;
}

void power_save_set(int time)
{
  int i;time_msec,;
  time_sec=time*3600;
  PORTA.4=0;
  for(i=0;i<=time_sec;i++)
    delay_ms(1000);
  PORTA.4=1;
  lcd_init(16);
}

void main(void)
{
  DDRC=0xff;
  DDRB=0xff;
  DDRE=0x02;
  PORTA.4=1;
  EIMSK=0xF0;
  EICRRB=0xA0;
  #asm("sei")
  
  
}
