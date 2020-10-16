#include <Servo.h>

Servo ServoShoulder; // pin6
Servo ServoArm;      // pin5


int pos = 0;

void setup() {
  ServoShoulder.attach(6);
  ServoArm.attach(5);

  delay(1000);
  ServoArm.write(120);
  delay(1000);
  ServoShoulder.write(150);
  delay(1000);
}

void loop() {
  for (pos = 150; pos >= 100; pos -= 1) {
    ServoShoulder.write(pos);
    delay(100);
  }

  for (pos = 120; pos <= 170; pos += 1) {
    ServoArm.write(pos);
    delay(100);
  }

  for (pos = 100; pos <= 150; pos += 1) {
    ServoShoulder.write(pos);
    delay(100);
  }

  for (pos = 170; pos >= 120; pos -= 1) {
    ServoArm.write(pos);
    delay(100);
  }
}
