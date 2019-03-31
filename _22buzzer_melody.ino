#include <TimerOne.h>

const int led_pin = 10;

const int melody[] = {
  262, 294, 330, 349, 393, 440, 494, 523,  
};

void setup() {
  Timer1.initialize();
  Timer1.pwm(led_pin, 100);
}

void loop() {
  for(int note=0;note<8;note++) {
  Timer1.setPeriod(1000000/melody[note]);
  
  delay(1000);
  }
}

