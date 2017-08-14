void setup() {
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  
}
 
void loop() 
{
      
 
        //최대속도로 정회전
        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
        analogWrite(6, 255);
        
        
 
}

