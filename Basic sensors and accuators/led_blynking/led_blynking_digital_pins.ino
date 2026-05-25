//Led blynking using digital pins

#define led 3

void setup() {
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(led,LOW);
  Serial.println("HIGH");
  delay(1000);
  digitalWrite(led,HIGH);
  Serial.println("LOW");
  delay(1000);

}
