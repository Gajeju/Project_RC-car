#include <PinChangeInterrupt.h>

const int trig_pin = 11;
const int echo_pin = 12;

void setup() {  
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);

  attachPCINT(digitalPinToPCINT(echo_pin), echoIsr, CHANGE);

  Serial.begin(9600);
}

unsigned long echo_duration = 0;

void echoIsr(void) {    
  static volatile unsigned long echo_begin = 0;
  static volatile unsigned long echo_end = 0;

  unsigned int echo_pin_state = digitalRead(echo_pin);
  
  if(echo_pin_state == HIGH) {
  echo_begin = micros();
  } else {
  echo_end = micros();
  echo_duration = echo_end - echo_begin;
  }
}

void loop() {
  static unsigned long prev_millis = 0;
  const unsigned long interval_millis = 20;

  unsigned long curr_millis = millis();
  if(curr_millis - prev_millis >= interval_millis) {
  prev_millis = curr_millis;
  
  if(echo_duration == 0) { // triggering
    digitalWrite(trig_pin, LOW);  
    delayMicroseconds(2); 
    digitalWrite(trig_pin, HIGH);
    delayMicroseconds(10); 
    digitalWrite(trig_pin, LOW);
  } else {
    unsigned long distance = echo_duration / 58;
    if (distance >= 200 || distance <= 0) {
    Serial.println("Out of range");
    } else {
    Serial.print(distance);
    Serial.println(" cm");
    }
  
    echo_duration = 0;
  }
  } 
}

