/*taking gas values , temperature and humidity values in blynk app using guage template and virtual pins V0,V1,V2 */

/*These credentials are find in blynk app */
#define BLYNK_TEMPLATE_ID "Template_id"
#define BLYNK_TEMPLATE_NAME "templete_name"
#define BLYNK_AUTH_TOKEN "auth_token"  

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#include<DHT.h>

#define gas A0
int out=D8;
DHT dht(out,DHT11);

char auth[] = "Author_token";
char ssid[] = "Hotspot_name";
char pass[] = "Hotspot_password";



void setup() {
  Blynk.begin(auth,ssid,pass);
  Serial.begin(9600);
  pinMode(gas,INPUT);
  dht.begin();
}

void gasreading(){
   int value=analogRead(gas);
   int temp=dht.readTemperature();
   int humidity=dht.readHumidity();
  Serial.println(value);
  Blynk.virtualWrite(V0,value);
  Blynk.virtualWrite(V1,temp);
  Blynk.virtualWrite(V2,humidity);
}


void loop() {
  Blynk.run();
  delay(1000); // to avoid continue taking readings which avoid random values due fast running loop
}
