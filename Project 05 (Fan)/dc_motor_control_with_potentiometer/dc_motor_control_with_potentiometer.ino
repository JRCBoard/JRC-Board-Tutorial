/*
DC motor control with potentiometer
please connect the buit-in motor driver in the following way:
Motor Driver Pin 9 -> JRC Board Pin 0
Motor Driver Pin 10 -> JRC Board Pin 2
Motor Driver Pin 15 -> JRC Board Pin 15
Motor Driver Pin 4/5/12/13 -> JRC Board Pin GND
Motor Driver Pin 16 -> JRC Board Pin 5V Supply
Motor Driver Pin 8 -> Battery Positive Terminal
Motor Driver Pin 4/5/12/13 -> Battery Negative Terminal
Motor Driver Pin 11 -> with one pin of the DC motor
Motor Driver Pin 14 -> with other pin of the DC motor
*/


void setup() {
  ledcSetup(0, 1000, 8);
  ledcAttachPin(0, 0);
  pinMode(2, OUTPUT);
  pinMode(15, OUTPUT);
}
void loop() {
  int p = analogRead(26);  //connect a potentiometer to pin 26
  p = map(p, 0, 4095, 0, 511);

  if (p == 256) {
    digitalWrite(15, 0);
    digitalWrite(2, 0);
  }

  else if (p < 256) {
    digitalWrite(15, 1);
    digitalWrite(2, 0);
    ledcWrite(0, 256 - p);
  }

  else if (p > 256) {
    digitalWrite(15, 0);
    digitalWrite(2, 1);
    ledcWrite(0, p - 256);
  }
}