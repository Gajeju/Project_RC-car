// RC카 전후진

// 왼쪽 바퀴 - 전후진

const int DIRA = 4;                   // Motor A Direction (A 회전방향)
const int PWMA = 5;                  // Motor A PWM (A 속도)

// 오른쪽 바퀴 - 전후진

const int DIRB = 7;                   // Motor B Direction  (B 회전방향)
const int PWMB = 6;                  // Motor B PWM (B 속도)

void setup() {
  // 왼쪽 바퀴 초기화
  pinMode(DIRA, OUTPUT);

  digitalWrite(DIRA, LOW);
  analogWrite(PWMA, 0);

  // 오른쪽 바퀴 초기화
  pinMode(DIRB, OUTPUT);

  digitalWrite(DIRB, LOW);
  analogWrite(PWMB, 0); 
}

void loop() {
  // 전진
  // 왼쪽 전진
  digitalWrite(DIRA, HIGH);  
  analogWrite(PWMA, 200);
  // 오른쪽 전진
  digitalWrite(DIRB, HIGH);  
  analogWrite(PWMB, 200);

  delay(2000);

  // 정지
  // 왼쪽 정지 
  digitalWrite(DIRA, LOW); 
  analogWrite(PWMA, 0);
  // 오른쪽 정지
  digitalWrite(DIRB, LOW); 
  analogWrite(PWMB, 0);

  delay(2000);

  // 후진
  // 왼쪽 후진
  digitalWrite(DIRA, LOW);  
  analogWrite(PWMA, 200);
  // 오른쪽 후진
  digitalWrite(DIRB, LOW);  
  analogWrite(PWMB, 200); 
  
  delay(2000);

  // 정지
  // 왼쪽 정지
  digitalWrite(DIRA, LOW); 
  analogWrite(PWMA, 0);
  // 오른쪽 정지
  digitalWrite(DIRB, LOW); 
  analogWrite(PWMB, 0);

  delay(2000);
}

