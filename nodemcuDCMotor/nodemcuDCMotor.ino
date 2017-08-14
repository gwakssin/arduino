#include <Wire.h> 
//#include <LiquidCrystal_I2C.h>

//LiquidCrystal_I2C lcd(0x27,16,2);

#define DIRA 0
#define PWMA 5
#define DIRB 2
#define PWMB 4



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println();
  Serial.println("Starting...");
  pinMode(PWMA,OUTPUT);
  pinMode(DIRA,OUTPUT);

  pinMode(PWMB,OUTPUT);
  pinMode(DIRB,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //front
    digitalWrite(DIRA,0);
    analogWrite(PWMA,1023);
    digitalWrite(DIRB,0);
    analogWrite(PWMB,1023);
    delay(3000);
  
   //left
    digitalWrite(DIRA,0);
    analogWrite(PWMA,1023);
    digitalWrite(DIRB,1);
    analogWrite(PWMB,1023);
    delay(400);
    Serial.println("front running");
       digitalWrite(DIRA,0);
       analogWrite(PWMA,1023);
       digitalWrite(DIRB,0);
       analogWrite(PWMB,1023);
       delay(3000);
   //right
    digitalWrite(DIRA,1);
    analogWrite(PWMA,1023);
    digitalWrite(DIRB,0);
    analogWrite(PWMB,1023);
    delay(400);
    digitalWrite(DIRA,0);
    analogWrite(PWMA,1023);
    digitalWrite(DIRB,0);
    analogWrite(PWMB,1023);
    delay(3000);
    //back 
    digitalWrite(DIRA,1);
    analogWrite(PWMA,1023);
    digitalWrite(DIRB,1);
    analogWrite(PWMB,1023);
    delay(3000); 
   
}
