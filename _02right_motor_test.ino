// 오른쪽 바퀴 - 전후진

// 핀 선택
const int DIRB = 7;                   // Motor B Direction  (B 회전방향)
const int PWMB = 6;                  // Motor B PWM (B 속도)

void setup() {
  // 오른쪽 바퀴 초기화
  pinMode(DIRB, OUTPUT);

  digitalWrite(DIRB, LOW);
  analogWrite(PWMB, 0); 
}

void loop() {
  // 오른쪽 전진
  digitalWrite(DIRB, HIGH);  
  analogWrite(PWMB, 200);
  
  delay(2000);

  // 오른쪽 정지
  digitalWrite(DIRB, LOW); 
  analogWrite(PWMB, 0);
  
  delay(2000);

  // 오른쪽 후진
  digitalWrite(DIRB, LOW);  
  analogWrite(PWMB, 200);
  
  delay(2000);

  // 오른쪽 정지
  digitalWrite(DIRB, LOW); 
  analogWrite(PWMB, 0);
  
  delay(2000);
}

