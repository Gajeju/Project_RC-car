void setup() {
  remote_setup();
  motor_setup();
}

void loop(){
  remote_loop();
  motor_loop();
}

void remote_setup() {
  Serial.begin(9600);
}

void remote_loop() {
  check_remote_input();
  distribute_remote_input();
}

char remote_input;
bool remote_input_changed = false;

void check_remote_input() {
  if(Serial.available()) {
    remote_input = Serial.read();
    remote_input_changed = true;
  }
}

enum {
  GOFORWARD = 'f',
  GOBACKWARD = 'b',
  TURNRIGHT = 'l',
  TURNLEFT = 'r',
  STOP = 's',
};

char driving_action = STOP;
bool driving_action_changed = false;

void distribute_remote_input() {
  if(remote_input_changed) {
    remote_input_changed = false;

    if(remote_input == GOFORWARD ||
       remote_input == GOBACKWARD ||
       remote_input == TURNLEFT ||
       remote_input == TURNRIGHT ||
       remote_input == STOP) {
        driving_action = remote_input;
        driving_action = true;
       }
  }
}

//왼쪽 바퀴 - 전후진

const int DIRA = 4;
const int PWMA = 5;

//오른쪽 바퀴 - 전후진

const int DIRB = 7;
const int PWMB = 6;

void motor_setup() {
  //왼쪽 바퀴 초기화
  pinMode(DIRA, OUTPUT);

  digitalWrite(DIRA,LOW);
  analogWrite(PWMA,0);

  //오른쪽 바퀴 초기화

 pinMode(DIRB, OUTPUT);

 digitalWrite(DIRB, LOW);
 analogWrite(PWMB, 0);
}

void motor_loop() {
  process_driving_action();
}

void process_driving_action() {
  if(driving_action_changed) {
    driving_action_changed = false;

    if(driving_action == GOFORWARD) {
      go_forward();
    } else if (driving_action == GOBACKWARD) {
      go_backward();
    } else if (driving_action == TURNLEFT) {
      turn_left();
    } else if (driving_action == TURNRIGHT) {
      turn_right();
    } else if (driving_action == STOP){
      stop_driving();
    }
  }
}

void go_forward() {
  //전진
  //왼쪽전진
  digitalWrite(DIRA, HIGH);
  analogWrite(PWMA, 200);
  //오른쪽 전진
  digitalWrite(DIRB, HIGH);
  analogWrite(PWMB, 200);
}

void go_backward() {
  //후진
  //왼쪽 전진
  digitalWrite(DIRA, LOW);
  analogWrite(PWMA,200);
  //오른쪽 전진
  digitalWrite(DIRB, LOW);
  analogWrite(PWMB,200);
}

void turn_left() {
  //좌회전
  //왼쪽 후진
  digitalWrite(DIRA, LOW);
  analogWrite(PWMA, 200);
  //오른쪽 전진
  digitalWrite(DIRB, LOW);
  analogWrite(PWMB, 200);
}

void turn_right() {
  //우회전
  //왼쪽 전진
  digitalWrite(DIRA, HIGH);
  analogWrite(PWMA, 200);
  //오른쪽 후진
  digitalWrite(DIRB, LOW);
  analogWrite(PWMB, 200);
}

void stop_driving() {
  //정지
  //왼쪽 정지
  digitalWrite(DIRA, LOW);
  analogWrite(PWMA,0);
  //오른쪽 정지
  digitalWrite(DIRB,LOW);
  analogWrite(PWMB,0);
}
