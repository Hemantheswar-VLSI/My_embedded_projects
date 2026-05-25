/* LCD display interfacing using Arduino  */

#include<Wire.h>
#include<LiquidCrystal_I2C.h>       
#define led_pin 5
LiquidCrystal_I2C LCD(ox27,16,2);
void setup(){
 pinMode(led_pin,OUTPUT);
 lcd.init();
 lcd.backlight();
 lcd.begin(16,2);
 lcd.setCursor(0,0);
lcd.print("LCD using Arduino Uno");
lcd.setcursor(0,1);
lcd.print("LED Blinking...");
delay(2000);
}
void loop(){
  digitalWrite(led_pin,HIGH);
  lcd.setCursor(0,1);
  lcd.print("LED:ON");
  delay(1000);
  digitalWrite(led_pin,LOW);
  lcd.setCursor(0,1);
  lcd.print("LED:OFF");
  delay(1000);
}
