// type 0 = 一般黃色 / type 1 = 紫色
void fire(byte type, byte brightness){
  unsigned long local_timer = 0;
  // 原時間控制部分，為省空間已移到上一層統一控制，但可讀性變低
  // while(true){
  //   if( millis()-starttime > ((delay_time + next_beat_time)* 1000) ){
  //     pixels.setBrightness(255);
  //     break;
  //   }else{
      setAllFirePixels(type, brightness); pixels.show();   
      local_timer = millis();  while( (millis()-local_timer)<random(150, 350) );  // equal function : delay(random(50, 300));   
  //   }
  // }
}


// 
void rainbow(byte type, byte speed){
  unsigned long local_timer = 0;
  uint16_t posAdd = 0;

  switch(type){
    case RAINBOWSIMILAR:
      switch(speed){
        case SLOW:
          posAdd = 50;
          break;
        case MID:
          posAdd = 275;
          break;
        case FAST:
          posAdd = 500;
          break;
        case VERYFAST:
          posAdd = 1000;
          break;
      }  
    break;
    case RAINBOWDISTRIBUTED:
      switch(speed){
        case SLOW:
          posAdd = 225;//300;
          break;
        case MID:
          posAdd = 450;//600;
          break;
        case FAST:
          posAdd = 900;//1200;
          break;
        case VERYFAST:
          posAdd = 1800;
          break;
      }  
    break;
  }
  
  // 原時間控制部分，為省空間已移到上一層統一控制，但可讀性變低
  // while(true){
  //   if( millis()-starttime > ((delay_time + next_beat_time)* 1000) ){
  //     break;
  //   }else{
      setAllRainbowPixels(type,rainbowStartPos);
      local_timer = millis();  while( (millis()-local_timer)<10 );  // equal function : delay(10);
      rainbowStartPos += posAdd; 
  //   }
  // }
}


// 多顏色循環飛出
void ColorsShootOut(byte speed){  
  byte delayTime; 
  switch(speed){
    case SLOW:
      delayTime = 160;  //不可超過255(單位為byte)
      break;
    case MID:
      delayTime = 80;
      break;
    case FAST:
      delayTime = 40;
      break;
    case VERYFAST:
      delayTime = 20;
      break;
  }  

  for(byte color=0; color<6; color++){
    shootColorPos = shootColorPos + 1;
    if( shootColorPos > 5){
      shootColorPos = shootColorPos - 6;
    }
    ShootOutCore(shootColorPos, delayTime);
  }
}





// get that pixel's rgb value
// void printRGBValue(byte position){
//   int r = (pixels.getPixelColor(position) >> 16) & 0xFF;
//   int g = (pixels.getPixelColor(position) >>  8) & 0xFF;
//   int b = (pixels.getPixelColor(position) >>  0) & 0xFF;
//   Serial.print(r);Serial.print(" ");
//   Serial.print(g);Serial.print(" ");
//   Serial.println(b);
// }
