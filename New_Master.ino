
/*
  433 MHz RF Module Transmitter Demonstration 1
  RF-Xmit-Demo-1.ino
  Demonstrates 433 MHz RF Transmitter Module
  Use with Receiver Demonstration 1

  DroneBot Workshop 2018
  https://dronebotworkshop.com
*/

// Include RadioHead Amplitude Shift Keying Library
#include <RH_ASK.h>
// Include dependant SPI Library
#include <SPI.h>
#include <Brain.h>

float attention; 
char attentionchar[2]; 

Brain brain(Serial);




// Create Amplitude Shift Keying Object
RH_ASK rf_driver;


void setup()
{
  // Initialize ASK Object
  rf_driver.init();

  Serial.begin(9600);


}

void loop()
{

  if (brain.update()) {
    Serial.println(brain.readErrors());

 attention=brain.readCSV(); 
 itoa(attention,attentionchar,10); 
//debug begin
 Serial.print("Sensor Integer: ");
 Serial.print(attention);
 Serial.print("Sensor CharMsg:");
 Serial.print(attentionchar);
 Serial.println(" "); 
 delay (100); 

//debug end

    rf_driver.send((uint8_t *)attentionchar, strlen(attentionchar)); //transmits the data
    rf_driver.waitPacketSent(); // Wait until the whole message is gone
    delay(500);
  }
}
