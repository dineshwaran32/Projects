#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
int scrollSpeed = 300;  // Adjust the scrolling speed (lower value = faster scroll)

void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Hello, world!");
  lcd.setCursor(2,1);
  lcd.print("Ywrobot Arduino!");
  delay(2000);  // Delay to show initial text
}

void loop()
{
  // Scroll "Ywrobot Arduino!"
  for (int i = 0; i < 16; i++) {
    lcd.scrollDisplayLeft();
    delay(scrollSpeed);
  }
  delay(1000);  // Delay at the end of the scroll
   // Delay at the end of the scroll
}
