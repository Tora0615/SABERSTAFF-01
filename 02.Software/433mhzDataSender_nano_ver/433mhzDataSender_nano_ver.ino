/* attiny 不能用，不然是最完美的*/
/*
#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver(2000,11,6);
const char *send_reset = "reset";

void setup() {
  pinMode(5, INPUT);  //3.3v -> D5
  pinMode(LED_BUILTIN, OUTPUT);
  if (!driver.init()){
        digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(10000); 
      }
  
  }

void loop() {
  if ( digitalRead(5) == LOW ) {
    driver.send((uint8_t *)send_reset, strlen(send_reset));
    driver.waitPacketSent();

    //Serial.println("sent_reset");
      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(3000);                       // wait for a second
      digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
      delay(3000);     
  }
//  while(1){
//    
//  }
}

*/

/*
// 無法發送
#include <VirtualWire.h>
uint8_t send_reset[5] = {'r','e','s','e','t'};

void setup() {
  pinMode(5, INPUT);  //3.3v -> D5
  pinMode(LED_BUILTIN, OUTPUT);

  //vw_set_ptt_inverted(true);
  vw_set_tx_pin(5);
  vw_setup(2000);
  }

void loop() {
  if ( digitalRead(5) == LOW ) {
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(3000);  
    
    vw_send((uint8_t *)send_reset, strlen(send_reset));
    vw_wait_tx();
    
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    delay(3000);     
  }
}
*/


#include "ManchesterRF.h" //https://github.com/cano64/ManchesterRF
#define TX_PIN 6 //any pin can transmit

ManchesterRF rf(MAN_600); 

uint8_t data = 1;  // meaning is to reset
String got_from_serial;

void setup() {
  //pinMode(LED_BUILTIN, OUTPUT);  
  rf.TXInit(TX_PIN);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    got_from_serial = Serial.readStringUntil('\n');  // 讀取傳入的字串直到"\n"結尾
    if(got_from_serial == "reset!"){
      rf.transmitByte(data);
      }
  }

//  if ( digitalRead(5) == LOW ) {
//      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
//      delay(500); 
//      rf.transmitByte(data);
//      digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
//      delay(500);   
//    }
}
