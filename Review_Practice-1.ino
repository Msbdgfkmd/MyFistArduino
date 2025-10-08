const int buttonPin = 2; // the number of the pushbutton pin
const int RledPin = 3; // the number of the R pin
const int GledPin = 4; // the number of the G pin
const int BledPin = 5; // the number of the B pin

// variables will change:
int buttonState = 0; 
int ledcolor = 0;
bool ButtonPressed = false;
unsigned long previousMillis = 0;
const long interval = 1000;
bool ledColorOrder = true;

void setup() {
  pinMode (buttonPin, INPUT);

  pinMode (RledPin, OUTPUT); 
  pinMode (GledPin, OUTPUT); 
  pinMode (BledPin, OUTPUT);
}

void loop() {

  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH && !ButtonPressed) {
    ledColorOrder = !ledColorOrder;
    ButtonPressed = true;
  }
  if(buttonState == LOW && ButtonPressed) {
    ButtonPressed = false;
  }

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
    if (ledColorOrder == true) {
      ledcolor = ledcolor + 1;
      if(ledcolor > 3) 
      ledcolor = 0;
    } else 
      ledcolor = ledcolor - 1;
      if(ledcolor < 0)
      ledcolor = 3;
    }
  
  if (ledcolor == 0){
// RED
    digitalWrite(RledPin, LOW);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
  } else 
  if (ledcolor == 1){
//Green 
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, HIGH);
  }
//BLUE
    else if (ledcolor == 2){
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, LOW);
  }
    else if (ledcolor == 3){
    digitalWrite(RledPin, LOW);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, LOW);
  }
}

