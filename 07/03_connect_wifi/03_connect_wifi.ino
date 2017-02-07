// Libraries
#include <SPI.h>
#include <WiFi101.h>

// WiFi credientials
char ssid[] = "UPC2A55751"; //  your network SSID (name)
char pass[] = "sBfj3wfEurnh";    // your network password (use for WPA, or use as key for WEP)

// Status
int status = WL_IDLE_STATUS;

void setup() {
  
  // Initialize serial and wait for port to open:
  Serial.begin(115200);

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





