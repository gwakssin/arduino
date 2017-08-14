#include <SPI.h>
#include <nRF24L01p.h>
  
nRF24L01p verici(7,8);//CSN,CE
  
void setup(){
 delay(150);
 Serial.begin(115200);
 SPI.begin();
 SPI.setBitOrder(MSBFIRST);
 verici.channel(90);
 verici.TXaddress("kontrol");
 verici.init();
}
  
String message;
  
void loop(){
 if(Serial.available()>0){
 char character=Serial.read();
 if(character=='\n'){
 verici.txPL(message);
 verici.send(SLOW);
 message="";
 }else{
 message+=character;
 }
 }
}

