#include <ESP8266WiFi.h> // Include the Wi-Fi library
#include <WiFiClient.h> // Include WiFi Client
#include <ESP8266WebServer.h> // Include Web Server

const char *ssid = "Qbus";
const char *password = "__qbus__";

ESP8266WebServer server(80);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(10);
  Serial.println('\n');

  WiFi.hostname("Qbus"); // Set hostname

  WiFi.softAP(ssid, password); // Start the access point
  Serial.print("Access Point \"");
  Serial.print(ssid);
  Serial.println("\" started");

  Serial.print("IP address:\t");
  Serial.println(WiFi.softAPIP());

  runServer();
}

void loop() {
  // put your main code here, to run repeatedly:
  connectedCount();
  server.handleClient();
}

void connectedCount() {
  Serial.print("\nPlayers: ");
  Serial.print(playerCount());
  delay(2000);
  connectedCount();
}

double playerCount() {
  return WiFi.softAPgetStationNum();
}

void runServer() {
  server.on("/", serverRoot);

  server.onNotFound(serverNF);

  server.begin();
}

void serverRoot() {
  server.send(200, "text/html", "<h1><b>Q</b>bus</h1>");
}

void serverNF() {
  server.send(4040, "text/html", "<h1>404 Not FOund</h1><hr /><b>Q</b>bus");
}
