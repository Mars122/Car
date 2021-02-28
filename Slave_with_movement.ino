/*
  433 MHz RF Module Receiver Demonstration 1
  RF-Rcv-Demo-1.ino
  Demonstrates 433 MHz RF Receiver Module
  Use with Transmitter Demonstration 1

  DroneBot Workshop 2018
  https://dronebotworkshop.com
*/

// Include RadioHead Amplitude Shift Keying Library
#include <RH_ASK.h>
// Include dependant SPI Library
#include <SPI.h>

// Create Amplitude Shift Keying Object
RH_ASK rf_driver;
int attention;
char attentionmsg;
String str_out;
String str_attention;
long val;
long val2;
// Define the pin numbers
int motorPin1 = 6;
int motorPin2 = 7;
int motorPin3 = 8;
int motorPin4 = 9;
void setup()
{
     pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
    Serial.begin(38400);
    long val;
    long val2;
  // Initialize ASK Object
  rf_driver.init();
  // Setup Serial Monitor
  Serial.begin(9600);
}

void loop()
{
  // Set buffer to size of expected message
  byte buf[1];
  byte buflen = sizeof(buf);
  // Check if received packet is correct size
  if (rf_driver.recv(buf, &buflen))
  {

    // Message received with valid checksum
    Serial.print("Message Received: ");
    Serial.println((char*)buf);
    //str_out = String((char*)buf);
    //  str_attention=str_out;
  }
if (buf > 40) {
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
}

else {
      digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW); 
}

  //Serial.println(str_attention);


  //  attentionmsg[i]=char(buf[i]);
  //attentionmsg=char(buf);
  //attention=atoi(attentionmsg);


}
