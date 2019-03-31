const int horn_pin = 17; // A3

void setup() {
  pinMode(horn_pin, OUTPUT);
}

void loop() {
  for(int i = 0; i<100; i++) {
  digitalWrite(horn_pin, HIGH);   
  delay(1);     
  digitalWrite(horn_pin, LOW);  
  delay(1);
  }
  
  delay(100);

  for(int i = 0; i<150; i++) {
  digitalWrite(horn_pin, HIGH);    
  delay(1);     
  digitalWrite(horn_pin, LOW);   
  delay(1);
  }
  
  delay(2000);
}

