/*Moisture sensor and led blynking based on moisture levels based on digital values(0 if moisutre is present or 1 moisture is not present)   */

int moisture_pin=6;
int led=5;
int water;
void setup(){
  pinMode(led,OUPUT);
  pinMode(moisture_pin,INPUT);

}
void loop(){
  water=digitalread(moisture_pin);
  if(water==0){
    digitalWrite(led,HIGH);

  }
  else{
    digitalWrite(led,LOW);
  };
  delay(1000);
}
