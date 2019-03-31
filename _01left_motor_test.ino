// 왼쪽 바퀴 - 전후진

// 핀 선택
const int DIRA = 4;                   // Motor A Direction  (A 회전방향)
const int PWMA = 5;                  // Motor A PWM (A 속도)

void setup() {
  // 왼쪽 바퀴 초기화
  pinMode(DIRA, OUTPUT);

  digitalWrite(DIRA, LOW);
  analogWrite(PWMA, 0); 
}

void loop() {
  // 왼쪽 전진
  digitalWrite(DIRA, HIGH);  
  analogWrite(PWMA, 200);
  
  delay(2000);

  // 왼쪽 정지
  digitalWrite(DIRA, LOW); 
  analogWrite(PWMA, 0);
  
  delay(2000);

  // 왼쪽 후진
  digitalWrite(DIRA, LOW);  
  analogWrite(PWMA, 200);
  
  delay(2000);

  // 왼쪽 정지
  digitalWrite(DIRA, LOW); 
  analogWrite(PWMA, 0);
  
  delay(2000);
}

