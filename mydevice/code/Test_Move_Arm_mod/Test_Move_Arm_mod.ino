#include <Servo.h>

Servo ServoShoulder; // pin6
Servo ServoForeArm;  // pin5

void setup() {
  ServoShoulder.attach(6);
  ServoForeArm.attach(5);

  Serial.begin(9600);
  delay(1000);
  ServoForeArm.write(120);
  delay(1000);
  ServoShoulder.write(150);
  delay(1000);
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

void loop() {
  Serial.println("1: shoulder up");
  moveServo(ServoShoulder, 150, 120, 90);
  Serial.println("2: arm down");
  moveServo(ServoForeArm,  120, 160, 90);
  Serial.println("3: shoulder down");
  moveServo(ServoShoulder, 120, 150, 90);
  delay(2000);

  Serial.println("4: arm up");
  moveServo(ServoForeArm,  160, 140, 50);
  Serial.println("5: arm down");
  moveServo(ServoForeArm,  140, 160, 12);
  Serial.println("4: arm up");
  moveServo(ServoForeArm,  160, 140, 50);
  Serial.println("5: arm down");
  moveServo(ServoForeArm,  140, 160, 10);
  delay(2000);
  moveServo(ServoForeArm,  160, 120, 100);

}
