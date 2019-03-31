const int trig_pin = 11;
const int echo_pin = 12;

void setup() {  
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(trig_pin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trig_pin, LOW);

  long duration = pulseIn(echo_pin, HIGH);
  long distance = (duration/2) / 29.1;

  if (distance >= 200 || distance <= 0) {
  Serial.println("Out of range");
  } else {
  Serial.print(distance);
  Serial.println(" cm");
  }
  
  delay(100);
}

