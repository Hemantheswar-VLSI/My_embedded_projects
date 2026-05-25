/* Servo motor interface */

#include<Servo.h>
Servo servo;
#define servo_pin 6

void setup(){
servo.attach(servo_pin);
Serial.begin(9600);
}

void loop(){
for(int i=0;i<=180;i++){
servo.write(i);
delay(15);
}
delay(2000);
for(int i=180;i>=0;i--){
servo.write(i);
delay(15);
}
delay(2000);
}

