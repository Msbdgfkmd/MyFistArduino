const int buttonPin = 2; // the number of the pushbutton pin
const int RledPin = 9; // the number of the R pin
const int GledPin = 10; // the number of the G pin
const int BledPin = 11; // the number of the B pin

int buttonState = 0;
bool buttonPressed = false;
unsigned long pressingTime = 0;
const int longPressInterval = 2000;

int lightNum = 0;
int RLightColor = 0;
int GLightColor = 0;
int BLightColor = 0;

void setup() {
  pinMode (RledPin, OUTPUT); 
  pinMode (GledPin, OUTPUT); 
  pinMode (BledPin, OUTPUT);
  pinMode (buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  checkButton();
  setRGBLEDColor(RLightColor, GLightColor, BLightColor);
}

void setRGBLEDColor(int r, int g, int b){
  analogWrite(RledPin, r);
  analogWrite(GledPin, g);
  analogWrite(BledPin, b);
}

void checkButton() {
  
  buttonState = digitalRead(buttonPin);

  if(buttonState == LOW && !buttonPressed){
    pressingTime = millis();
    buttonPressed = true;
  }

  if(buttonState == HIGH && buttonPressed){
    unsigned long currentTime = millis();
    if (currentTime - pressingTime < longPressInterval) {
    // short
    Serial.println("short");
    changeLEDColor();
    }
    else {
    // long
      Serial.println("long");
    }
    buttonPressed = false;
  }
}

void changeLEDColor() {
  lightNum = lightNum + 1;
  if(lightNum >= 5) 
  lightNum = 0;

  if(lightNum == 0) {
    // white
    RLightColor = 0;
    GLightColor = 0;
    BLightColor = 0;
  }
  if(lightNum == 1) {
    // red
    RLightColor = 0;
    GLightColor = 255;
    BLightColor = 255;
  }
  if(lightNum == 2) {
    // green
    RLightColor = 255;
    GLightColor = 0;
    BLightColor = 255;
  }
  if(lightNum == 3) {
    // blue
    RLightColor = 255;
    GLightColor = 255;
    BLightColor = 0;
  }
  if(lightNum == 4) {
    // yellow
    RLightColor = 0;
    GLightColor = 0;
    BLightColor = 255;
  }
}





