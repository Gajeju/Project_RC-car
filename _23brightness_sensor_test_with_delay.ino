const int brightness_sensor_pin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {  
  int brightness = analogRead(brightness_sensor_pin);
  Serial.print("brightness sensor value : ");
  Serial.println(brightness);
  delay(500);
}

