#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

// Pin definitions
#define TFT_CS     10
#define TFT_RST    8
#define TFT_DC     9

// Initialize the display
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  Serial.begin(9600);
  Serial.println("TFT test");

  tft.initR(INITR_BLACKTAB);  // Use INITR_BLACKTAB or REDTAB depending on your display
  tft.fillScreen(ST77XX_BLACK);
  tft.setCursor(10, 30);
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(2);
  tft.println("It works!");
}

void loop() {
  // Do nothing
}

