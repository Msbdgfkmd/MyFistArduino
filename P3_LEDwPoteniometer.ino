const int RledPin = 3;

void setup() {
  
  Serial.begin(9600);
  pinMode (RledPin, OUTPUT);
}

void loop() {
  
  int sensorValue = analogRead(A0);
  
  Serial.println(sensorValue);
  if (sensorValue > 500){
    digitalWrite(RledPin, LOW);
  }
  else {
    digitalWrite(RledPin, HIGH);
  }
  delay(1);  // delay in between reads for stability
}
