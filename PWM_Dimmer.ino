#include <M5Stack.h>

int pwmChannel = 1;
int ledPin = 17;
int ledState = 125;
int ledONOFF = 0;
int i = 0;


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
  M5.Lcd.print("PWM Dimmer:)");
}

void loop() {
  // put your main code here, to run repeatedly:

 //---------------dimming up--------------------
  if(M5.BtnA.isPressed()){
    ledState += 2;
    if(ledState > 240)
      ledState = 240;
      ledcWrite(pwmChannel, ledState);
      delay(25);
      i = 0;
  }

 //--------------dimming down-------------------
  if(M5.BtnB.isPressed()){

    ledState -=2;
    if(ledState < 15)
      ledState = 15;
      ledcWrite(pwmChannel, ledState);
      delay(25);
      i= 0;

    }
 //-----------------on and off-----------------
  if(M5.BtnC.isPressed()){
    if(i == 0){
      ledONOFF = 1;
      ledcWrite(pwmChannel, ledONOFF);
      delay(300);
    }
    
    if(i == 1){
      ledcWrite(pwmChannel, ledState);
      delay(300);  
    }
    
  i = !i;
  }
  M5.update();
}
