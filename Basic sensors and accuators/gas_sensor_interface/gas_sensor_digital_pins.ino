/* Gas sensor taking  readings and indicating dangerous gases using led using digital pins */

int gas=6;
int val;
int led=5;
void setup(){
  Serial.begin(9600);
  pinMode(gas,INPUT);
  pinMode(led,OUTPUT);

}
void loop(){
  val=digitalRead(gas);
  Serial.println(val);
  if(val==1){
    digitalWrite(led,HIGH);
    Serial.println("Danger");
  }
  else{
    digitalWrite(led,LOW);
  };
  delay(500);
}
