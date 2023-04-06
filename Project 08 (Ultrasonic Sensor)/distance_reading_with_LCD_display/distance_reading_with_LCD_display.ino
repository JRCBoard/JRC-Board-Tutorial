i #include<Wire.h>
#include <LiquidCrystal_I2C.h>
  LiquidCrystal_I2C lcd(0x27, 16, 2);
int trig = 2, echo = 0;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop() {
  lcd.setCursor(0, 1);
  lcd.print("Distance:");
  int x = reading();
  lcd.print(String(x));
  lcd.print("cm ");
  delay(50);
}

int reading() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long duration = pulseIn(echo, HIGH);
  int distance = duration * 0.0343 / 2;
  return distance;
}