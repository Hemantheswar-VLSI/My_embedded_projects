//Password based door lock system   ---------        mini project 

#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <Servo.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo servoLock;
const byte ROWS = 4;
const byte COLS = 3;
char keys[ROWS][COLS] = {
{'1','2','3'},
{'4','5','6'},
{'7','8','9'},
{'*','0','#'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
String password = "1234";
String inputPassword = "";
void setup() {

lcd.init();
lcd.backlight();
servoLock.attach(10);
servoLock.write(0);
lcd.setCursor(0, 0);
lcd.print("Door Locked");
delay(1500);
lcd.clear();
}
void loop() {
lcd.setCursor(0, 0);
lcd.print("Enter Password:");
char key = keypad.getKey();
if (key) {
  if (key == '#') {         //key to check the password 
    if (inputPassword == password) {
      unlockDoor();
      }
    else {
      wrongPass();
      }
    inputPassword = "";
    } 
  else if (key == '*') {        //key to clear the entered password
    inputPassword = "";
    lcd.clear();
    }
 else {                           //this blocks continue to store the password in each press of a key
inputPassword += key;
lcd.setCursor(0, 1);
lcd.print(inputPassword);
}
}
}
void unlockDoor() {
lcd.clear();
lcd.print("Access Granted");
servoLock.write(90);
delay(2000);
lockDoor();
}
void wrongPass() {
lcd.clear();
lcd.print("Wrong Password");
delay(1500);
lcd.clear();
}
void lockDoor() {
lcd.clear();
lcd.print("Door Locked");
servoLock.write(0);
}
