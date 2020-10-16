const int threshold = 10;
int sensorReading = 0;
int ledState = LOW;
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  sensorReading = analogRead(A0);
  if (sensorReading >= threshold) {
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("Knock!");
    delay(100);
  }
  else {
    digitalWrite(LED_BUILTIN, LOW);
  }
}
