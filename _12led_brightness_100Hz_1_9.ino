const int led_pin = 3;

void setup() {
  pinMode(led_pin, OUTPUT);
}

void loop() {
  digitalWrite(led_pin, HIGH);
  delay(1);
  digitalWrite(led_pin, LOW);
  delay(9);
}

