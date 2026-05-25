//Motion detection sensor and result displayed in LCD 

#include<Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0X27,16,2);
int pir_pin=7;
int led=6;
void setup(){
  pinMode(led,OUTPUT);
  pinMode(pir_pin,INPUT);
  lcd.init();
  lcd.begin(16,2);
  lcd.backlight();
  lcd.print("Hello world");
  lcd.setCursor(0,1);
}
void loop(){
  int pir=digitalRead(pir_pin);
  if(pir==LOW){
    digitalWrite(led,HIGH);
    lcd.setCursor(0,1);
    lcd.print("Object detected");
    delay(1000);
  }
  else{
    digitalWrite(led,LOW);
    lcd.setCursor(0,1);
    lcd.print("Objected not detected");
    delay(1000);
  }
}
