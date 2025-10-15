int Photoresistor = 2;
int led = 9;
// the setup routine runs once when you press reset:
void setup() {
// initialize serial communication at 9600 bits per second
Serial.begin(9600);
// make the pushbutton's pin an input:
pinMode(Photoresistor, INPUT);
pinMode(led, OUTPUT);
}
// the loop routine runs over and over again forever:
void loop() {
// read the input pin:
int PhotoresistorState = digitalRead(Photoresistor);
digitalWrite(led, PhotoresistorState);
// print out the state of the button:
Serial.println(PhotoresistorState);
delay(1);} // delay in between reads for stability