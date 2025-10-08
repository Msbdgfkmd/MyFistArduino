const int RledPin = 9; 
const int GledPin = 10;    
const int BledPin = 11;         
int brightness = 0; 
int fadeAmount = 5; 
int ledColor = 0; 

void setup() {
  pinMode(RledPin, OUTPUT);
  pinMode(GledPin, OUTPUT);
  pinMode(BledPin, OUTPUT);
}

void loop() {
  
  if(ledColor == 0){
    analogWrite(RledPin, brightness);
    analogWrite(GledPin, 255);
    analogWrite(BledPin, 255);
  }

  if(ledColor == 1){
    analogWrite(RledPin, 255);
    analogWrite(GledPin, brightness);
    analogWrite(BledPin, 255);
  }

  if(ledColor == 2){
    analogWrite(RledPin, 255);
    analogWrite(GledPin, 255);
    analogWrite(BledPin, brightness);
  }

  brightness = brightness + fadeAmount;

  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
    if (brightness >= 255){
      ledColor = ledColor + 1;
      if (ledColor > 2)
      ledColor = 0;
    }
  }
  delay(30);
}
