
const int switchBtn = 4;

#define SWITCH_ON   LOW
#define SWITCH_OFF  HIGH

void setup() {
  pinMode(switchBtn, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  int swst = digitalRead(switchBtn);

  if (swst == SWITCH_ON) {
    Serial.println("running mode");
  } else {
    Serial.println("testing mode");
  }
  delay(1000);
}
