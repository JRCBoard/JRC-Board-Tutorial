#define mid_value 2000  //sensor mid value
#define LED 13          //led pin number
#define ldr 5           //ldr sensor pin number

int x; //fot storing sensor data

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  x = analogRead(ldr);
  Serial.println(x);
  (x > 2000) ? digitalWrite(LED, 1) : digitalWrite(LED, 0);
}
