const int front_left_pin = 2;
const int front_right_pin = 19; //A5
const int rear_left_pin = 3;
const int rear_right_pin = 18; //A4

void setup() {
  pinMode(front_left_pin, OUTPUT);
  pinMode(front_right_pin, OUTPUT);
  pinMode(rear_left_pin, OUTPUT);
  pinMode(rear_right_pin, OUTPUT);

  digitalWrite(front_left_pin, LOW);
  digitalWrite(front_right_pin, LOW);
  digitalWrite(rear_left_pin, LOW);
  digitalWrite(rear_right_pin, LOW);
}

void loop() {
  digitalWrite(front_left_pin, HIGH);
  digitalWrite(front_right_pin, HIGH);
  digitalWrite(rear_left_pin, HIGH);
  digitalWrite(rear_right_pin, HIGH);
  
  delay(1000);
  
  digitalWrite(front_left_pin, LOW);
  digitalWrite(front_right_pin, LOW);
  digitalWrite(rear_left_pin, LOW);
  digitalWrite(rear_right_pin, LOW);
  
  delay(1000);
}

