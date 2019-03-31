const int trig_pin = 11;
const int echo_pin = 12;

void setup() {  
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);

  Serial.begin(9600);
}

void loop() {
  static unsigned long prev_millis = 0;
  const unsigned long interval_millis = 100;

  unsigned long curr_millis = millis();
  if(curr_millis - prev_millis >= interval_millis) {
  prev_millis = curr_millis;
  
  digitalWrite(trig_pin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trig_pin, LOW);

  unsigned long t_begin = micros();
  long duration = pulseIn(echo_pin, HIGH);
  unsigned long t_end = micros();
  Serial.print("echo time length : ");
  Serial.print(t_end - t_begin);
  Serial.println(" us");
  
  long distance = (duration/2) / 29.1;
  
  if (distance >= 200 || distance <= 0) {
    Serial.println("Out of range");
  } else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  }  
}

