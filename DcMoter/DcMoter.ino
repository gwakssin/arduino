//모터A 컨트롤
int IN1=10;
int IN2=9;
int Spin= 6; 

 
void setup() {
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  
  pinMode(Spin,OUTPUT);
}
 
void loop() {
  bothMotorStart();
  delay(3000);
  
  stopAllMotor();
  delay(3000);
}
 
//모터A,B 정회전
void bothMotorStart()
{
    analogWrite(Spin,150);
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    
}
 
//모터A,B Stop
void stopAllMotor()
{
    analogWrite(Spin,0);
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    
}
 
