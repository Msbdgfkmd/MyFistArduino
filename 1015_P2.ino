const int digitalInput = 2;

void setup() {
  Serial.begin(9600);
  pinMode(digitalInput, INPUT);
}

void loop() {
  int sensorValue = analogRead(A0);
  int digitalSensorValue = digitalRead(digitalInput);

  Serial.println(sensorValue);
  Serial.println(digitalSensorValue);
  delay(1);
}
