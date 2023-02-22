// 火焰設定核心，每個燈珠都隨機設定顏色
// 複雜雙色版本
void setAllFirePixels(byte type, byte brightness){
  uint8_t r,g,b;
  int16_t r1,g1,b1;

  for (uint8_t i=0; i<REALPIXELSNUM; i++){
    uint8_t flicker = random(30,80);
    if (type == FIRENORNAL){
      r = 230;  g = 90;  b = 30;    // 一般黃色
    }else if(type == FIREPURPLE){
      r = 158;  g = 8;  b = 148;    // 紫色
    }else if(type == FIRESKYBLUE){
      r = 8;  g = 158;  b = 148;    // 天藍色
    }
    
    r1 = r-flicker; g1 = g-flicker; b1 = b-flicker;
    if(g1<0) g1=5;  if(r1<0) r1=5;  if(b1<0) b1=5; 
    pixels.setPixelColor(i,r1,g1,b1);

    switch (brightness){
      case NIGHT:
        pixels.setBrightness(random(5,30));   //30,150
        break;
      case DAWN:
        pixels.setBrightness(random(40,100));   //80,200  random(91,170)
        break;
      case NOON:
        pixels.setBrightness(random(200,240));  //130,250
        break;
    }
  }
}

// 簡易單色版本
// void setAllFirePixels(byte type, byte brightness){
//   uint8_t r1=230 ,g1=90;
//   for (uint8_t i=0; i<NUMPIXELS; i++){
//     uint8_t flicker = random(30,80);
//     pixels.setPixelColor(i, r1-flicker, g1-flicker, 5);
//     pixels.setBrightness(random(130,250));
//   }
// }


/*
彩虹函式，須自行設定時間＆呼叫show
pixels.rainbow(first_hue,reps,saturation,brightness,gammify);

參數說明
first_hue = 0,(default) --> 設定起始顏色，可選值：0~65535
reps = 1, (default) --> 燈珠範圍內重複幾圈
saturation = 255,(default) --> 透明度，可選值：0~255，越靠近 0 越接近白色
brightness = 255,(default) --> 亮度，可選值：0~255
gammify = true,(default) --> 若是true，則對顏色應用伽瑪校正以獲得更好的外觀，可選值：true/false
*/
void setAllRainbowPixels(byte type, uint16_t startPos){
  if(type == RAINBOWSIMILAR){
    pixels.rainbow(startPos,-1,255,255,true);  // all simillar but different 
  }else if(type == RAINBOWDISTRIBUTED){
    pixels.rainbow(startPos,-10,255,255,true);  //rainbow equally distributed
  }
  pixels.show();   
}



// 單燈珠顏色從內向外飛出
void ShootOutCore(byte style, byte delayTime){
  unsigned long local_timer = 0;
  pixels.clear();  pixels.show();
  for(byte position=0; position < REALPIXELSNUM; position++){
    fromStyleSetPixel(position, style);     //color
    fromStyleSetPixel(position-1, BLACK);   //black
    pixels.show();

    // delay
    local_timer = millis();      
    while( 
      (millis()-local_timer)<delayTime &&   // 還沒到delay時間
      !(millis()-starttime > ((delay_time + next_beat_time)* 1000))   //還沒超過這個樣式的時間
    );
    /* 此函式因為有 delay，導致有時執行時間會太久。
    在樣式間隔時間太短時，無法跳到上層確定是否要切換樣式，程式就會出錯 */
    
  }
} 




