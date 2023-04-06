#include <LiquidCrystal.h>
int rs = 14, en = 13, d4 = 5, d5 = 23, d6 = 19, d7 = 18;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  lcd.print("hello, world!");
  lcd.setCursor(0, 1);
  lcd.print("display test!");
}

void loop() {
}