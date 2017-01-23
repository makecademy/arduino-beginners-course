// Libraries
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Instance
LiquidCrystal_I2C lcd(0x27,20,4); 

void setup()
{
  // Init
  lcd.init();
  
  // Print a message to the LCD
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Hello, world!");
  
}


void loop()
{
}
