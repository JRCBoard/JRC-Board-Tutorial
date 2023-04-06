#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

DHT dht(23, DHT11);

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.init();
  lcd.backlight();
}

void loop() {
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  lcd.setCursor(0, 0);
  lcd.print("HUMIDITY TEMP");
  lcd.setCursor(1, 1);
  lcd.print(String(h) + "%");
  lcd.setCursor(10, 1);
  lcd.print(String(t) + "C");
}