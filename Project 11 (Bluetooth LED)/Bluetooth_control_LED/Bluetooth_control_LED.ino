#include "BluetoothSerial.h"
BluetoothSerial SerialBT;
int state1 = 0, state2 = 0, state3 = 0, state4 = 0;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test");
  Serial.print("BT Started!");
  pinMode(13, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(02, OUTPUT);
}

void loop() {
  if (SerialBT.available()) {
    char x = SerialBT.read();
    Serial.println(x);
    if (x == 'A') {
      state1 = !state1;
      digitalWrite(13, state1);
    }

    else if (x == 'B') {
      state2 = !state2;
      digitalWrite(15, state2);
    }

    else if (x == 'C') {
      state3 = !state3;
      digitalWrite(17, state3);
    }

    else if (x == 'D') {
      state4 = !state4;
      digitalWrite(02, state4);
    }
  }
  delay(20);
}