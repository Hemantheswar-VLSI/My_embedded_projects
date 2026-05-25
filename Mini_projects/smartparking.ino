/*Smart parking in urban areas to know the how many parking slots are available in the parking area and changes based on in and out going cars */

#include<Servo.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd (0x27,16,2);

#define ir1 4
#define ir2 7

#define servo_pin 9
Servo servo;

int count=0;
int slots=5;

void setup(){

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("PARKING AREA :");
  lcd.setCursor(0,1);
  lcd.print("WELCOME ");

  pinMode(ir1,INPUT);
  pinMode(ir2,INPUT);
  //pinMode(trig,OUTPUT);
  //pinMode(echo,INPUT);
  Serial.begin(9600);
  servo.attach(servo_pin);
}

void loop(){
 // int distance=ultra();
  //Enter
  int enter=digitalRead(ir1);  //CHECKING ENTERING VEHICLES
  int exit=digitalRead(ir2);   //CHECKING EXIT VEHICLES
    Serial.print("enter  : ");
    Serial.println(ir1);
    Serial.print("exit :");
    Serial.println(ir2);
    if(enter==0 && exit==1){         //   Type 1 ----Vechile is entering
      count=count+1;
    servo.write(90);
    delay(1000);
    lcd.setCursor(8,0);
    lcd.print("Enter ");
    Serial.println("type 1 GATE open ");
    slot();
    while (enter==0 || exit ==0){      //safety logic for servo , not to close until vehicle enter fully 
      enter=digitalRead(ir1);
      exit=digitalRead(ir2);
      delay(500);
    }
    }
    
     else if(exit==0 && enter ==1){        //Type 2 ------ vechile is exit
    servo.write(90);
    delay(1000);
    lcd.setCursor(8,0);
    lcd.print("Exit ");
    Serial.println("type 2 GATE open ");
    count=count-1;
        slot();
    while (exit==0 || enter==0){            //Safety logic that servo not close until vehicle exit completely 
      exit=digitalRead(ir2);
      enter=digitalRead(ir1);
      delay(500);
    }
     }
  else if(exit==0 && enter==0){             //Type 3 ----- One vehicle is entering and other vehicle is exiting at a time
    servo.write(90);        
    lcd.setCursor(8,0);
    lcd.print("Enter and Exit");
    Serial.println("type 3  GATE open ");
    slot();
    while(exit==0 || enter==0){           //Safety logic again , not to close parking gate until vehicle moves completely
      enter=digitalRead(ir1);
      exit=digitalRead(ir2);
      delay(500);
    }
  }
    else if(exit==1 && enter ==1){       //Type 4  ---   No vechile   is entering  or exit 
      servo.write(0);                        
      lcd.setCursor(8,0);
      lcd.print("GATE close");
      Serial.println("GATE close ");
      delay(1000);
      slot();
    }
  
  servo.write(0);
  delay(3000);
  lcd.setCursor(8,0);
  lcd.print("Gate closed");
}
void slot(){
  lcd.setCursor(0,1);
    lcd.print("Avail:");
    lcd.setCursor(6,1);
    lcd.print("5");
    lcd.setCursor(11,1);
    lcd.print("rem:");
    lcd.print(slots-count);

}
