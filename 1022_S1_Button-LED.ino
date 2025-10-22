const int buttonPin = 2; // the number of the pushbutton pin
const int RledPin = 9; // the number of the R pin
const int GledPin = 10; // the number of the G pin
const int BledPin = 11; // the number of the B pin

int buttonState = 0;

bool ButtonPressed = false;

void setup() {
  pinMode (RledPin, OUTPUT); 
  pinMode (GledPin, OUTPUT); 
  pinMode (BledPin, OUTPUT);
  pinMode (buttonPin, INPUT);
}

void loop() {
// read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

//   if (buttonState == HIGH) {
//     analogWrite(RledPin, 255);
//     analogWrite(GledPin, 255);
//     analogWrite(BledPin, 255);
//   } else {
//     analogWrite(RledPin, 0);
//     analogWrite(GledPin, 0);
//     analogWrite(BledPin, 0);
//   }
// }
  if (buttonState == HIGH) {
    setRGBLEDColor(0, 0, 0);
  } else {
    setRGBLEDColor(255, 255, 255);
  }
}

void setRGBLEDColor(int r, int g, int b){
    analogWrite(RledPin, r);
    analogWrite(GledPin, g);
    analogWrite(BledPin, b);
}

