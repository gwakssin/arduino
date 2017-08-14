int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor

int moterPinA = 7;
int moterPinB = 8;
int PwmPin = 6;

unsigned long inputTime;

void setup() {
  // declare the ledPin as an OUTPUT:
   Serial.begin(9600);  
   pinMode(moterPinA, OUTPUT);
   pinMode(moterPinB, OUTPUT);
   waterstop();
}

void loop() {
  // read the value from the sensor:
  //sensorValue = map(analogRead(sensorPin),0,1023,0,7);    
  sensorValue = analogRead(sensorPin);
  
  delay(1000);          
  Serial.print("sensor = " );                       
  Serial.println(sensorValue); 
  if (sensorValue < 4 ){
        waterInput();
        delay(60000);       
        waterstop(); 
              
   }
  waterstop();
}

void waterInput(){ 
   Serial.println("waterInput"); 
   digitalWrite(moterPinA, HIGH);
   digitalWrite(moterPinB, LOW);
   analogWrite(PwmPin, 255); 
}

void waterstop(){  
   Serial.println("waterstop");
   digitalWrite(moterPinA, HIGH);
   digitalWrite(moterPinB, LOW);
   analogWrite(PwmPin, 0); 
}
