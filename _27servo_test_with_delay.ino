#include <Servo.h>

Servo face_direction_servo; 
const int servo_pin = 9;

void setup() {
  face_direction_servo.attach(servo_pin);
  face_direction_servo.write(90);
  delay(1000);
}

void loop() {
  for(int angle = 0; angle < 180; angle ++) { 
  face_direction_servo.write(angle);
  delay(10);
  }
  for(int angle = 180; angle > 0; angle --) { 
  face_direction_servo.write(angle);
  delay(10);
  }
}

