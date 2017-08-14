/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>
Servo left_servo;
Servo right_servo;
Servo hand_servo;
Servo body_servo;
//Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

// comple Select 

//#define serial
//#define _servo_runing
#define _move_forwold

int servo_name = 0;
int pos = 0;

void setup() { 
  Serial.begin(9600);
}

void loop() {
  #ifdef serial     
     delay(100);
     if (Serial.available() > 0)
      {
        servo_attach();
        char input = Serial.read();
        input_servo(input);     
      }
         
  #endif
 
  #ifdef _move_forwold     
     delay(100);   
     if (Serial.available() > 0)
      {
        servo_attach();
        char move_input = Serial.read();
        move_forwold(move_input);      
      }
     
  #endif
 
  #ifdef _servo_runing 
   servo_attach();
   Serial.println("servo_runing?");
     for (int i = 0;  i<5; i++){
      servo_runing(i);
     delay(2000);
     }
     
  #endif    
}

void servo_runing( int servo_name ){
 switch(servo_name){
  case 0:
       for (pos = 80; pos >= 20; pos -= 1) { // goes from 180 degrees to 0 degrees
            body_servo.write(pos);              // tell servo to go to position in variable 'pos'
            delay(15);                       // waits 15ms for the servo to reach the position
       }
       for (pos = 20; pos <= 160; pos += 1) { // goes from 0 degrees to 180 degrees        
           body_servo.write(pos);              // tell servo to go to position in variable 'pos'
           delay(15);                       // waits 15ms for the servo to reach the position
        }
       for (pos = 160; pos >= 80; pos -= 1) { // goes from 180 degrees to 0 degrees
            body_servo.write(pos);              // tell servo to go to position in variable 'pos'
            delay(15);                       // waits 15ms for the servo to reach the position
       }
      
       break;
  case 1:
       for (pos = 50; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees        
           right_servo.write(pos);              // tell servo to go to position in variable 'pos'
           delay(15);           
        }
       for (pos = 90; pos >= 50; pos -= 1) { // goes from 180 degrees to 0 degrees
            right_servo.write(pos);              // tell servo to go to position in variable 'pos'
            delay(15);                       // waits 15ms for the servo to reach the position
       } 
       break;     
       
  case 2:
       for (pos = 15; pos <= 110; pos += 1) { // goes from 0 degrees to 180 degrees        
           left_servo.write(pos);              // tell servo to go to position in variable 'pos'
           delay(15);                       // waits 15ms for the servo to reach the position
        }
       for (pos = 110; pos >= 15; pos -= 1) { // goes from 180 degrees to 0 degrees
            left_servo.write(pos);              // tell servo to go to position in variable 'pos'
            delay(15);                       // waits 15ms for the servo to reach the position
       } 
       break;
                       
  case 3:
       for (pos = 25; pos <= 44; pos += 1) { // goes from 0 degrees to 180 degrees        
           hand_servo.write(pos);              // tell servo to go to position in variable 'pos'
           delay(15);                       // waits 15ms for the servo to reach the position
        }
       for (pos = 44; pos >= 25; pos -= 1) { // goes from 180 degrees to 0 degrees
            hand_servo.write(pos);              // tell servo to go to position in variable 'pos'
            delay(15);                       // waits 15ms for the servo to reach the position
       } 
       break;
  case 4:
       servo_detach();
       break;
  default:
       left_servo.write(5);
       right_servo.write(50);
       hand_servo.write(44);
       body_servo.write(85);
       break;
  }
  
} 


void input_servo(char key){
  Serial.print("input Key: ");
  Serial.println(key);
  switch(key){
   case 'b':
       for (pos = 20; pos <= 160; pos += 1) { // goes from 0 degrees to 180 degrees        
           body_servo.write(pos);              // tell servo to go to position in variable 'pos'
           delay(15);                       // waits 15ms for the servo to reach the position
        }
       for (pos = 160; pos >= 20; pos -= 1) { // goes from 180 degrees to 0 degrees
            body_servo.write(pos);              // tell servo to go to position in variable 'pos'
            delay(15);                       // waits 15ms for the servo to reach the position
       }
       body_servo.write(84);
       break;
       
  case 'l':
  
       
       for (pos = 15; pos <= 110; pos += 1) { // goes from 0 degrees to 180 degrees        
           left_servo.write(pos);              // tell servo to go to position in variable 'pos'
           delay(15);                       // waits 15ms for the servo to reach the position
        }
       for (pos = 110; pos >= 15; pos -= 1) { // goes from 180 degrees to 0 degrees
            left_servo.write(pos);              // tell servo to go to position in variable 'pos'
            delay(15);                       // waits 15ms for the servo to reach the position
       } 
       break;
       
  case 'r':
       for (pos = 50; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees        
           right_servo.write(pos);              // tell servo to go to position in variable 'pos'
           delay(15);                       // waits 15ms for the servo to reach the position
        }
       for (pos = 90; pos >= 50; pos -= 1) { // goes from 180 degrees to 0 degrees
            right_servo.write(pos);              // tell servo to go to position in variable 'pos'
            delay(15);                       // waits 15ms for the servo to reach the position
       } 
       break;
                
   case 'h':
       for (pos = 44; pos >= 25; pos -= 1) { // goes from 180 degrees to 0 degrees
            hand_servo.write(pos);              // tell servo to go to position in variable 'pos'
            delay(15);                       // waits 15ms for the servo to reach the position
       } 
        
       for (pos = 25; pos <= 44; pos += 1) { // goes from 0 degrees to 180 degrees        
           hand_servo.write(pos);              // tell servo to go to position in variable 'pos'
           delay(15);                       // waits 15ms for the servo to reach the position
        }
       
       break;
  
   case '9':
       servo_detach();
       break;         
  default:
       left_servo.write(0);
       right_servo.write(50);
       hand_servo.write(44);
       body_servo.write(85);
       break;
  }
}

void move_forwold(char movekey){
 
 Serial.println(pos);
 switch(movekey){   
  case 'f':
       pos = pos + 5;
       right_servo.write(pos);
       left_servo.write(pos);     
       break;
  case 'b':
       pos = pos - 5;
       right_servo.write(pos);
       left_servo.write(pos);
       break;

  case 'u':
       pos = pos + 5;                
       left_servo.write(pos);
       
       if (pos > 110 ) pos= 110;
       break; 
        
  case 'd':
       pos = pos - 5;      
       left_servo.write(pos);
       if (pos < 15)  pos = 15;
       break;
  case 'r':
       pos = pos - 5;                
       right_servo.write(pos);
       if (pos > 90 ) pos= 90;
       break; 
  case '9':
       servo_detach();
       break;                  
 }
 
} 

void servo_attach(){
    left_servo.attach(9);  // attaches the servo on pin 9,11,6  to the servo object
    right_servo.attach(10);
    hand_servo.attach(6);
    body_servo.attach(11);
  
    left_servo.write(15);
    right_servo.write(5);
    hand_servo.write(40);
    body_servo.write(85);
}

void servo_detach(){
  left_servo.detach();  // attaches the servo on pin 9,11,6  to the servo object
  right_servo.detach();
  hand_servo.detach();
  body_servo.detach();
}

