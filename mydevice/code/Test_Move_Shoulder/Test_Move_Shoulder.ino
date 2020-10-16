#include <Servo.h>

Servo ServoShoulder; // pin6

int pos = 0;

void setup() {
  ServoShoulder.attach(6);
}

void loop() {

  for (pos = 150; pos >= 70; pos -= 1) {
    ServoShoulder.write(pos);
    delay(100);
  }

  for (pos = 70; pos <= 150; pos += 1) {
    ServoShoulder.write(pos);
    delay(100);
  }

  

}
