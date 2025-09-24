void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(3, OUTPUT); //R
  pinMode(4, OUTPUT); //G
  pinMode(5, OUTPUT); //B
}

// the loop function runs over and over again forever
void loop() {

  //red
  digitalWrite(3, LOW); 
  digitalWrite(4, HIGH); 
  digitalWrite(5, HIGH);  
  delay(100);        
  // turn off           
  digitalWrite(3, HIGH); 
  digitalWrite(4, HIGH); 
  digitalWrite(5, HIGH);  
  delay(100); 
  //blue
  digitalWrite(3, HIGH); 
  digitalWrite(4, HIGH); 
  digitalWrite(5, LOW);  
  delay(100);        
  // turn off           
  digitalWrite(3, HIGH); 
  digitalWrite(4, HIGH); 
  digitalWrite(5, HIGH);  
  delay(100);     
  //red
  digitalWrite(3, LOW); 
  digitalWrite(4, HIGH); 
  digitalWrite(5, HIGH);  
  delay(100);        
  // turn off           
  digitalWrite(3, HIGH); 
  digitalWrite(4, HIGH); 
  digitalWrite(5, HIGH);  
  delay(100);          
}
