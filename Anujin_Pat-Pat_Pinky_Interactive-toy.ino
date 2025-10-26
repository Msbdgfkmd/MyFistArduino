const int buttonPin = 2;
const int RledPin = 11;
const int GledPin = 10;
const int BledPin = 9;

int mood = 0;  // start sad (0 = blue, 10 = purple, 20 = green)
bool buttonPressed = false;
unsigned long lastTouch = 0;
unsigned long lastReduce = 0;

const long unTouchInterval = 5000;  // 5 sec before mood goes down
const long reducedInterval = 1000;  // lose 1 point per second after that

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(RledPin, OUTPUT);
  pinMode(GledPin, OUTPUT);
  pinMode(BledPin, OUTPUT);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  // When button pressed, mood increases
  if (buttonState == HIGH && !buttonPressed) {
    mood++;
    if (mood > 20) mood = 20;  // max happy = GREEN
    buttonPressed = true;
    lastTouch = millis();
  }

  if (buttonState == LOW) {
    buttonPressed = false;
  }

  // If no press for 5 sec = mood decreases
  if (millis() - lastTouch > unTouchInterval) {
    if (millis() - lastReduce > reducedInterval) {
      mood--;
      if (mood < 0) mood = 0;  // min sad = BLUE
      lastReduce = millis();
    }
  }

  // Update LED color based on mood
  showColor(mood);
}

void showColor(int mood) {
  int r = 0;
  int g = 0;
  int b = 0;

if (mood <= 10) {
  int step = mood; 
  r = 255 - (step * 15);  
  g = 100 + (step * 15);  
  b = 0;                  
} else {
  int step = mood - 10;   
  r = 0;                 
  g = 255 - (step * 25);   
  b = step * 25;      
}

  if (r > 255) r = 255;
  if (g > 255) g = 255;
  if (b > 255) b = 255;
  if (r < 0) r = 0;
  if (g < 0) g = 0;
  if (b < 0) b = 0;

  analogWrite(RledPin, r);
  analogWrite(GledPin, g);
  analogWrite(BledPin, b);
}
