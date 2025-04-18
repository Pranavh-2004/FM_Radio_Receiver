#include <Wire.h>
#include <TEA5767.h>

TEA5767 radio;

const int potPin = A0;
float minFreq = 50.0;
float maxFreq = 200.0;
float currentFreq = 0;

void setup() {
  Wire.begin();
  Serial.begin(9600);
  radio.setMono(true);  // optional: mono for clarity
}

void loop() {
  int potValue = analogRead(potPin); // 0 to 1023
  float freq = map(potValue, 0, 1023, minFreq * 100, maxFreq * 100) / 100.0;

  if (abs(freq - currentFreq) > 0.5) { // only update if changed
    radio.setFrequency(freq);
    currentFreq = freq;
    Serial.print("Tuned to: ");
    Serial.println(freq);
  }

  delay(200); // reduce I2C spamming
}

