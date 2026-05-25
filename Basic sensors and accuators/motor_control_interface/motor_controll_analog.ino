/* L298N motor driver control interface using Arduino uno */
#define motor1pin1 3 //IN1
#define motor1pin2 4 //IN2
#define motor2pin1 7 //IN3
#define motor2pin2 8 //IN4
#define motor1analog_pin 5//EN1
#define motor2analog_pin 6 //EN2

//changing Analog speed here from 0 to 255
#define motor1analog_speed 120
#define motor2analog_speed 120  


void setup() {
 
  Serial.begin(9600); 
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(motor1analog_pin, OUTPUT);
  pinMode(motor2analog_pin, OUTPUT);
}

void loop() {
//Wheels moving forward
  digitalWrite(motor1pin1,HIGH);
  digitalWrite(motor1pin2,LOW);
  digitalWrite(motor2pin1,HIGH);
  digitalWrite(motor2pin2,LOW);
  analogWrite(motor1analog_pin,motor1analog_speed);
  analogWrite(motor2analog_pin,motor2analog_speed);
  delay(2000);
  //Wheels moving backward
  digitalWrite(motor1pin1,LOW);
  digitalWrite(motor1pin2,HIGH);
  digitalWrite(motor2pin1,LOW);
  digitalWrite(motor2pin2,HIGH);
  analogWrite(motor1analog_pin,motor1analog_speed);
  analogWrite(motor2analog_pin,motor2analog_speed);
  delay(2000);
 //Right wheel moving
  digitalWrite(motor1pin1,HIGH);
  digitalWrite(motor1pin2,LOW);
  digitalWrite(motor2pin1,LOW);
  digitalWrite(motor2pin2,LOW);
  analogWrite(motor1analog_pin,motor1analog_speed);
  analogWrite(motor2analog_pin,motor2analog_speed);
  delay(2000);
  //Left wheel moving 
  digitalWrite(motor1pin1,LOW);
  digitalWrite(motor1pin2,LOW);
  digitalWrite(motor2pin1,HIGH);
  digitalWrite(motor2pin2,LOW);
  analogWrite(motor1analog_pin,motor1analog_speed);
  analogWrite(motor2analog_pin,motor2analog_speed);
  delay(2000);
  //Wheels stopped
  digitalWrite(motor1pin1,LOW);
  digitalWrite(motor1pin2,LOW);
  digitalWrite(motor2pin1,LOW);
  digitalWrite(motor2pin2,LOW);
  delay(2000);

}

  
