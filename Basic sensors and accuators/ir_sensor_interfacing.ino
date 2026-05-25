/* IR sensor interfacing */

#define ir_pin 5
int ir_value=0;
void setup() {
  
  pinMode(ir_pin,INPUT);
  Serial.begin(9600);
}

void loop() {
  
  ir_value=digitalRead(ir_pin);
  Serial.print("IR value : ");
  Serial.println(ir_value);  //0 if black object detected or 1 black object not detected
  delay(1000);
}
