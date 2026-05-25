/* L298N motor driver control interface using Arduino uno */
#define motor1pin1 3 //IN1
#define motor1pin2 4 //IN2
#define motor2pin1 5 //IN3
#define motor2pin2 6 //IN4

void setup() {
 
  Serial.begin(9600); 
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
}

void loop() {
//Wheels moving forward
  digitalWrite(motor1pin1,HIGH);
  digitalWrite(motor1pin2,LOW);
  digitalWrite(motor2pin1,HIGH);
  digitalWrite(motor2pin2,LOW);
  delay(2000);
  //Wheels moving backward
  digitalWrite(motor1pin1,LOW);
  digitalWrite(motor1pin2,HIGH);
  digitalWrite(motor2pin1,LOW);
  digitalWrite(motor2pin2,HIGH);
  delay(2000);
 //Right wheel moving
  digitalWrite(motor1pin1,HIGH);
  digitalWrite(motor1pin2,LOW);
  digitalWrite(motor2pin1,LOW);
  digitalWrite(motor2pin2,LOW);
  delay(2000);
  //Left wheel moving 
  digitalWrite(motor1pin1,LOW);
  digitalWrite(motor1pin2,LOW);
  digitalWrite(motor2pin1,HIGH);
  digitalWrite(motor2pin2,LOW);
  delay(2000);
  //Wheels stopped
  digitalWrite(motor1pin1,LOW);
  digitalWrite(motor1pin2,LOW);
  digitalWrite(motor2pin1,LOW);
  digitalWrite(motor2pin2,LOW);
  delay(2000);

}

  
