void setup() {
  Serial.begin(9600);  
}

char remote_input = 's';

void loop() {
  if(Serial.available()) {
  char r_data = Serial.read();
  
  if(r_data != remote_input) {
    remote_input = r_data;
  
    Serial.print(remote_input);
  }
  }
}

