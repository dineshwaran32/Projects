#include "DHT.h"
#define Dpin 2
#include <Wire.h> 
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
int scrollSpeed = 300;

const int t_pin = 9;
const int e_pin = 10;
long duration;
int dis_cm;
DHT dht(Dpin, DHT11);

void setup() {
  // put your setup code here, to run once:
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  pinMode(t_pin,OUTPUT);
  pinMode(e_pin,INPUT);
  Serial.begin(9600);
  
  dht.begin();


}

void loop() {
  // put your main code here, to run repeatedly:

  float humi  = dht.readHumidity();
  float tempC = dht.readTemperature();
  float tempF = dht.readTemperature(true);
  
   digitalWrite(t_pin, LOW);
   delayMicroseconds(2);
   digitalWrite(t_pin, HIGH);
   delayMicroseconds(10);
   digitalWrite(t_pin, LOW);
   duration = pulseIn(e_pin,HIGH);
   dis_cm = (duration * 0.034) / 2;

   if(dis_cm < 10 || dis_cm == 1184)
   {
    Serial.println("Stock low ");
    lcd.setCursor(5,0);
    lcd.print("Stock low");
   }
   else
   {
    Serial.println("Stock ok");
    lcd.setCursor(5,0);
    lcd.print("Stock ok");
   }
   Serial.print("Distance (cm): ");
   Serial.println(dis_cm);
   if (isnan(humi) || isnan(tempC) || isnan(tempF)) 
   {
    Serial.println("Failed to read from DHT11 sensor!");  
   } 
   else 
   {
      lcd.setCursor(1,1);
      Serial.print("Humidity: ");
      Serial.print(humi);
      Serial.print("%");
      Serial.print("  |  ");
      lcd.print("Temperatue"); 
      Serial.print("Temperature: ");
      lcd.print(tempC);
      Serial.print(tempC);
      Serial.print("°C ~ ");
      Serial.print(tempF);
      Serial.println("°F");
      if(tempC > 35)
      {
        Serial.println("Temp is high");
        lcd.print("HIGH!");
      }
      else
      {
        Serial.println("Temp is normal");
        lcd.print("NORMAL!");
      }
    }


    for (int i = 0; i < 16; i++) {
    lcd.scrollDisplayLeft();
    delay(scrollSpeed);
  }
   delay(1000);
}
