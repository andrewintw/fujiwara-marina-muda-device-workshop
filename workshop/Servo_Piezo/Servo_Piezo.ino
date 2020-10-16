#include <Servo.h>
Servo myservo;
int pos = 0;
const int threshold = 10;
int sensorReading = 0;
int ledState = LOW;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  myservo.attach(9);
}

void loop() {
  sensorReading = analogRead(A0);
  if (sensorReading >= threshold) {
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("Knock!");
    for (pos = 0; pos <= 90; pos += 1) {
      myservo.write(pos);
      delay(15);
    }
    {
      delay(2000);
    }
    for (pos = 90; pos >= 0; pos -= 1) {
      myservo.write(pos);
      delay(15);
    }
    {
      delay(2000);
    }
  }
  else {
    digitalWrite(LED_BUILTIN, LOW);
    for (pos = 0; pos <= 0; pos += 1) {
      myservo.write(pos);
      delay(15);
    }
  }
}
