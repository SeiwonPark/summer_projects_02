#include <Servo.h>

Servo servo;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(3) //  3번 디지털 핀에 서보모터를 연결
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 170; i += 10) {   // 딜레이 500ms(0.5초) 마다 10도씩 회전
    servo.write(i);
    delay(500);                        
  }
}
