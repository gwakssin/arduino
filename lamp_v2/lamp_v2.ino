int motorDirPin = 5;      // Motor direction connected to digital pin 2
int motorSpeedPin = 3;    // Motor speed connected to analog pin 3

void setup()
{
  pinMode(motorDirPin, OUTPUT);       // sets the pin as output
  pinMode(motorSpeedPin, OUTPUT);     // sets the pin as output

  digitalWrite(motorDirPin, LOW);     // sets the default dir to be forward
  digitalWrite(motorSpeedPin, LOW);   // sets the default speed to be off
}

void loop()
{
  // Set the motor direction to forward
  digitalWrite(motorDirPin, LOW);     

  // Ramp the motor speed up
  //analogWrite(motorSpeedPin, 0);    // Min speed forward (motor off)
  //delay(3000);  
  analogWrite(motorSpeedPin, 45);   
  //delay(50);  
  //analogWrite(motorSpeedPin, 127);   
  //delay(50); 
  //analogWrite(motorSpeedPin, 191);   
  //delay(50); 
  //analogWrite(motorSpeedPin, 255);   // Max speed forward
  //delay(50); 

  // Ramp the motor speed down
  //analogWrite(motorSpeedPin, 191);   
  //delay(50);  
  //analogWrite(motorSpeedPin, 127);   
  //delay(50);  
  //analogWrite(motorSpeedPin, 63);   
  //delay(50); 
  //analogWrite(motorSpeedPin, 0);     // Min speed forward (motor off)
  //delay(50); 


  
}
