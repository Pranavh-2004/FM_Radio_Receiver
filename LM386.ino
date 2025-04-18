// Generate a square wave tone on pin 9
void setup() {
  pinMode(6, OUTPUT);
}

void loop() {
  tone(6, 1000);  // 1kHz tone
  delay(2000);    // Play for 2 seconds
  noTone(6);
  delay(1000);    // Pause for 1 second
}

