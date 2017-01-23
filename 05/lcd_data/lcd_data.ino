// Libraries
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

// Pin
#define DHTPIN 5

// Instance
LiquidCrystal_I2C lcd(0x27,20,4); 

// Use DHT11
#define DHTTYPE DHT11

// Create instance
DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  // Init
  lcd.init();
  lcd.backlight();

  // Init DHT
  dht.begin();
  
}


void loop()
{

   // Reading temperature & humidity
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Print to the LCD
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temperature: ");
  lcd.print(t);
  lcd.setCursor(0,2);
  lcd.print("Humidity: ");
  lcd.print(h);

  // Wait a few seconds between measurements
  delay(2000);
  
}
