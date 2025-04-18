// TFT Display

#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>
#include <string.h>

#define TFT_CS 10
#define TFT_RST 8
#define TFT_DC  9

#define TFT_WIDTH 128
#define TFT_HEIGHT 160
#define TFT_SCALE 2
#define CHAR_WIDTH (TFT_SCALE * 6)
#define CHAR_HEIGHT (TFT_SCALE *8)

int getStringWidth(const char *str);
int getStringHeight(const char *str);
void printCenter(const char *str);

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

// TEA5767 Radio

#include <Wire.h>
#include <TEA5767.h>

void update();

TEA5767 radio;
const int FREQUENCY_PIN = A0;
const float MIN_FREQUENCY = 0.0f;
const float MAX_FREQUENCY = 200.0f;
const float FREQUENCY_TOLERANCE = 0.5f;
float current_frequency = 91.4f;

void setup() {
  tft.initR(INITR_BLACKTAB);
  Wire.begin();
  Serial.begin(9600);
  radio.setMono(true);

  /*tft.fillScreen(ST77XX_BLACK);
  tft.setCursor(TFT_WIDTH/2 - getStringWidth(text)/2, TFT_HEIGHT/2 - getStringHeight(text)/2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(2);
  tft.println(text);*/
}

void loop() {
  int frequency_pot_value = analogRead(FREQUENCY_PIN);
  float frequency = map(frequency_pot_value, 0, 1023, MIN_FREQUENCY * 100, MAX_FREQUENCY * 100) / 100.0f;

  if (abs(frequency - current_frequency) > FREQUENCY_TOLERANCE) {
    update(frequency);
  }
}

int getStringWidth(const char *str) {
  return CHAR_WIDTH * strlen(str);
}

int getStringHeight(const char *str) {
  int lines = 0;
  for (int i = 0; str[i]; i++) {
    if (str[i] == '\n') {
      lines++;
    }
  }

  return CHAR_HEIGHT * lines;
}

void printCenter(const char *str) {
  const int x = (TFT_WIDTH / 2) - getStringWidth(str) / 2;
  const int y = (TFT_HEIGHT / 2) - getStringHeight(str) / 2;

  tft.fillScreen(ST77XX_BLACK);
  tft.setCursor(x, y);
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(TFT_SCALE);
  tft.println(str);
}

void update(float frequency) {
  radio.setFrequency(frequency);
  current_frequency = frequency;

  char frequency_string[5];
  sprintf(frequency_string, "%.1f", current_frequency);
  printCenter(frequency_string);
}


