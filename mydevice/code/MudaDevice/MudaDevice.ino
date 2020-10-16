#include <Servo.h>
#include <Arduino.h>
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

const int switchBtn = 4;
const int pizeoThreshold = 10;
const int pizeoPin = A0;

const long loopInterval = 50;
unsigned long previousMillis = 0;

#define SWITCH_ON   LOW
#define SWITCH_OFF  HIGH

int swst = SWITCH_OFF;

int pizeoReading = 0;
int knockCounter = 0;

Servo ServoShoulder; // pin6
Servo ServoForeArm;  // pin5
Servo ServoHead;     // pin9

SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

void initServoPos() {
  ServoForeArm.write(120);
  delay(1000);
  ServoShoulder.write(150);
  delay(1000);
  ServoHead.write(80);
  delay(1000);
}

void setup() {
  pinMode(switchBtn, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  ServoShoulder.attach(6);
  ServoForeArm.attach(5);
  ServoHead.attach(9);
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
  initServoPos();
}

void moveServo(Servo &servo, int startPos, int endPos, int delayTime) {
  int pos = 0;
  if (startPos < endPos) {
    for (pos = startPos; pos <= endPos; pos += 1) {
      servo.write(pos);
      delay(delayTime);
    }
  }
  else
  {
    for (pos = startPos; pos >= endPos; pos -= 1) {
      servo.write(pos);
      delay(delayTime);
    }
  }
}

void turnHead(int mode) {
  if (mode == 1) {
    Serial.println("move> Turn head");
    moveServo(ServoHead, 80, 150, 100);
  } else {
    Serial.println("move> Turn head back");
    moveServo(ServoHead, 150, 80, 100);
  }
}

void moveHand(int mode) {
  if (mode == 1) {
    Serial.println("move> shoulder up");
    moveServo(ServoShoulder, 150, 120, 90);
    Serial.println("move> arm down");
    moveServo(ServoForeArm,  120, 160, 90);
    Serial.println("move> shoulder down");
    moveServo(ServoShoulder, 120, 150, 90);
    delay(2000);

    Serial.println("move> arm up");
    moveServo(ServoForeArm,  160, 140, 50);
    Serial.println("move> arm down");
    moveServo(ServoForeArm,  140, 160, 12);
    Serial.println("move> arm up");
    moveServo(ServoForeArm,  160, 140, 50);
    Serial.println("move> arm down");
    moveServo(ServoForeArm,  140, 160, 10);
  } else {
    Serial.println("move> arm up (back to orig pos.)");
    moveServo(ServoForeArm,  160, 120, 100);
  }
}

void moveHandDemo() {
  Serial.println("move> shoulder up");
  moveServo(ServoShoulder, 150, 120, 90);
  Serial.println("move> arm down");
  moveServo(ServoForeArm,  120, 160, 90);
  Serial.println("move> shoulder down");
  moveServo(ServoShoulder, 120, 150, 90);
  playSound(30, 2);

  while (true) {
    Serial.println("move> arm up");
    moveServo(ServoForeArm,  160, 140, 50);
    Serial.println("move> arm down");
    moveServo(ServoForeArm,  140, 160, 12);
    Serial.println("move> arm up");
    moveServo(ServoForeArm,  160, 140, 50);
    Serial.println("move> arm down");
    moveServo(ServoForeArm,  140, 160, 10);
    swst = digitalRead(switchBtn);
    if (swst == SWITCH_ON) {
      Serial.println("move> arm up (back to orig pos.)");
      moveServo(ServoForeArm,  160, 120, 100);
      break;
    }
  }
}


void playSound(int volume, int mp3Index) {
  myDFPlayer.volume(volume);  // 0 to 30
  myDFPlayer.play(mp3Index);  // play mp3/0002.mp3
}

void doDaijoubuDesu() {
  Serial.println("Daijouubu Desu!");
  moveHand(1);
  turnHead(1);
  playSound(30, 2);
  moveHand(0);
  //playSound(30, 2);
  turnHead(0);
}

void doRun() {
  if (analogRead(A0) >= pizeoThreshold) {
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("Knock!");
    knockCounter = knockCounter + 1;
    delay(100);
    if (knockCounter >= 5) {
      doDaijoubuDesu();
      knockCounter = 0;
    }
  }  else {
    digitalWrite(LED_BUILTIN, LOW);
  }
}

void doDemo() {
  //Serial.println("Daijouubu Desu! (Demo Mode)");
  moveHandDemo();
}

void loop() {
  swst = digitalRead(switchBtn);
  if (swst == SWITCH_ON) {
    //Serial.println("running mode");
    doRun();
  } else {
    //Serial.println("testing mode");
    doDemo();
  }
}
