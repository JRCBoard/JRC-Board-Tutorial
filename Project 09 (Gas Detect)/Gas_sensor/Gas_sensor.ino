int x;
void setup() {
  pinMode(26, INPUT); // Gas Sensor Input
  pinMode(13, OUTPUT); // LED Output
}
void loop() {
  x = digitalRead(26);
  if (x == 0) {
    digitalWrite(13, 1);
    delay(250);
    digitalWrite(13, 0);
    delay(250);
  } else digitalWrite(13, 0);
}