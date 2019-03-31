#include <TimerOne.h>

const int led_pin = 10;

void setup() {
  Timer1.initialize(); 
  Timer1.pwm(led_pin, 0);

  Timer1.setPeriod(1000); // 1000Hz
}

void loop() {
  for(int t_high=0;t_high<=1023;t_high++) {
  Timer1.setPwmDuty(led_pin, t_high);

  delay(1000/100);
  }
}

