//Code for tesing a Buzzer 

#define buz 8       
void setup(){
  pinMode(buz,OUTPUT);
}
void loop(){
  tone(buz,2000);
  delay(2000);
  noTone(buz);
  delay(2000);
}
