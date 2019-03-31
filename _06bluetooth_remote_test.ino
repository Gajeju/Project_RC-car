void setup() {
  Serial.begin(9600);  
}

void loop() {
  if(Serial.available()) {
  char r_data = Serial.read();
  
  Serial.print(r_data);
  }
}

