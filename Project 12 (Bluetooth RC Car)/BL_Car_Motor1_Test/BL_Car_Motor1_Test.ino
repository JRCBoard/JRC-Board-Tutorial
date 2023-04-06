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
  motor1(255); delay(5000); //motor1 will move forward for 5 seconds
  motor1(0); delay(2000); //motor1 will stop for 2 seconds
  motor1(-100); delay(5000); //motor1 will move backward at half speed for 5 seconds
  motor1(-255); delay(5000); //motor1 will move backward at full speed for 5 seconds
}
void motor1(int a) {
  if (a > 0) {
    digitalWrite(M1_front, 1);
    digitalWrite(M1_back, 0);
  } else {
    a = -a;
    digitalWrite(M1_front, 0);
    digitalWrite(M1_back, 1);
  }
  ledcWrite(0, a);
}