#include "BluetoothSerial.h"
BluetoothSerial SerialBT;
int LED1 = 14, LED2 = 32;
int M1_front = 17, M1_back = 4, M1_pwm = 2;
int M2_front = 16, M2_back = 0, M2_pwm = 15;

void setup() {
  Serial.begin(9600);
  SerialBT.begin("Bluetooth RC Car");
  Serial.print("BT Started!");
  ledcSetup(0, 1000, 8);
  ledcAttachPin(M1_pwm, 0);
  ledcSetup(1, 1000, 8);
  ledcAttachPin(M2_pwm, 1);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(M1_front, OUTPUT);
  pinMode(M1_back, OUTPUT);
  pinMode(M2_front, OUTPUT);
  pinMode(M2_back, OUTPUT);
}

void loop() {
  motor2(255); delay(5000);
  motor2(0); delay(2000);
  motor2(-100); delay(5000);
  motor2(-255); delay(5000);
}

void motor2(int a) {
  if (a > 0) {
    digitalWrite(M2_front, 1);
    digitalWrite(M2_back, 0);
  } else {
    a = -a;
    digitalWrite(M2_front, 0);
    digitalWrite(M2_back, 1);
  }
  ledcWrite(1, a);
}