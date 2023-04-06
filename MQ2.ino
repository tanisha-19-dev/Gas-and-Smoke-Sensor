#include <LiquidCrystal_I2C.h>
#define MQ2pin 0
int lcdColumns = 16;
int lcdRows = 2;

// set LCD address, number of columns and rows
// if you don't know your display address, run an I2C scanner sketch
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  
float sensorValue;  //variable to store sensor value

void setup() {
  lcd.init();
  // turn on LCD backlight                      
  lcd.backlight();
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  Serial.begin(9600); // sets the serial port to 9600
  Serial.println("MQ2 warming up!");
  delay(20000); // allow the MQ2 to warm up
}

void loop() {
  sensorValue = analogRead(MQ2pin); // read analog input pin 0

  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);
  if(sensorValue >= 130)
  {
   digitalWrite(13,HIGH);
   lcd.setCursor(0, 0);
  lcd.print("Alert");
   digitalWrite(12,LOW);
  }
  else
  {
   digitalWrite(13,LOW);
   digitalWrite(12,HIGH);
   lcd.setCursor(0, 0);
  lcd.print("Normal");
  }
  delay(1000); // wait 2s for next reading
  lcd.clear();
}
