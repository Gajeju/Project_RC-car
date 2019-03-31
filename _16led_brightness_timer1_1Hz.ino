#include <TimerOne.h>

const int led_pin = 10;

void setup() {
  Timer1.initialize(); 
  Timer1.pwm(led_pin, 0);

  Timer1.setPeriod(1000000); // 1Hz
  Timer1.setPwmDuty(led_pin, 511);
}

void loop() {}

