#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#define TRIGGER_PIN 2
#define ECHO_PIN 3
#define LED_PIN 13

const char* ssid = "YourWiFiNetwork";
const char* password = "YourWiFiPassword";

ESP8266WebServer server(80);

void setup() {
  Serial.begin(9600);
  
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  
  Serial.println("Connected to WiFi");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
  server.on("/", handleRoot);
