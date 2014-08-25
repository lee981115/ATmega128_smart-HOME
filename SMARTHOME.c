#include <mega128.h>
#include <ds1302.h>
#include <lcd.h>
#include <stdio.h>
#define LD 630
#define LE 683
#define LED1_ON 'A'
#define LED1_OFF 'a'
#define LED2_ON 'B'
#define LED2_OFF 'b'
#define STOVE_OFF 'c'
#define STOVE_ON 'C'
#define STOVE2_ON 'D'

int i,j,k;
void servo_motter(short angle);
void lcd_display(void);
char wifi_rx(void);
void rtc_init(void);
void adc_senser(char no);
void lamp_bright(char lux);
void power_disable(void);
void play_music(void);
void play_note(char note);
