#include <Servo.h>

Servo ServoHead;     // pin9

void setup() {
  ServoHead.attach(9);

  Serial.begin(9600);
  delay(1000);
  ServoHead.write(80);
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
  Serial.println("1: Turn head");
  moveServo(ServoHead, 80, 150, 100);
  delay(3000);
  Serial.println("2: Turn head back");
  moveServo(ServoHead, 150, 80, 100);

}
