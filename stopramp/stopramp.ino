#include <Stepper.h>
int const led = 7;
int const ledLOW = 6;
// 2048:한바퀴(360도), 1024:반바퀴(180도)...
const int stepsPerRevolution = 512; 
// 모터 드라이브에 연결된 핀 IN4, IN2, IN3, IN1
Stepper myStepper(stepsPerRevolution,11,9,10,8);           
void setup() {
  pinMode(led, OUTPUT);
  pinMode(ledLOW, OUTPUT);
  digitalWrite(ledLOW,LOW);
  digitalWrite(led,HIGH);
  myStepper.setSpeed(14); 
}
void loop() {
  // 시계 반대 방향으로 한바퀴 회전
  myStepper.step(stepsPerRevolution);
  delay(500);
  myStepper.step(stepsPerRevolution);
  delay(500);
  myStepper.step(stepsPerRevolution);
  delay(500);
  myStepper.step(stepsPerRevolution);
  delay(500);
  // 시계 방향으로 한바퀴 회전
  myStepper.step(-stepsPerRevolution);
  delay(500);
  myStepper.step(-stepsPerRevolution);
  delay(500);
  myStepper.step(-stepsPerRevolution);
  delay(500);
  myStepper.step(-stepsPerRevolution);
  delay(500);
}


