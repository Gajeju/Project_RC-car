const int brightness_sensor_pin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {  
  static unsigned long prev_millis = 0;
  const unsigned long interval_millis = 500;

  unsigned long curr_millis = millis();
  if(curr_millis - prev_millis >= interval_millis) {
  prev_millis = curr_millis;
  
  int brightness = analogRead(A0);
  Serial.print("brightness sensor value : ");
  Serial.println(brightness);
  }
}

