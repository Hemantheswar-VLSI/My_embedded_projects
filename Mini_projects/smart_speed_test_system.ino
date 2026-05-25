/* Smart speed test system using 2 ir sensros and arduino   */

#include <Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

#define buz 8
#define ir1_pin 3
#define ir2_pin 5
int ir1=0;
int ir2=0;

void setup(){
  pinMode(ir1_pin,INPUT);
  pinMode(ir2_pin,INPUT);
  lcd.init();
  lcd.backlight();
 lcd.print("ROBOTICS LAB RKV");
  lcd.setCursor(0,1);
  lcd.print("SPEED TESTING");
  delay(2000);
  pinMode(buz,OUTPUT);

}
void loop(){
  ir1=digitalRead(ir1_pin);
  delay(20);                //This delay is like time between 2 stops.Here the distance between these 2 irs we know that , delay 
  ir2=digitalRead(ir2_pin);  // means time , then speed=distance/time;
  if(ir1==0 && ir2==1){                   //One check point is crossed but other is not crossed , so speed is in limit
    lcd.setCursor(0,1);
    lcd.print("Speed in limit     ");
  }
  else if(ir2==0 && ir1==1){     //From other direction One check point is crossed but other is not crossed , so speed is in limit 
     lcd.setCursor(0,1);
    lcd.print("Speed isin limit");

  }
  else if(ir1==0 && ir2==0){          //Both check points are reached within time so speed is high 
    lcd.setCursor(0,1);
    lcd.print("Over speed alert    ");

  }
  else{
     lcd.setCursor(0,1);
      lcd.print("No vehcile entered  ");
  }

delay(1000);       // For real time monitoring avoid this delay
 
}





