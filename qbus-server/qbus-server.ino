#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);

int r = random(100, 999)

const char *ssid = "Qbus" + to_string(r)
const char *WiFiPWD = "q" + to_string(r)

void setup() {
  Serial.begin(115200);
  Serial.println("");

  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, WiFiPWD);

  delay(500);

  Serial.println("IP Adress:");
  Serial.println(WiFi.softAPIP());

  Serial.println("[DEBUG] Begin Server")

  serverSetup()

  server.begin(); // Run Server
  Serial.println("[DEBUG] Run HTTP Server");
}

void loop() {

}

void serverSetup() {
  server.onNotFound(sNF)
}

void sNF() {
  server.send(404, "text/plain", "Error: 404 - Not Found")
}
