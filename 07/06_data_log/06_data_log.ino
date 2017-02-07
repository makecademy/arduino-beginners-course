// Libraries
#include <SPI.h>
#include <WiFi101.h>
#include "DHT.h"

// WiFi credientials
char ssid[] = "UPC2A55751"; //  your network SSID (name)
char pass[] = "sBfj3wfEurnh";    // your network password (use for WPA, or use as key for WEP)

// Status
int status = WL_IDLE_STATUS;

// Pin
#define DHTPIN 5

// Use DHT11
#define DHTTYPE DHT11

// Create instance
DHT dht(DHTPIN, DHTTYPE);

// Server
char server[] = "dweet.io"; 

// Client instance
WiFiClient client;

void setup() {
  
  // Initialize serial and wait for port to open:
  Serial.begin(115200);

  // Init DHT
  dht.begin();

  // Attempt to connect to WiFi network:
  while (status != WL_CONNECTED) {
    
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);

    // Wait 10 seconds for connection:
    delay(10000);
  }
  Serial.println("Connected to wifi");
  printWiFiStatus();
}

void loop() {

  // Reading temperature & humidity
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Light level
  int sensorData = analogRead(A0);
  float light = sensorData/1024.*100.;

  // Build request
  String request = "GET /dweet/for/mymkr1000?temperature=";
  request += String(t);
  request += "&humidity=";
  request += String(h);
  request += "&light=";
  request += String(light);
  request += " HTTP/1.1";

  Serial.println("\nStarting connection to server...");
  // if you get a connection, report back via serial:
  if (client.connect(server, 80)) {
    Serial.println("connected to server");
    // Make a HTTP request:
    Serial.println(request);
    client.println(request);
    client.println("Host: dweet.io");
    client.println("Connection: close");
    client.println();
  }
  
  // if there are incoming bytes available
  // from the server, read them and print them:
  while (client.connected()) {
    while (client.available()) {
      char c = client.read();
      Serial.print(c);
    }
  }

  // if the server's disconnected, stop the client:
  Serial.println();
  Serial.println("disconnecting from server.");
  client.stop();

  delay(10000);
}


void printWiFiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}



