#include <Wire.h>
#include <TEA5767.h>

TEA5767 radio = TEA5767();

void setup() {
  Serial.begin(9600);
  Wire.begin();
  radio.setFrequency(91.9);  // Set to a known FM station in your area
  delay(100);
  Serial.println("TEA5767 ready. Playing 91.9 MHz.");
}

void loop() {
  // Nothing in loop
}

