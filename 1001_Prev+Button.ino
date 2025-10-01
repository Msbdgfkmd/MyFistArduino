const int pushButton = 2;
const int ledPin = 3;

int buttonState = 0;

void setup() {
  // pinMode(9, OUTPUT);
  // pinMode(10, OUTPUT);
  // pinMode(11, OUTPUT);

  pinMode(pushButton, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {

  buttonState = digitalRead(pushButton);

  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }  

  // // green
  // digitalWrite(9, HIGH);
  // digitalWrite(10, LOW);
  // digitalWrite(11, HIGH); 
  // delay(5000);
  // // turn off
  // digitalWrite(9, HIGH);
  // digitalWrite(10, HIGH);
  // digitalWrite(11, HIGH);
  // delay(100);


  // // yellow
  // digitalWrite(9, LOW);
  // digitalWrite(10, LOW);
  // digitalWrite(11, HIGH); 
  // delay(1000);
  // // turn off
  // digitalWrite(9, HIGH);
  // digitalWrite(10, HIGH);
  // digitalWrite(11, HIGH);
  // delay(100);


  // // red
  // digitalWrite(9, LOW);
  // digitalWrite(10, HIGH);
  // digitalWrite(11, HIGH); 
  // delay(8000); 
  // // turn off
  // digitalWrite(9, HIGH);
  // digitalWrite(10, HIGH);
  // digitalWrite(11, HIGH);
  // delay(100);

  
}
