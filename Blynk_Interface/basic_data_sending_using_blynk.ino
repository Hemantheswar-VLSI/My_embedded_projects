//Basic example how to take readings from blynk app using virtual pins 

#define BLYNK_TEMPLATE_ID "Template id"
#define BLYNK_TEMPLATE_NAME "template name"
#define BLYNK_AUTH_TOKEN "authentification token "


#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


char auth[] = "authentification token ";
char ssid[] = "Hotspot name";
char pass[] = "Hotspot password";

void setup(){
  Blynk.begin(auth, ssid, pass); 
    Serial.begin(9600);
    Serial.println("program starts ");
};

BLYNK_WRITE(V0){
  int value = param.asInt();  //It param.asInt converts parameter V0 to a interger value which you send in blynk app
  Serial.println(value);      //Observe values in Serial monitor
}

void loop(){
  Blynk.run();
}

