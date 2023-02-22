/* 注意： 對於每個樣式，checkIsAllPixelSame ＆ fromStyleSetPixel 都要設定*/
void checkIsAllPixelSame(byte light_style){
  if(light_style < 50){
    isAllPixelSame = true;       
  }else{
    isAllPixelSame = false;     
  }
}

void changeStyle(byte light_style){
  if(isAllPixelSame){
    for(byte i=0; i<REALPIXELSNUM; i++){
      fromStyleSetPixel(i, light_style);
    }
  }else{
    fromStyleSetStrip(light_style);    
  }
}





// 簡單樣式(單色)，可多次呼叫單燈珠函式設定
void fromStyleSetPixel(byte position, byte light_style){
  switch(light_style){
    case RED:
      pixels.setPixelColor(position,255,0,0);
      break;      
    case YELLOW:
      pixels.setPixelColor(position,255,255,0);
      break;      
    case GREEN:
      pixels.setPixelColor(position,0,255,0);
      break;      
    case SKYBLUE:
      pixels.setPixelColor(position,0,255,255);
      break;
    case BLUE:
      pixels.setPixelColor(position,0,0,255);
      break;      
    case PURPLE:
      pixels.setPixelColor(position,255,0,255);
      break;
    case BLACK:
      pixels.setPixelColor(position,0,0,0);
      break;
    // case WHITE:
    //   pixels.setPixelColor(position,180,180,254);   //255,255,255有色偏
    //   break;
    
  }
}


// complex style (Need to control loop, delay time and color.)
void fromStyleSetStrip(byte light_style){
  // 統一時間控制，若每個函式自行控制太佔空間，只能犧牲可讀性換取空間
  while(true){
    if( millis()-starttime > ((delay_time + next_beat_time)* 1000) ){
      pixels.setBrightness(255);
      break;
    }else{
      
      switch(light_style){ 
        case 50:
          fire(FIRENORNAL,NIGHT);
          break;
        case 51:
          fire(FIRENORNAL,DAWN);
          break;
        case 52:
          fire(FIRENORNAL,NOON);
          break;
        
        case 53:
          fire(FIREPURPLE,NIGHT);
          break;
        case 54:
          fire(FIREPURPLE,DAWN);
          break;
        case 55:
          fire(FIREPURPLE,NOON);
          break;
        
        case 56:
          fire(FIRESKYBLUE,NIGHT);
          break;
        case 57:
          fire(FIRESKYBLUE,DAWN);
          break;
        case 58:
          fire(FIRESKYBLUE,NOON);
          break;





        case 60:
          rainbow(RAINBOWSIMILAR,SLOW);
          break;
        case 61:
          rainbow(RAINBOWSIMILAR,MID);      
          break;
        case 62:
          rainbow(RAINBOWSIMILAR,FAST);
          break;
        case 63:
          rainbow(RAINBOWSIMILAR,VERYFAST);
          break;
        
        case 64:
          rainbow(RAINBOWDISTRIBUTED,SLOW);
          break;
        case 65:
          rainbow(RAINBOWDISTRIBUTED,MID);
          break;
        case 66:
          rainbow(RAINBOWDISTRIBUTED,FAST);
          break;
        case 67:
          rainbow(RAINBOWDISTRIBUTED,VERYFAST);
          break;


        case 70:
          ColorsShootOut(SLOW);
          break;
        case 71:
          ColorsShootOut(MID);
          break;
        case 72:
          ColorsShootOut(FAST);
          break;
        case 73:
          ColorsShootOut(VERYFAST);
          break;
        
        default:
          break;
      }

    }
  }  
}






/*  函式說明
changeStyle (統一呼叫此函式)
    |-- fromStyleSetPixel 利用迴圈遍歷更改每一個
    |-- fromStyleSetStrip 因為會一直變動，迴圈遍歷已包裝在深層函數中
*/