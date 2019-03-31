const int led_pin = 3;

void setup() {
  pinMode(led_pin, OUTPUT);
}

unsigned long current_millis = 0;
unsigned long prev_millis = 0;
unsigned long interval_millis = 1000;

void loop() {
  
  for(int t_high=0;t_high<=255;t_high+=25) {
  while(1) {          
    analogWrite(led_pin, t_high);

    current_millis = millis();
    if(current_millis - prev_millis >= interval_millis) {
    prev_millis = current_millis;
    break;
    }
  }
  }
}

