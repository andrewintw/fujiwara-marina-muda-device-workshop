#include <Servo.h>
Servo myservo;

#define servo_pos_default 30
#define servo_pos_max 150
#define sensor_value_min 150
#define sensor_value_max 360

int pos;

void setup() {
  Serial.begin(9600);
  myservo.attach(9);
}
void loop() {
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);

  pos = constrain(sensorValue, sensor_value_min, sensor_value_max);
  pos = map(pos, sensor_value_min, sensor_value_max, servo_pos_default,
            servo_pos_max);
  myservo.write(pos);
  delay(100);
}
