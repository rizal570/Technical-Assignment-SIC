#include <WiFi.h>
#include <HTTPClient.h>
#include "DHT.h"

const char* ssid = "SECRET";
const char* password = "bajutidur1";
const char* serverUrl = "192.168.1.13";

#define DHTTYPE DHT11 // DHT 11
//DHT Sensor;
uint8_t DHTPin = 4;
DHT dht(DHTPin, DHTTYPE);

float temperature;
float Humidity;

WiFiClient client;

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Connect to WiFi network
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
  Serial.println("IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Replace this section with your sensor data reading code
  Humidity = dht.readHumidity();
  // Read temperature as Celsius (the default)
  temperature = dht.readTemperature();
}
  String processor(const String& var){
  loop();
  //Serial.println(var);
  if(var == "TEMPERATURE_C"){
    return String(temperature_Celsius);
  }
   else if(var == "HUMIDITY"){
    return String(Humidity);

  // Convert sensor reading to JSON format (example)
  String jsonData = "{\"sensorValue\":";
  jsonData += Humidity,Temperature;
  jsonData += "}";

  // Send POST request with sensor data
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(client, serverUrl);
    http.addHeader("Content-Type", "application/json");
    int httpResponseCode = http.POST(jsonData);
    String response = http.getString();

    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    Serial.println(response);

    http.end();
  } else {
    Serial.println("ESP32 not connected to WiFi");
  }

  delay(5000);
}
