// servo control test

#include <Servo.h>

Servo servo;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(3) //  connect servo with digital pin 3
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 170; i += 10) {
    servo.write(i);
    delay(500);                        
  }
}
