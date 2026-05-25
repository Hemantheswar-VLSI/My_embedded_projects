/* Basic motor control using Blynk app and Nodemcu  */

//These credentials you will find after creating a template in Blynk webstie
#define BLYNK_TEMPLATE_ID "Template id"
#define BLYNK_TEMPLATE_NAME "Template name"
#define BLYNK_AUTH_TOKEN"authentification token"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


char auth[] = "authentification token";
char ssid[] = "Hotspot name";
char pass[] = "Hotspot password";



#define m1p1 D0        //m1p1=motor 1  pin1    IN1
#define m1p2 D1        //m1p2=motor 1  pin2    IN2
#define m1ap D2        //m1ap=motor1 analog pin  EN1
void setup(){
  Serial.begin(115200);          //You can use 9600 also but bee sure braud rate in serial monitor should be same to this 
  Blynk.begin(auth, ssid, pass); 
  pinMode(m1p1,OUTPUT);
  pinMode(m1p2,OUTPUT);
  pinMode(m1ap,OUTPUT);

}
BLYNK_WRITE(V0) {
  int value = param.asInt(); 
  Serial.println(value);
  //Use this when you use switch or push button as Virtual pin V0
  if(value==HIGH){
    digitalWrite(m1p1,HIGH);
    digitalWrite(m1p2,LOW);
  }
  else if (value==LOW){ 

    digitalWrite(m1p1,LOW);
    digitalWrite(m1p2,LOW);

  }
  
  /*  
  // use this when you use slider as virtual pin V0
    digitalWrite(m1p1,HIGH);
    digitalWrite(m1p2,LOW);
    analogWrite(m1ap,value);    
  */
}

void loop(){
   Blynk.run();
}
