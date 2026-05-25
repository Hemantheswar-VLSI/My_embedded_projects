//Led blynking using analog pins and changing brightness of led

#define led 3

void setup() {
  pinMode(led,OUTPUT);
  
}

void loop() {
 for(int i=0;i<=255;i++){
  analogWrite(led,i);
  delay(15);
 }
 delay(1000);
 
 for(int i=255;i>=0;i--){
 analogWrite(led,i);
 delay(15);
 }
  
  delay(1000);

}
