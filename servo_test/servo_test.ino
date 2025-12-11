#include <ESP32Servo.h>
Servo myServo;
int servo_pin = 5;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myServo.attach(servo_pin);
}

void loop() {
  // put your main code here, to run repeatedly:
  //myServo.write(140);      // 140 -open then 30-close
  Serial.println("Open");
  delay(1000);
  myServo.write(30);
  Serial.println("close");
  delay(1000);
}
