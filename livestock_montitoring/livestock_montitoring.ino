#include "DHT.h"
#include <Wire.h> 
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define Dpin 2

LiquidCrystal_I2C lcd(0x27, 16, 4);

int scrollSpeed = 800;

const int wtpin = 3;
const int wepin = 4;
const int otpin = 5;
const int oepin = 6;
const int stpin = 9;
const int sepin = 10;
const int rpin = 13;

long duration;
int dis_cm;
int waterdistance,outsidedistance,stockdistance;
DHT dht(Dpin, DHT11);

void setup() {
  // put your setup code here, to run once:
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  pinMode(wtpin,OUTPUT);
  pinMode(wepin,INPUT);
  pinMode(otpin,OUTPUT);
  pinMode(oepin,INPUT);
  pinMode(stpin,OUTPUT);
  pinMode(sepin,INPUT);
  pinMode(rpin,OUTPUT);
  Serial.begin(9600);
  dht.begin();
 
}

void loop() {
  // put your main code here, to run repeatedly:

  float humi  = dht.readHumidity();
  float tempC = dht.readTemperature();
  float tempF = dht.readTemperature(true);
  
  waterdistance   = ultrasonic(wtpin,wepin);
  outsidedistance = ultrasonic(otpin,oepin);
  stockdistance   = ultrasonic(stpin,sepin);
  
  if(stockdistance > 10 || stockdistance == 1184)
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
  Serial.print("Stock Distance (cm): ");
  Serial.println(stockdistance);


  if(waterdistance > 1 && tempC<35)
  {
    Serial.println("Water low ");
    lcd.setCursor(9,1);
    lcd.print("Water low");
    digitalWrite(rpin,HIGH);
  }
  else
  {
    Serial.println("Water normal");
    lcd.setCursor(9,1);
    lcd.print("Water normal");
    digitalWrite(rpin,LOW);
  }
  Serial.print("Water Distance (cm): ");
  Serial.println(waterdistance);


  if(outsidedistance <20  || outsidedistance == 1184)
  {
    Serial.println(" Movement Detected ");
    lcd.setCursor(5,2);
    lcd.print("Movement Detected ");
  }
  else
  {
    Serial.println("Movement not Detected ");
    lcd.setCursor(5,2);
    lcd.print("Movement not Detected ");
  }
  Serial.print("Outside Distance (cm): ");
  Serial.println(outsidedistance);


  
   if (isnan(humi) || isnan(tempC) || isnan(tempF)) 
   {
    Serial.println("Failed to read from DHT11 sensor!");  
   } 
   else 
   {
      lcd.setCursor(1,3);
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


int ultrasonic(int tpin , int epin)
{
  digitalWrite(tpin, LOW);
   delayMicroseconds(2);
   digitalWrite(tpin, HIGH);
   delayMicroseconds(10);
   digitalWrite(tpin, LOW);
   duration = pulseIn(epin,HIGH);
   dis_cm = (duration * 0.034) / 2;
   return dis_cm;
}
