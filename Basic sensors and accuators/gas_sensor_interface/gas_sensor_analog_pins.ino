/*Gas sensor readings and indicating dangerous gases using led and gas values are displayed in serial monitor using analog pins    */

int gas=A0;
int val;
int led=5;
void setup(){
  Serial.begin(9600);
  pinMode(gas,INPUT);
  pinMode(led,OUTPUT);

}
void loop(){
  val=analogRead(gas);
  Serial.println(val);
  if(val>=1000){
    digitalWrite(led,HIGH);
    Serial.println("Danger");
  }
  else{
    digitalWrite(led,LOW);
  };
  delay(500);
}
