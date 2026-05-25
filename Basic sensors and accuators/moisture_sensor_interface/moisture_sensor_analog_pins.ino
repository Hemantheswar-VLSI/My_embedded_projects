/* Moisture sensor taking readings using analog pins and displayed moisture values in serial monitor */

int moisture_pin=A0;
int led=5;
int water;
void setup(){
  pinMode(led,OUPUT);
  pinMode(moisture_pin,INPUT);

}
void loop(){
  water=analogread(moisture_pin);
  Serial.print("Moisture level");
  Serial.println(moisture_pin);
  if(water>=500){
    digitalWrite(led,HIGH);
    Serial.println("Moisture is detected");
  }
  else{
    digitalWrite(led,LOW);
    Serial.println("Moisture is not detected");
  };
  delay(1000);
}
