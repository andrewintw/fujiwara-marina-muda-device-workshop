#include <Servo.h>

Servo myservo;
int pos = 0;

void setup() {
  myservo.attach(5);
  myservo.attach(6);
  myservo.attach(9);
  myservo.write(pos);
}

void loop() {
}
