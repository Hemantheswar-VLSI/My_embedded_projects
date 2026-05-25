/* Calculating distance by using Ultrasonic sensor and showing distance in serial monitor */

#define trig 5
#define echo 6
int ultra(){
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  long duration=pulseIn(echo,HIGH,20000 );
  Serial.print("Duration and distance : ");
  Serial.println(duration);
  int distance =duration * 0.034 / 2 ;
  Serial.println(distance);
  return distance;
}
void setup(){
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
}
void loop(){
  int distance=ultra();
  Serial.print(distance);
  Serial.print("cm \n");
  delay(1000);
  int distance=ultra();
  		Serial.print("Distance  : ");
  		Serial.print(distance);
  		Serial.println(" cm");
      delay(1000);
      

}
