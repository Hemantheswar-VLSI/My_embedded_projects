/* Interfacing led blynking using Blynk App  */

#define BLYNK_TEMPLATE_ID "Template id"
#define BLYNK_TEMPLATE_NAME "Template name"
#define BLYNK_AUTH_TOKEN "Authentification token"


#include <BlynkSimpleEsp8266.h>

char auth[] = "Authentification token";
char ssid[] = "Hotspot name";
char pass[] = "Hotspot password";

#define led 3
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  Blynk.begin(auth, ssid, pass);
   while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    
  }
  Serial.println("\nWiFi connected!");
 

}

BLYNK_WRITE(V0){
  int value=param.asInt();
  analogWrite(led,value);     // use this if you use slider for changing brightness of led in Blynk app
  /*
  digitalWrite(led,value );  // Use this if you use switch or push bottons in Blynk app
  
        */
}



// the loop function runs over and over again forever
void loop() {
  Blynk.run();
}
