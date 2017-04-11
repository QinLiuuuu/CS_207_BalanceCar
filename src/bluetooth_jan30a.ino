*/
#include <SoftwareSerial.h>

#define tx A0
#define rx A1

unsigned char front=0;
unsigned char back=0;
unsigned char turnl=0;
unsigned char turnr=0;
unsigned char spinl=0;
unsigned char spinr=0;


  SoftwareSerial softSerial(tx,rx);//build softSerial，set TXpin and RXpin

void setup() {

softSerial.begin(9600);
Serial.begin(9600);
}

void loop() {
    while (softSerial.available())                                   
    switch (softSerial.read())                                 
    {
      case 0x01: front = 1;   break;                         
      case 0x02: back = 1;   break;                       
      case 0x03: turnl = 1;   break;                          
      case 0x04: turnr = 1;   break;                          
      case 0x05: spinl = 1;   break;                       
      case 0x06: spinr = 1;   break;                       
      case 0x07: turnl = 0; turnr = 0;  front = 0; back = 0; spinl = 0; spinr = 0;  break;                    
      case 0x08: spinl = 0; spinr = 0;  front = 0; back = 0;  turnl = 0; turnr = 0;  break;                  
      case 0x09: front = 0; back = 0; turnl = 0; turnr = 0; spinl = 0; spinr = 0;  break;       
      default: front = 0; back = 0; turnl = 0; turnr = 0; spinl = 0; spinr = 0; break;
    }

//      delay(100);
      if(front==1)
      {
         Serial.print("\t");
      Serial.println("front");
      
      } 
      else if(back==1)
      {   
        Serial.print("\t");  
      Serial.println("back");
     
      }   
      else if(turnl==1)
      {
         Serial.print("\t");
      Serial.println("left");
       
      }
      else
      {
         Serial.println("wait for the button");
      }

}

