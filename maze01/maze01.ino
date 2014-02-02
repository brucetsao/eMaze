#include <Wire.h>
#include <ArduinoNunchuk.h>
#define BAUDRATE 9600
#define servo1 9
#define servo2 10

ArduinoNunchuk nunchuk = ArduinoNunchuk();


void setup()
{
  Serial.begin(BAUDRATE);
  pinMode(servo1,OUTPUT);
  pinMode(servo2,OUTPUT);
  nunchuk.init();
}


void loop()
{
  if (getzButtonPressed())
  {
      nunchuk.update();
    Serial.print("x pos is : ");
    Serial.print(getJoysticX());
    Serial.print("  y pos is : ");
    Serial.print(getJoysticY());
    Serial.println(' ');
  }
  
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
  








