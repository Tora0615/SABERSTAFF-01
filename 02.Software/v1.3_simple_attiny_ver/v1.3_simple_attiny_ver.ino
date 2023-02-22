/*
Attiny Pin
(reset) 5   Vcc
        3   2
        4   1
        GND 0 <-- use this
*/
#include "ManchesterRF.h" //https://github.com/cano64/ManchesterRF
#include <Adafruit_NeoPixel.h>
#include <avr/power.h>
#include "music_data.h"

#define SIG_PIN 0 //attiny 0 
#define RX_PIN 1  //attiny 1
#define FAKEPIXELSNUM 60   //燈珠數量 (為了彩虹，設10倍)
#define REALPIXELSNUM 6


//初始化 NeoPixel 前，要先設定基本參數 : 有多少燈珠、傳訊息用哪個 pin 
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(FAKEPIXELSNUM, SIG_PIN, NEO_GRB + NEO_KHZ800);
//link speed, try also MAN_300, MAN_600, MAN_1200, MAN_2400, MAN_4800, MAN_9600, MAN_19200, MAN_38400
ManchesterRF rf(MAN_600); 


// non-volatile variable 
bool allowToBright __attribute__ (( section ( ".noinit" ))) ;
bool isStandby __attribute__ (( section ( ".noinit" ))) ;

// nornal variable 
uint8_t currentArrayPosition = -1;
unsigned long starttime = millis();
bool isAllPixelSame = false;
float next_beat_time;  
byte light_style = 0;
uint8_t reset_sig;
uint16_t rainbowStartPos = 0;
byte shootColorPos = 0;


// extern unsigned long timer0_millis;
// while(timer0_millis < 1000); 
// timer0_millis = 0; 
//利用底層程式碼釋放Arduino空間  https://itw01.com/2DKZIEA.html  

// soft reboot fuction  
void(* resetSystem)(void) = 0;




void setup() {
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif

  // init 433mhz and NeoPixel   
  rf.RXInit(RX_PIN);
  pixels.begin(); 
  //pixels.setBrightness(255);
  
  //when first boot, defult data are both zero. So change it to recongize.
  if(!isStandby && !allowToBright){  
    isStandby = 1;
    allowToBright = 1;
  }

  // power on sucess signal
  unsigned long local_timer = 0; 
  pixels.setPixelColor(0, 0,0,150);     pixels.show();
  local_timer = millis();  while( (millis()-local_timer)<100 );          
  pixels.clear();  pixels.show();  
  local_timer = millis();  while( (millis()-local_timer)<100 );
}

void loop() {
  if(isStandby){
    unsigned long local_timer = 0;
    //delay(1);   //沒delay會跑太快，收到訊號存不下來
    local_timer = millis();  while( (millis()-local_timer)<4 );
    // check 433mhz got data or not
    if (rf.available()) {  //something is in RX buffer
      if (rf.receiveByte(reset_sig)) {  // data save into reset_sig
        if (reset_sig == 1  && allowToBright){  // check data and check if it is allow to bright (only first time allowed)

          // got reboot data's success signal 
          pixels.setPixelColor(0, 150,0,0);   pixels.show();
          local_timer = millis();  while( (millis()-local_timer)<100 );          
          pixels.clear();  pixels.show();  
          
          // change standby signal, then reboot
          isStandby = 0; 
          resetSystem(); 
        }
      }
    }  
  }else{
    // before delay_time, shouldn't do anything (light shouldn't bright)
    if ( delay_time * 1000 < (millis() - starttime) ){  //after delay_time
      // before change time & pixel don't have to change
      if ( ((delay_time + next_beat_time)* 1000 > (millis() - starttime)) && isAllPixelSame){
        // Do nothing, loop again.
        // if allPixel NOT SAME, program will not go into here to wait. 
        // So we need to control time and delay in complex style function
      }else{
          // at the end of the song
          if(currentArrayPosition == timeListSize){   
            // set the standby signal and turn off all light.
            isStandby = 1;  allowToBright=0; pixels.clear();  //nornal 
            //currentArrayPosition = 0;  starttime = millis();  //for infinte loop
          }else{
            currentArrayPosition ++;
            next_beat_time = pgm_read_float_near(timeList + currentArrayPosition);
            light_style = pgm_read_byte_near(styleList + currentArrayPosition); 
            checkIsAllPixelSame(light_style);
            // save the pixel change.
            changeStyle(light_style);
          }
        pixels.show();
      }
    }
  }
}



/* 用燈條顯示狀態 (塞不下了qq)
#define POWERON 0
#define REBOOT 1
#define WARNING 2

void showStatus(byte status){
  unsigned long local_timer = 0;  
  if (status == POWERON){
    pixels.setPixelColor(0, 0,0,150);   
  }else if(status == REBOOT){
    pixels.setPixelColor(0, 150,0,0);     
  }else if(status == WARNING){
    pixels.setPixelColor(0, 150,150,0); 
  }
  pixels.show();
  local_timer = millis();  while( (millis()-local_timer)<100 );          
  pixels.clear();  pixels.show();  
  local_timer = millis();  while( (millis()-local_timer)<100 );
}
*/
      
/*
變數 __attribute__ (( section ( ".noinit" ))) 
https://atadiat.com/en/e-how-to-preserve-a-variable-in-ram-between-software-resets/

Arduino - 利用PROGMEM将数据写到闪存（程序存储空间）
https://blog.csdn.net/sdlgq/article/details/88720706


減少空間使用
少用全域變數
少用delay
盡量能重複用的就重複用

*/
