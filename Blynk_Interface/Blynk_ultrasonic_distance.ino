/* Sending distance measured from ultrasonic sensor to Blynk App  */


//These details you will find after creation of template in Blynk app
#define BLYNK_TEMPLATE_ID "Blynk template id
#define BLYNK_TEMPLATE_NAME "template name"
#define BLYNK_AUTH_TOKEN "author token"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "Author token ";
char ssid[] = "Hotspot name";
char pass[] = "Hotspot password";

#define TRIG_PIN D5  // Trigger pin for ultrasonic sensor
#define ECHO_PIN D6  // Echo pin for ultrasonic sensor

BlynkTimer timer;  // Blynk timer to send data periodically

void sendUltrasonicData() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  int distance = duration * 0.034 / 2;  // Convert time to distance in cm

  Serial.print("Distance: ");
  delay(200);
  Serial.print(distance);
  delay(200);
  Serial.println(" cm");
delay(200);
  Blynk.virtualWrite(V2, distance);  // Send distance data to Blynk
}

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");

  Blynk.begin(auth, ssid, pass);

}

void loop() {
  Blynk.run();  // Run Blynk

delay(1000);
sendUltrasonicData();
}
