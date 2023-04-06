#include <ESP32Servo.h>
Servo myservo;

void setup() {
  myservo.attach(19);
}

void loop() {
  for (int i = 0; i <= 180; i++) {
    myservo.write(p);
    delay(10);
  }
  for (int i = 180; i >= 0; i--) {
    myservo.write(p);
    delay(10);
  }
}