// Libraries
#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

// Instance
Adafruit_8x8matrix matrix = Adafruit_8x8matrix();

void setup() {

  // Serial
  Serial.begin(9600);
  Serial.println("8x8 LED Matrix Test");

  // Init LED matrix
  matrix.begin(0x70);
}

void loop() {

  // Single pixel
//  matrix.clear();
//  matrix.drawPixel(4, 5, LED_ON);  
//  matrix.writeDisplay();

  matrix.setTextSize(1);
  matrix.setTextWrap(false);
  matrix.setTextColor(LED_ON);
  for (int8_t x=0; x>=-36; x--) {
    matrix.clear();
    matrix.setCursor(x,0);
    matrix.print("25 C");
    matrix.writeDisplay();
    delay(100);
  }
}
