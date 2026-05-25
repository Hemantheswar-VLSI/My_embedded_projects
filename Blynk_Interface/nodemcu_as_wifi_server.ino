#include <ESP8266WiFi.h>
#include <DHT.h>
#define DHTPIN D2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
const char* ap_ssid = "ESP8266_AP";
const char* ap_password = "esp8266ap";
WiFiServer server(80);
void setup() {
Serial.begin(9600);
dht.begin();
pinMode(A0, INPUT); // Gas sensor
WiFi.softAP(ap_ssid, ap_password);
Serial.print("AP IP: ");
Serial.println(WiFi.softAPIP());
server.begin();
}
void loop() {
WiFiClient client = server.available();
if (!client) return;
while (client.connected() && !client.available()) delay(1);
String req = client.readStringUntil('\n');
req.trim();
if (req.indexOf("favicon.ico") >= 0) {
client.stop();
return;
}
while (client.available()) {
String header = client.readStringUntil('\n');
if (header == "\r" || header == "") break;
}
float h = dht.readHumidity();
float t = dht.readTemperature();
int gasValue = analogRead(A0);
client.println("HTTP/1.1 200 OK");
client.println("Content-Type: text/html");
client.println("Connection: close");
client.println();
client.println("<!DOCTYPE html><html><head>");
client.println("<meta name='viewport' content='width=device-width,initial-scale=1'>");
client.println("<style>body{font-family:Arial;text-align:center;background:#f2f2f2;}.box{background:#fff;padding:20px;width:320px;margin:auto;border-radius:10px;}</style>");
client.println("</head><body><div class='box'>");
client.println("<h1>Hemanth's Page</h1>");
if (isnan(t) || isnan(h)) {
client.println("<p>DHT connections wrong</p>");
} else {
client.print("<p> Temperature: <b>"); client.print(t); client.println("&deg;C</b></p>");
client.print("<p> Humidity: <b>"); client.print(h);
client.println("%</b></p>");
}
client.print("<p>Gas Value: <b>");
client.print(gasValue);
client.println("</b></p>");
if (gasValue > 600) {
client.println("<p style='color:red; font-weight:bold;'>⚠ High GasLevel!</p>");
}
client.println("</div></body></html>");
delay(1);
client.stop();
}
