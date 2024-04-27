#include <LiquidCrystal_I2C.h>
#include <Servo.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myservo;  
#define LED 4
#define Buzzer 3
#define Sensor A1
int servoPin = 9;
void setup() {
  Serial.begin(9200);
  lcd.init();
  myservo.attach(servoPin);
  lcd.backlight();
  pinMode(LED, OUTPUT);
  pinMode(Buzzer, OUTPUT);
}

void loop() {
  myservo.write(0);
  delay(1000);
  int value = analogRead(Sensor);
  lcd.setCursor(0, 0);
  lcd.print("Value :");
  lcd.print(value);
  lcd.print("  ");

  if (value > 400) {
    digitalWrite(LED, HIGH);
    digitalWrite(Buzzer, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("GAS Detected!");
    myservo.write(90);
    delay(1000);
  } else {
    digitalWrite(LED, LOW);
    digitalWrite(Buzzer, LOW);
    lcd.setCursor(0, 1);
    myservo.write(270);
    delay(1000);
    lcd.print("             ");
  }
}
