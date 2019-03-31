const int horn_pin = 17; // A3

void setup() {
  pinMode(horn_pin, OUTPUT);
}

void loop() {
  static unsigned long prev_millis = 0;
  const unsigned long interval_millis = 1;
  static int horn_cnt = 0; 

  unsigned long curr_millis = millis();
  if(curr_millis - prev_millis >= interval_millis) {
  prev_millis = curr_millis;

  horn_cnt++;
  if(horn_cnt == 1000) {
    horn_cnt = 0;
  } else if(horn_cnt<200) {
    digitalWrite(horn_pin, horn_cnt%2);
  } else if((200 <= horn_cnt) && (horn_cnt < 300)) {
      // do nothing
  } else if((300<=horn_cnt) && (horn_cnt<600)) {
    digitalWrite(horn_pin, horn_cnt%2);
  } else if((600<=horn_cnt) && (horn_cnt<1000)) {
     // do nothing
  }
  }
}

