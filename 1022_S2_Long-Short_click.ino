const int buttonPin = 2; // the number of the pushbutton pin
const int RledPin = 9; // the number of the R pin
const int GledPin = 10; // the number of the G pin
const int BledPin = 11; // the number of the B pin

int buttonState = 0;
bool buttonPressed = false;
unsigned long pressingTime = 0;
const int longPressInterval = 2000;

void setup() {
  pinMode (RledPin, OUTPUT); 
  pinMode (GledPin, OUTPUT); 
  pinMode (BledPin, OUTPUT);
  pinMode (buttonPin, INPUT);
  // Serial.begin(9600);
}

void loop() {
  checkButton();
}

void checkButton() {
  buttonState = digitalRead(buttonPin);

  if(buttonState == HIGH && !buttonPressed){
    pressingTime = millis();
    buttonPressed = true;
  } 
  if(buttonState == LOW && buttonPressed){
    unsigned long currentTime = millis();
    if (currentTime - pressingTime < longPressInterval) {
    // short
    // Serial.println("short");
  } else {
    // long
    // Serial.println("long");
  }
  buttonPressed = false;
  }
}





