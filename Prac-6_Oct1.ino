const int buttonPin = 2; // the number of the pushbutton pin
const int RledPin = 3; // the number of the R pin
const int GledPin = 4; // the number of the G pin
const int BledPin = 5; // the number of the B pin

// variables will change:
int buttonState = 0; // variable for reading the pushbutton status
int ledcolor = 0;

bool ButtonPressed = false;

String currentcolor = "led";

void setup() {
// initialize the LED pin as an output: pinMode (RledPin, OUTPUT);
  pinMode (RledPin, OUTPUT); 
  pinMode (GledPin, OUTPUT); 
  pinMode (BledPin, OUTPUT);
  pinMode (buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
// read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  Serial.print("Current Color: ");
  Serial.println(currentcolor);

  if (buttonState == HIGH && !ButtonPressed) {
  ledcolor = ledcolor + 1;
  ButtonPressed = true;

  // delay (100);
  }

  if (buttonState == LOW && ButtonPressed) {
  ButtonPressed = false;
  }

  if (ledcolor == 0){
    currentcolor="LED off";
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
  }
  else if (ledcolor == 1) {
  // RED
    currentcolor="Red";
    digitalWrite(RledPin, LOW);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
  }
  else if(ledcolor == 2) {
  //Green
    currentcolor="Green";
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, HIGH);
  }
//BLUE
  else if(ledcolor == 3){
    currentcolor="Blue";
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, LOW);
  }
  else if(ledcolor == 4){
    currentcolor="Yellow";
    digitalWrite(RledPin, LOW);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, HIGH);
  }
//purple
  else if(ledcolor == 5){
    currentcolor="Purple";
    digitalWrite(RledPin, LOW);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, LOW);
}
//cyan
  else if (ledcolor == 6){
    currentcolor="Cyan";
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, LOW);
  }
//white
  else if(ledcolor == 7){
    currentcolor="White";
    digitalWrite(RledPin, LOW);
    digitalWrite (GledPin, LOW);
    digitalWrite(BledPin, LOW);
  }
  else if (ledcolor == 8){
    ledcolor = 0;
  }
}