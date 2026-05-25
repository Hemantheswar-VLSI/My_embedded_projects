//Temperature senor taking readings and displayed in LCD display 

#include<Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

#include<DHT.h>
#define out 8
DHT dht(out, DHT11);
void setup()
{
  lcd.init();
  lcd.backlight();
lcd.begin(16,2);
lcd.setCursor(0,0);
lcd.print("Hello World");
Serial.begin(9600);
dht.begin();
}
void loop() {
delay(2000);
float temperature = dht.readTemperature();
float humidity = dht.readHumidity();
Serial.print("Temperature: ");
Serial.print(temperature);
Serial.println(" °C");
lcd.setCursor(0,1);
lcd.print("Temperature : ");
lcd.setCursor(6,1);
lcd.print(temperature);
Serial.print("Humidity: ");
Serial.print(humidity);
Serial.println(" %");
lcd.setCursor(0,0);
lcd.print("Humidity : ");
lcd.setCursor(11,0);
lcd.print(humidity);
}
