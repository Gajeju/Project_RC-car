#include <Servo.h>

Servo face_direction_servo; 
const int servo_pin = 9;

void setup() {
  face_direction_servo.attach(servo_pin);
  face_direction_servo.write(90);
  delay(1000);
}

enum {
  FACING_LEFT,
  FACING_RIGHT,
};

void loop() {
  static unsigned long prev_millis = 0;
  static unsigned long interval_millis = 10;
  static unsigned long facing = FACING_RIGHT;
  static unsigned long facing_angle = 0;

  unsigned long curr_millis = millis();
  if(curr_millis - prev_millis >= interval_millis) {
  prev_millis = curr_millis;
  
  if(facing == FACING_RIGHT) {
    facing_angle ++;
    if(facing_angle == 150) {
    facing = FACING_LEFT;
    }
  } else if(facing == FACING_LEFT) {
    facing_angle --;
    if(facing_angle == 30) {
    facing = FACING_RIGHT;
    }
  }
  face_direction_servo.write(facing_angle);
  } 
}

