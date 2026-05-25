#include<Servo.h>
#define m1p1 2
#define m1p2 4
#define m2p1 7
#define m2p2 8
#define m1ap 5
#define m2ap 6
#define trig 3
#define echo 9
#define servo 10
#define led 13
#define ir 12
Servo myservo;
int ultra(){
  digitalWrite(trig,LOW);
  delay(1000);
  digitalWrite(trig,HIGH);
  delay(1000);
  digitalWrite(trig,LOW);
  long duration=pulseIn(echo,HIGH);
  int distance =duration * 0.032 / 2 ;
  return(distance);
}
void setup(){
  Serial.begin(9600);
  pinMode(led,12);
  pinMode(ir,INPUT);
  pinMode(m1p1,OUTPUT);
  pinMode(m1p2,OUTPUT);
  pinMode(m2p1,OUTPUT);
  pinMode(m2p2,OUTPUT);
  pinMode(m1ap,OUTPUT);
  pinMode(m2ap,OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  myservo.attach(10);
}
void loop(){
	int ir_value=digitalRead(ir);
	Serial.print(" = Object detection : ");
  	Serial.println(ir_value);
  	
if(ir_value==1){//No parking slot is detected
  myservo.write(90);
  int distance=ultra();
  Serial.print(distance);
  Serial.print("cm \n");
if(distance>50){
  		digitalWrite(m1p1,HIGH);
  		digitalWrite(m1p2,LOW);
  		analogWrite(m1ap,80);
  		digitalWrite(m2p1,HIGH);
  		digitalWrite(m2p2,LOW);
  		analogWrite(m2ap,80);
  }
else{
  		digitalWrite(m1p1,LOW);
  		digitalWrite(m1p2,LOW);
  		digitalWrite(m2p1,LOW);
  		digitalWrite(m2p2,LOW);
  
  
      for(int i=90;i<=180;i++){
      myservo.write(i);
    	}
    	delay(1000);
    	int distance1=ultra();
  	  for(int i=180;i>=0;i--){
      	myservo.write(i);
    	}
    	delay(1000);
    	int distance2=ultra();
  		
    if(distance1<distance2){
  		digitalWrite(m1p1,HIGH);
  		digitalWrite(m1p2,LOW);
  		analogWrite(m1ap,150);
  		digitalWrite(m2p1,LOW);
  		digitalWrite(m2p2,LOW);
      delay(600);              //This delay is for time to turn left or right. This delay should be small if delay is more then turn is more we will loss perfection
    }
    else if(distance1>distance2){
                digitalWrite(m1p1,LOW);
  		digitalWrite(m1p2,LOW);
      	        digitalWrite(m2p1,HIGH);
  		digitalWrite(m2p2,LOW);
  		analogWrite(m2ap,150);
      delay(600);                //This delay is for time to turn left or right. This delay should be small if delay is more then turn is more we will loss perfection
    }
    
}
}
  else{
                digitalWrite(m1p1,LOW);
  		digitalWrite(m1p2,LOW);
  		digitalWrite(m2p1,LOW);
  		digitalWrite(m2p2,LOW);
    		digitalWrite(led,HIGH);
    		Serial.print("Parked succesfully");
  }
  
  
}
