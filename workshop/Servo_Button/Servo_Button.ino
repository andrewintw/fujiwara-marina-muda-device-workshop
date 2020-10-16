#include <Servo.h>
Servo myservo;
int pos = 0;

const int buttonPin = 2;
int buttonState = 0;

void setup() {
  myservo.attach(9);
  pinMode(buttonPin, INPUT);
}
void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    for (pos = 0; pos <= 0; pos += 1) {
      myservo.write(pos);
    }
  }
  else {
    for (pos = 0; pos <= 180; pos += 1) {
      myservo.write(pos);
      delay(15);
    }
    {
      delay(1000);
    }
    for (pos = 180; pos >= 0; pos -= 1) {
      myservo.write(pos);
      delay(15);
    }
  }
}
