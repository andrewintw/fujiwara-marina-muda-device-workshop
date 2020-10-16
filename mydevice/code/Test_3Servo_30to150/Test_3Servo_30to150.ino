#include <Servo.h>

Servo myservo5;
Servo myservo6;
Servo myservo9;

int pos = 0;

void setup() {
  myservo5.attach(5);
  myservo6.attach(6);
  myservo9.attach(9);
}

void loop() {
  for (pos = 30; pos <= 150; pos += 1) {
    myservo5.write(pos);
    myservo6.write(pos);
    myservo9.write(pos);
    delay(100);
  }
  for (pos = 150; pos >= 30; pos -= 1) {
    myservo5.write(pos);
    myservo6.write(pos);
    myservo9.write(pos);
    delay(100);
  }
}
