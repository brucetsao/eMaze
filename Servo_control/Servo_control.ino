// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 
  
 Servo myservo;  // create servo object to control a servo 
                 // a maximum of eight servo objects can be created 
  
int pos = 0;    // variable to store the servo position 
int potpin = 0;  
int val;    


void setup() 
{ 
   myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
} 
  
  
void loop() 
{ 
   val = analogRead(potpin);      
   val = map(val, 0, 1023, 0, 179);     // scale it to use it with the servo (value between 0 and 180) 
    myservo.write(val);   
    delay(120);    
 }
