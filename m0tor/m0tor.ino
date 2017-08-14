#define MOTOR 9
#define Motor 10
void setup()
{
  pinMode(MOTOR, OUTPUT);
  pinMode(Motor,OUTPUT);
 
}
void loop()
{
  //analogWrite(MOTOR,64);  //slow
  
  //delay(2000);
  analogWrite(MOTOR,128);  //medium
 // delay(2000);
  //analogWrite(MOTOR,255);  //fast
  //delay(2000);
  //digitalWrite(MOTOR,LOW);
  //digitalWrite(MOTOR,HIGH);
  digitalWrite(Motor,LOW);
  }

