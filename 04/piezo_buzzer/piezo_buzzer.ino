// Pins
int buzzerPin = 6;

void setup() {

  // Setup pins
  pinMode(buzzerPin, OUTPUT);
  
}

void loop() {
  
  // Low frequency
  tone(buzzerPin, 100); 
  delay(2000);
  noTone(buzzerPin);
  delay(2000);

  // Medium frequency
  tone(buzzerPin, 500); 
  delay(2000);
  noTone(buzzerPin);
  delay(2000);

  // High frequency
  tone(buzzerPin, 2000); 
  delay(2000);
  noTone(buzzerPin);
  delay(2000);
  
}



