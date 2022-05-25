#include <dma_led.h>
#include <dma_key.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(37 ,36,35, 26, 27, 28, 29); //設定LCD腳位
 
DMA_KEY key = DMA_KEY(); 
DMA_LED led = DMA_LED();

//宣告字元陣列
char msgs[11][16] = 
{  "press sw03 to", //0
   "start",         //1
   "Finish",       //2
   "REACTION GAME^^",  //3
   "GAME1", //4
   "GAME2", //5 
   "GAME3", //6
   "        win ",//7
   "you         ",//8
   "       lose ",//9
};

//把關卡的燈全部關掉，已顯示輸(贏)的紅(綠)燈
void turnoff(){
  for (int i=0;i<3;i++){
    led.LedOff(1,i);
    led.LedOff(2,i);
    led.LedOff(3,i);
  }
}

//贏家的lcd、led顯示
int win(){
        lcd.clear();
        lcd.setCursor(1,0);
        lcd.print(msgs[8]);
        lcd.setCursor(2,3);
        lcd.print(msgs[7]);
        delay(50); 
        led.LedToggle(1,1);
        led.LedToggle(2,1);
        led.LedToggle(3,1);  
        delay(500);
        led.LedOff(1,1);
        led.LedOff(2,1);
        led.LedOff(3,1);
        delay(500);           
}

//輸家的lcd、led顯示
int lose(){
        lcd.clear();
        lcd.setCursor(1,0);
        lcd.print(msgs[8]);
        lcd.setCursor(2,3);
        lcd.print(msgs[9]);
        delay(50);
        led.LedOff(1,0);
        led.LedOff(2,0);
        led.LedOff(3,0);
        delay(500); 
        led.LedToggle(1,0);
        led.LedToggle(2,0);
        led.LedToggle(3,0);  
        delay(500);        
}

//關卡1
void game1(int i){
    switch (i) { 
    case 1:
        led.LedOff(1,0);
        led.LedToggle(3,1);
        delay(100); 
        break;        
    case 2:
        led.LedOff(3,1); 
        led.LedToggle(2,1);
        led.LedToggle(2,0);
        delay(100); 
        break;        
    case 3:        
        led.LedOff(2,1);
        led.LedOff(2,0); 
        led.LedToggle(1,0);
        delay(100);
        break; 
    }
}

//關卡2
void game2(int i){
    switch (i) { 
    case 1:
        led.LedOff(2,0);
        led.LedOff(2,1);
        led.LedOff(2,2);
        led.LedToggle(2,0);
        delay(50); 
        break;       
    case 2:
        led.LedOff(2,0); 
        led.LedToggle(2,1);
        led.LedToggle(2,0);
        delay(50); 
        break;        
    case 3:        
        led.LedOff(2,0);
        led.LedOff(2,1);
        led.LedToggle(2,1);
        delay(50);
        break; 
    case 4:        
        led.LedOff(2,1);
        led.LedToggle(2,2);
        delay(50);
        break;
    case 5:        
        led.LedOff(2,2);
        led.LedToggle(2,0);
        led.LedToggle(2,2);
        delay(50);
        break;
    case 6:        
        led.LedOff(2,0);
        led.LedOff(2,2);
        led.LedToggle(2,0);
        led.LedToggle(2,1);
        led.LedToggle(2,2);
        delay(50);
        break;      
         
    }
}

//關卡3    
void game3(int i){
    switch (i) { 
    case 1:
        led.LedOff(3,0);
        led.LedOff(3,1);
        led.LedOff(3,2); 
        led.LedToggle(1,0);
        delay(50); 
        break;       
    case 2:
        led.LedOff(1,0); 
        led.LedToggle(1,1);
        led.LedToggle(1,0);
        led.LedToggle(2,1);
        led.LedToggle(2,0);
        delay(50); 
        break;        
    case 3:        
        led.LedOff(1,1);
        led.LedOff(1,0);
        led.LedOff(2,1);
        led.LedOff(2,0);
        led.LedToggle(1,1);
        led.LedToggle(2,1);
        led.LedToggle(3,1);  
        delay(50);
        break; 
    case 4:        
        led.LedOff(1,1);
        led.LedOff(2,1);
        led.LedOff(3,1);
        led.LedToggle(1,2);
        led.LedToggle(2,2);
        led.LedToggle(3,2); 
        delay(50);
        break;
    case 5:        
        led.LedOff(1,2);
        led.LedOff(2,2);
        led.LedOff(3,2);
        led.LedToggle(2,0);
        led.LedToggle(2,2);
        led.LedToggle(3,0);
        led.LedToggle(3,2);   
        delay(50);
        break;
    case 6:        
        led.LedOff(2,0);
        led.LedOff(2,2);
        led.LedOff(3,0);
        led.LedOff(3,2); 
        led.LedToggle(3,0);
        led.LedToggle(3,1);
        led.LedToggle(3,2);  
        delay(50);
        break;               
    }
}

//清除LCD螢幕  
int initlcd(){
    lcd.clear();
    led.LedInit();  
    key.KeyInit();
}

