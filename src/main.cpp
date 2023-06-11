/*
This code enables sending and receiving data using the RS-485 standard with RS-485 shields, like the MKR 485 Shield.
This library supports the Maxim Integrated MAX3157 and equivalent chipsets.
For more infortion about this code, please refer to url=http://www.arduino.cc/en/Reference/ArduinoRS485

*/

#include<main.h>

int counter = 0; // Counter for the sender function
/* ================================================================================================= */
void sender(){
  RS485.beginTransmission();
  RS485.print("hello ");
  RS485.println(counter);
  RS485.endTransmission();

  counter++;
  delay(1000);
}
/* ================================================================================================= */
void receiver(){
  // enable reception, can be disabled with: RS485.noReceive();
  RS485.receive();
   if (RS485.available()) {
    Serial.write(RS485.read());
  }
  delay(1000);
}
/* ================================================================================================= */
void setup() {
  Serial.begin(9600);
  while (!Serial);
   delay (1000);
  Serial.println ("RS485 Sender/Receiver");
  RS485.begin(9600);
}

void loop() { 
  /*  To send call */ 
  sender();
  /* To resceive call */
  //receiver();
}