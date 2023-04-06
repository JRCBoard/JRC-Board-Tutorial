#include <ESP32Servo.h>
Servo myservo;

void setup() {
  myservo.attach(19);
}

void loop() {
  int p = analogRead(26);
  p = map(p, 0, 4095, 0, 180);
  myservo.write(p);
}