//起始畫面
int start(){
    initlcd();
    lcd.setCursor(1,0);
    lcd.print(msgs[0]);
    lcd.setCursor(2,1);
    lcd.print(msgs[1]);
}

void setup() 
{    
    lcd.begin(16,2);
    initlcd();
    lcd.clear();
    lcd.print(msgs[3]);
    delay(2000);
    start();
    Serial.begin(9600);
}

int c=random(1000,2000);
int i=random(1,10);
int deadlinetime = 0;
int j=0;
int win();
int lose();

void loop()
{   
   Serial.print(millis());
   int detect=0;
   if(key.CheckKey(3) == 1){
      initlcd();
      while(1){
          lcd.setCursor(1,0);
          lcd.print(msgs[4]);     
          int d=millis()%100;
    
          //開始關卡1
          while(1){          
              j++;          
              if(j>=d) 
                  break;
                  i=random(1,4);
                  game1(i);
                  Serial.print(j);
                  Serial.print("   ");
                  Serial.println(d);
          }
          break;
      }
      //測驗反應時間的程式碼       
      int starttime1=millis();
      int endtime1;
      int d=250;//2點多秒內要按下一號鍵
      while(1){        
      j++;          
            if(j>=d) 
                break;
                Serial.print(j);
                Serial.print("   ");
                Serial.println(d);
                if(key.CheckKey(1) == 1) {
                    detect++;
                    endtime1=millis();
                    break;
                }
      }
      //測驗失敗後，輸家的亮燈顯示
      while(detect==0){
      turnoff();
      lose();
      } 
      //藉由detect變數等於1，讓系統跑下個關卡，所以關卡二的縮牌以while(detect==1)為原本初始點
      //此處為關卡1到關卡2，lcd顯示玩家反應的時間
      initlcd();
      while(detect==1){
          lcd.print((endtime1-starttime1)/1000);
          lcd.print(".");
          lcd.print((endtime1-starttime1)%1000);
          lcd.print(" sec");
          Serial.println(endtime1);
          Serial.println(starttime1);
          delay(2000);     
     
              //開始關卡2
              int d=millis()%1000;
              int j=0;            
              while(1){          
                  j++;          
                  if(j>=d) 
                      break;
                          i=random(1,6);
                          game2(i);
                          Serial.print(j);
                          Serial.print("   ");
                          Serial.println(d);
              }
              break;
      }
      //之後以下為關卡2的測驗程序，縮排要回歸到while(detect==1)的位置        
      initlcd();
      int starttime3=millis();
      int endtime3;
      int d2=250;//2點多秒內要按下一號鍵
      int j=0;
      while(1){        
          j++;          
          if(j>=d2) 
              break;
              Serial.print(j);
              Serial.print("   ");
              Serial.println(d2);
              if(key.CheckKey(1) == 1) {
                  detect++;
                  endtime3=millis();
                  break;
              }
      }          
      
      //輸家的亮燈顯示
      while(detect==1){
          turnoff();
          lose();
      }
      //此處為關卡2到關卡3，lcd顯示玩家反應的時間
      initlcd();
      while(detect==2){
          lcd.print((endtime3-starttime3)/1000);
          lcd.print(".");
          lcd.print((endtime3-starttime3)%1000);
          lcd.print(" sec");
          Serial.println(endtime3);
          Serial.println(starttime3);
          delay(2000);
              lcd.clear();
              lcd.setCursor(1,0);
              lcd.print(msgs[6]);     

              //跟上述關卡2切換的時候一樣，現在位於while(detect==2)的迴圈裏面
              //開始關卡3        
              int d=millis()%100;
              int j=0;            
              while(1){          
                  j++;          
                  if(j>=d) 
                      break;
                          i=random(1,6);
                          game3(i);
                          Serial.print(j);
                          Serial.print("   ");
                          Serial.println(d);
                  
              }
              break;
      }

      //最後一輪遊戲的測驗程序
      initlcd();
      int starttime4=millis();
      int endtime4;
      int d3=250;//2點多秒內要按下一號鍵
      while(1){        
          j++;          
          if(j>=d3) 
              break;
              Serial.print(j);
              Serial.print("   ");
              Serial.println(d3);
                  if(key.CheckKey(1) == 1) {
                      detect++;
                      endtime4=millis();
                          break;
                  }
      }          
      
      //輸家的亮燈顯示
      while(detect==2){
          turnoff();
          lose();
      }
      
      //以下到尾都是勝利者的畫面
      //此處為關卡3到遊戲勝利，lcd顯示玩家反應的時間
      initlcd();     
      while(detect==3){
          lcd.print((endtime4-starttime4)/1000);
          lcd.print(".");
          lcd.print((endtime4-starttime4)%1000);
          lcd.print(" sec");
          Serial.println(endtime4);
          Serial.println(starttime4);
          delay(2000);
              break;            
      }
          initlcd();
          while(detect==3){
              turnoff();  
              win();          
          }
      
   }
} 
