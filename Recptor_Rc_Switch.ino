/*
  Simple example for receiving
  
  http://code.google.com/p/rc-switch/
  
  Need help? http://forum.ardumote.com
*/

#include <RCSwitch.h>


int led = 13;
RCSwitch mySwitch = RCSwitch();
#define pressed1 9   //defines incoming data set by user which is transmitted
#define pressed2 5
#define pressed3 
#define pressed4
#define pressed5
#define pressed6
#define pressed7

void setup() {
  pinMode (led, OUTPUT);
  Serial.begin(9600);
 mySwitch.enableReceive(0);  // Receiver on interrupt 0 => that is pin #2 pinMode(led,OUTPUT);
}
void loop() {


  //digitalWrite(led,HIGH);
  if (mySwitch.available()) {
    
    int value = mySwitch.getReceivedValue();
    
    if (value == 0) {
      Serial.print("Unknown encoding");
    } else {
      //  used for checking received data      
         /*Serial.print("Received ");       
          Serial.print( mySwitch.getReceivedValue() );      
          Serial.print(" / ");     
          Serial.print( mySwitch.getReceivedBitlength() );      
          Serial.print("bit ");      
          Serial.print("Protocol: ");     
          Serial.println( mySwitch.getReceivedProtocol() );*/    }
if (mySwitch.getReceivedValue())


{
    process();



}


mySwitch.resetAvailable();


Serial.println("  ");  
}
  //digitalWrite(led,LOW);
  
  delay(100);
  
}
void process()
{
  unsigned long res = mySwitch.getReceivedValue();

  switch (res){
    case 0:
     Serial.println("");
     digitalWrite(led,LOW);
     break;
    case 1:
     Serial.println("B1 ");
     digitalWrite(led,HIGH);
     break;
    case 2:
     Serial.println("  B2 ");
     break;    
    case 3:
     Serial.println("B1 B2 ");
     break;
     case 4:
     Serial.println("      B3 ");
     break;
     case 5:
     Serial.println("B1    B3 ");
     break;
     case 6:
     Serial.println("   B2 B3");
     break;
     case 7:
     Serial.println("B1 B2 B3");
     break;
     
  }
}

