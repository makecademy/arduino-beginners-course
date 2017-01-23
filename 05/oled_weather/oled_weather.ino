//Libraries
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "DHT.h"

// Pin
#define OLED_RESET 4

// Pin
#define DHTPIN 5

// Use DHT11
#define DHTTYPE DHT11

// Create instance
DHT dht(DHTPIN, DHTTYPE);

// Instance
Adafruit_SSD1306 display(OLED_RESET);

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

void setup()   {   
               
  Serial.begin(9600);

  // Init
  display.begin(SSD1306_SWITCHCAPVCC, 0x3D);  // initialize with the I2C addr 0x3D (for the 128x64)

  // Clear the buffer.
  display.clearDisplay();

  // Init DHT
  dht.begin();
  
}


void loop() {

  // Read light level
  int sensorReading = analogRead(A0);
  int lightLevel = (int)(sensorReading/1024. * 100);

  // Reading temperature & humidity
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Display on OLED
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  
  display.print("Temperature: ");
  display.print(t);
  display.println(" C");
  display.println("");
  
  display.print("Humidity: ");
  display.print(h);
  display.println("%");
  display.println("");
  
  display.print("Light level: ");
  display.print(lightLevel);
  display.println("%");

  display.display();

  delay(500);
  
}
