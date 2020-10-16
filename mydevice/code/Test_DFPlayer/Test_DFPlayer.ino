/*
  DFPlayer - A Mini MP3 Player For Arduino
  library created by [Angelo qiao](Angelo.qiao@dfrobot.com)
  Connection and Diagram: https://www.dfrobot.com/wiki/index.php/DFPlayer_Mini_SKU:DFR0299#Connection_Diagram

  SD:\\mp3\0001.mp3
  SD:\\mp3\0002.mp3
  SD:\\mp3\0003.mp3

  VCC: use ext. 5v power
  RX -- 1k ohm --> arduino TX (pin11) reduce noise
  SPK1: speaker+
  SPK2: speaker-

  if you cannot play mp3, try to re-format the whole SD card and only put 0001.mp3 in [SD]/mp3/ folder.
  if you got noise, use external 5v power for DFPlayer (major issue). Also, put 1k resistor between DFPlayer RX and MCU TX pins (minor issue).

*/

#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

void setup()
{
  mySoftwareSerial.begin(9600);
  Serial.begin(9600);

  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));

  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while (true) {
      delay(0); // Code to compatible with ESP8266 watch dog.
    }
  }
  Serial.println(F("DFPlayer Mini online."));
  delay(3000);
  myDFPlayer.volume(25);  // set volume value. from 0 to 30
  myDFPlayer.play(2);     // play mp3/0002.mp3
}

void loop()
{
}
