#define IRRX_GND 3
#define IRRX_PWR 4
#define IRRX_OUT 2
#define IRLEDPIN A3

byte bosePwr[4]   = {0xBA, 0xA0, 0x4c, 0xb3};
long time;
byte counter;
bool flag;
byte message[4];

void setup() {
  attachInterrupt(0,interrupt,CHANGE);
  pinMode(IRRX_GND,OUTPUT);
  pinMode(IRRX_PWR,OUTPUT);
  pinMode(IRLEDPIN,OUTPUT);
  digitalWrite(IRRX_GND,LOW);
  digitalWrite(IRRX_PWR,HIGH);
  Serial.begin(9600);
  Serial.println("Ready");
}

void loop() {
  long timer = micros() - time;
  if(flag){
    flag = 0;
    if(timer > 1400 && timer < 2000){ //Logic 1 addBit(1); }else if(timer > 450 && timer < 650){ //Logic 0 addBit(0); }else if(timer > 4000 && timer < 5000){ //START clearBits(); }else if(timer > 2000 && timer < 2500){ //REPEAT sendRpt(); clearBits(); } } if(counter >= 32){ //Recieve 32 or more bits successfully
    printBits();
    delay(50);
    sendCommand(message);
    clearBits();
  }

  if(timer > 10000 && counter > 0 && counter < 32){ //10ms Timeout
    Serial.println("Incomplete code");
    clearBits();
  }
}

void addBit(byte data){
  byte block = counter / 8;
  byte spot = counter % 8;
  byte mask = data << spot;
  message[block] |= mask;
  counter++;
}

void clearBits(){
  counter = 0;
  for(int i = 0; i < 4; i++){
    message[i] = 0;
  }
}

void printBits(){
  for(int i = 0; i < 4; i++){ byte low = message[i] & B00001111; byte high = (message[i] & B11110000) >> 4;
    Serial.print(high,HEX);
    Serial.print(low,HEX);
    Serial.print(" ");
  }
  Serial.println();
}

void interrupt(){
  if(!digitalRead(IRRX_OUT)) flag = 1;
  else time = micros();
}

void sendCommand(byte command[]) {
  sendHeader();
  for(int i = 0; i < 4; i++){
    sendByte(command[i]);
  }
  sendFooter();
}

void sendByte(byte data){
  byte mask = B00000001;
  for(int j = 0; j < 8; j++){
    if(mask & data) send1();
    else send0();
    mask <<= 1; } } void send1(){ send38KHz(560); delayMicroseconds(1690); } void send0(){ send38KHz(560); delayMicroseconds(560); } void sendHeader(){ send38KHz(9000); delayMicroseconds(4500); } void sendFooter(){ send38KHz(560); } void sendRpt(){ send38KHz(9000); delayMicroseconds(2250); send38KHz(2250); } void send38KHz(long microsecs) { while (microsecs > 0) {
    // 38 kHz -> 26 uSec (Duty cycle = 1/3)
    digitalWrite(IRLEDPIN, HIGH); //takes ~ 5uSec
    delayMicroseconds(6);
    digitalWrite(IRLEDPIN, LOW); //takes ~ 5uSec
    delayMicroseconds(10);
    microsecs -= 26;
  }
}
