/*Colour sensor detecting colours and displayed using 3 colour frequencies  */

#include<LiquidCrystal_I2C.h>
  #include<Wire.h>
  LiquidCrystal_I2C lcd(0x27,16,2);
  const int S0 = 5;
  const int S1 = 4;
  const int S2 = 7;
  const int S3 = 6;
  const int sensorOut = 8;
  int redFrequency = 0;
  int greenFrequency = 0;
  int blueFrequency = 0;
  void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Hello world");
  Serial.begin(9600);
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  Serial.println("TCS230 Color Sensor Test");
  lcd.setCursor(0,0);
  lcd.print("TCS230 Color Sensor Test");
  }
  void loop() {
  redFrequency = pulseIn(sensorOut, LOW);
  delay(10);
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  greenFrequency = pulseIn(sensorOut, LOW);
  delay(10);
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  blueFrequency = pulseIn(sensorOut, LOW);
  delay(10);
  Serial.print("Red: "); Serial.print(redFrequency);lcd.setCursor(0,1);lcd.print("R:");lcd.setCursor(2,1);lcd.print(redFrequency);
  Serial.print(" Green: "); Serial.print(greenFrequency);lcd.setCursor(6,1);lcd.print("G:");lcd.setCursor(8,1);lcd.print(greenFrequency);
  Serial.print(" Blue: "); Serial.println(blueFrequency);lcd.setCursor(11,1);lcd.print("B:");lcd.setCursor(13,1);lcd.print(blueFrequency);
  delay(1000);
  }
