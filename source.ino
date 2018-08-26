#include<SoftwareSerial.h>

#define pin 3 // Relay pin

SoftwareSerial bluetooth(10,11); // RX , TX
char data=0;

void setup(){
  bluetooth.begin(9600);
  pinMode(pin,OUTPUT);
  bluetooth.print("AT+PSWD=\r\n"); // Set bluetooth password to nothing
}

void loop(){
  if(bluetooth.available()){
    data=bluetooth.read();
    if(data=='H') // If the cmd that came from serial is 'H' then switch relay to On
      digitalWrite(pin,HIGH);
    else if(data =='L') // If the cmd that came from serial is 'L' then switch relay to Off
      digitalWrite(pin,LOW);      
  }
  delay(100);
}
