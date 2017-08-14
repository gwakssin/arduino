#include <Wire.h>  // This library is already built in to the Arduino IDE
#include <LiquidCrystal_I2C.h> //This library you can add via Include Library > Manage Library > 
LiquidCrystal_I2C lcd(0x27, 16, 4);
 
void setup()
{
  lcd.init();   // initializing the LCD
  lcd.backlight(); // Enable or Turn On the backlight 
  //lcd.noBacklight(); // turn off backlight
  lcd.setCursor(0, 1);
  lcd.print("14CORE | 16x2  000TEST"); // Start Print text to Line 1
  lcd.setCursor(0, 2);      
  lcd.print("-----------------------"); // Start Print Test to Line 2
}
 
void loop()
{
  // Nothing
}
