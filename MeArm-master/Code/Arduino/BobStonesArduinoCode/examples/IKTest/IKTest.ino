/* meArm IK test - York Hackspace May 2014
 * Test applying Nick Moriarty's Inverse Kinematics solver
 * to Phenoptix' meArm robot arm, to walk a specified path.
 *
 * Pins:
 * Arduino    Base   Shoulder  Elbow    Gripper
 *    GND    Brown     Brown   Brown     Brown
 *     5V      Red       Red     Red       Red
 *     11    Yellow
 *     10             Yellow
 *      9                     Yellow
 *      6                               Yellow
 */
#include "meArm.h"
#include <Servo.h>
int currentValue = 0;
int values[] = {0,0};

int basePin = 11;     //5;
int shoulderPin =  10; //10;
int elbowPin = 9 ;//9;
int gripperPin = 6;    //  6;

meArm arm;

void setup() {
  Serial.begin(9600);
  arm.begin(basePin, shoulderPin, elbowPin, gripperPin);
}

void loop() {
  int i=0;
  /*arm.isReachable(0,0,0);
  if(Serial.available()){
    int incomingValue = Serial.read();
    
    values[currentValue] = incomingValue;

    currentValue++;
    if(currentValue > 1){
      currentValue = 0;
    }
    Serial.print("x = "); Serial.println(values[0]);
    Serial.print("y = "); Serial.println(values[1]);
    arm.gotoPoint(values[0],values[1],50);
  }  
  //Clap - so it's obvious we're at this part of the routine
  //arm.openGripper();
  //arm.closeGripper();
  //arm.openGripper();
  //arm.closeGripper();
  //arm.openGripper();
  
  delay(500);
  //Go up and left to grab something
  arm.gotoPoint(-80,100,140); 
  //arm.closeGripper();
  //Go down, forward and right to drop it
  arm.gotoPoint(70,200,10);
  //arm.openGripper();
  
  //Back to start position
  
  //arm.gotoPoint(0,100,50);
  */
  arm.gotoPoint(10,180,100);
  Serial.println("0,90,5");
  delay(5000);
 
  
  arm.end(basePin, shoulderPin, elbowPin, gripperPin);
}
