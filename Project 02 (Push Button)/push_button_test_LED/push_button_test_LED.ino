#define LED 13
#define button 5

int x;
void setup() {
  pinMode(button, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
}
void loop() {
  x = digitalRead(button);
  if (x == 0) { //if pressed, blink the LED 2 times
    digitalWrite(LED, 1); delay(500);
    digitalWrite(LED, 0); delay(500); 
    digitalWrite(LED, 1); delay(500);
    digitalWrite(LED, 0); delay(500);
  } 
  
  else digitalWrite(LED, 0);
}