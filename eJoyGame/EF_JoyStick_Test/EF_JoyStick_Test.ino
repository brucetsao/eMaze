/*********************************************************************
**  Device: Joystick                                                **
**  File:   EF_Joystick_Test.c                                      **
**								    **
**  Created by ElecFreaks Robi.W /10 June 2011                      **
**                                                                  **
**  Description:                                                    **
**  This file is a sample code for your reference.                  **
**                                                                  **
**  Copyright (C) 2011 ElecFreaks Corp.                     	    **
*********************************************************************/



int FirstShotX , FirstShotY;

void setup()
{
  for(int i=0; i<19; i++)
  { 
    pinMode(i, INPUT);
    digitalWrite(i, 1);
  }
  
  Serial.begin(9600); 
  FirstShotX = 0;
  FirstShotY = 0;
  
}

void loop(){
  
  int i, someInt, flag = 0;
  for(i=1; i<11; i++)
  {
    someInt = digitalRead(i);


    if(someInt == 0)
    {  
      flag =1;
      break;
    }
   }
   if(flag == 1)
   {    
     switch(i)
     {
       case 4: Serial.println("--------> Button A"); break;
       case 5: Serial.println("--------> Button B"); break;
       case 6: Serial.println("--------> Button C"); break;
       case 7: Serial.println("--------> Button D"); break;
       case 8: Serial.println("--------> Button E"); break;
       case 9: Serial.println("--------> Button F"); break;
       case 10: Serial.println("--------> Button KEY"); break;
       default: break;
     }

     flag=0;
          Serial.print("KEY code is :") ;
     Serial.println(i) ;
   }
   
   int sensorValue = analogRead(A0);
   if(FirstShotX == 0)
   {  
     FirstShotX = sensorValue;
     Serial.print("FirstShotX = ");
     Serial.println(FirstShotX);
   }
   
   Serial.print("X = ");
   Serial.println(sensorValue - FirstShotX);
   
   sensorValue = analogRead(A1);
   if(FirstShotY == 0)
   {  
     FirstShotY = sensorValue;
     Serial.print("FirstShotY = ");
     Serial.println(FirstShotY);
   }
   Serial.print("Y = ");
   Serial.println(sensorValue - FirstShotY);
   
   delay(200);
}
