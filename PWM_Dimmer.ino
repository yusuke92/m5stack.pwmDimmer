#include <M5Stack.h>

int pwmChannel = 1;
int ledPin = 17;
int ledState = 125;
int ledONOFF = 0;
int i = 0;
int DspState;

void setup() {
  // put your setup code here, to run once:
  M5.begin();
  ledcSetup(pwmChannel, 1000, 8);
  ledcAttachPin(ledPin, pwmChannel);
  pinMode(ledPin, OUTPUT);
  M5.Lcd.fillScreen(WHITE);
  M5.Lcd.setTextColor(BLACK);
  M5.Lcd.setCursor(10,100);
  M5.Lcd.setTextSize(4);
  M5.Lcd.drawString("PWM Dimmer",10,100, 1);
}

void loop() {
  // put your main code here, to run repeatedly:

 //---------------dimming up--------------------
  if(M5.BtnA.isPressed()){
    //M5.Lcd.clear();
    M5.Lcd.fillScreen(WHITE);
    ledState += 2;
    if(ledState > 240)
      ledState = 240;
      ledcWrite(pwmChannel, ledState);
      delay(0);
      i = 0;
       DspState = (ledState*10) / 24;
       M5.Lcd.drawString("Dim",10,100, 1);
       M5.Lcd.drawNumber(DspState,100,100, 1);
       M5.Lcd.drawString("%",180,100, 1);
  }

 //--------------dimming down-------------------
  if(M5.BtnB.isPressed()){
   M5.Lcd.fillScreen(WHITE);
    ledState -=2;
    if(ledState < 15)
      ledState = 15;
      ledcWrite(pwmChannel, ledState);
      delay(0);
      i= 0;
       DspState = (ledState*10) / 24;
       M5.Lcd.drawString("Dim",10,100, 1);
       M5.Lcd.drawNumber(DspState,100,100, 1);
       M5.Lcd.drawString("%",180,100, 1);
    }
 //-----------------on and off-----------------
  if(M5.BtnC.isPressed()){
       M5.Lcd.fillScreen(WHITE);
    if(i == 0){
       M5.Lcd.fillScreen(WHITE);
      ledONOFF = 1;
      ledcWrite(pwmChannel, ledONOFF);
      delay(300);
      M5.Lcd.drawString("OFF",130,100, 1);
    }
    
    if(i == 1){
       M5.Lcd.fillScreen(WHITE);
      ledcWrite(pwmChannel, ledState);
      delay(300);
      M5.Lcd.drawString("ON",130,100, 1);  
    }
    
  i = !i;
  }
  M5.update();
}
