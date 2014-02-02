#include <Wire.h>
#include <ArduinoNunchuk.h>
#include <Servo.h> 
#define BAUDRATE 9600
#define servo1 9
#define servo2 10
Servo myservoX;  // create servo object to control a servo 
Servo myservoY;  // create servo object to control a servo 

ArduinoNunchuk nunchuk = ArduinoNunchuk();


void setup()
{
  Serial.begin(BAUDRATE);
//------ init Servo --------
  pinMode(servo1,OUTPUT);
  pinMode(servo2,OUTPUT);
  myservoX.attach(9);  // attaches the servo on pin 9 to the servo object 
  myservoY.attach(10);  // attaches the servo on pin 10 to the servo object 
//----init nunchuk--------
  nunchuk.init();
}


void loop()
{
  if (getzButtonPressed())
  {
    int posx ;
    int posy ;
      posx = getJoysticX() ;
      posy = getJoysticY() ;
      myservoX.write(posx);
      myservoY.write(posy);
    Serial.print("x pos is : ");
    Serial.print(posx);
    Serial.print("  y pos is : ");
    Serial.print(posy);
    Serial.println(' ');
    
  }
  delay(150);
}


int getJoysticX()
{ 
  int tmp ;
    nunchuk.update();
    tmp = nunchuk.analogX;
  return map(tmp, 34,235, 1,180);
}  
 
int getJoysticY()
{ 
  int tmp ;
    nunchuk.update();
    tmp = nunchuk.analogY;
  return map(tmp, 225,16, 1,180);
}  
 

int getzButtonPressed()
{ 
    nunchuk.update();
    if (nunchuk.zButton == 1 )
       {
         return true ;
       }
       else
       {
         return false ;
       }
}  
 
int getcButtonPressed()
{ 
    nunchuk.update();
    if (nunchuk.cButton == 1 )
       {
         return true ;
       }
       else
       {
         return false ;
       }
}  
 
void showdata()
{
  nunchuk.update();
  Serial.print(nunchuk.analogX, DEC);
  Serial.print(' ');
  Serial.print(nunchuk.analogY, DEC);
  Serial.print(' ');
  Serial.print(nunchuk.accelX, DEC);
  Serial.print(' ');
  Serial.print(nunchuk.accelY, DEC);
  Serial.print(' ');
  Serial.print(nunchuk.accelZ, DEC);
  Serial.print(' ');
  Serial.print(nunchuk.zButton, DEC);
  Serial.print(' ');
  Serial.println(nunchuk.cButton, DEC);

}
  








