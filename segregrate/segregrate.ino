#include<Stepper.h>
#include <ESP32Servo.h>
const int photo_electric = 15;        // digital read
const int rain_drop = 32;            // analog read
const int buzzer = 12;               // buzzer output
const int IN1 = 14;                 // for stepper motor
const int IN2 = 27;                 // for stepper motor
const int IN3 = 26;                 // for stepper motor
const int IN4 = 25;                 // for stepper motor
const int servo_pin = 5;           // for servo motor
const int threshold = 3500;          // threshold value of moisture
const int stepper_speed = 10;        // speed for stepper motor
Stepper myStepper(2048, IN1, IN3, IN2, IN4);   // define objectt
int STEPS_PER_REV = 2048;
Servo myServo;

void play_buzzer(int time){
  digitalWrite(buzzer, HIGH);
  delay(time);
  digitalWrite(buzzer, LOW);
  delay(time);
}
long angle_to_steps(float angle) {
  long targetSteps = (angle * STEPS_PER_REV) / 360.0;
  return targetSteps;
}
void cool_motor(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(1000);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(photo_electric, INPUT_PULLUP);
  pinMode(rain_drop, INPUT);
  pinMode(buzzer, OUTPUT);
  myServo.attach(servo_pin);
  myStepper.setSpeed(stepper_speed);
  play_buzzer(1000);
  myServo.write(30);
}

void loop() {
  // put your main code here, to run repeatedly:
  int object_read = digitalRead(photo_electric);
  Serial.println(object_read);
  if(object_read==LOW){
    Serial.println("Object detected");
    play_buzzer(1000);
    object_read = HIGH;
    Serial.println("Object detected");
    int rain_drop_read = analogRead(rain_drop);
    if (rain_drop_read > threshold){
      Serial.println("Drop into dry bucket");
      long required_steps = angle_to_steps(195);
      myStepper.step(required_steps);        // move bucket below the chimney
      Serial.println("Getting Dry Bucket");
      delay(500);
      cool_motor();

      myServo.write(140);         // open the object
      delay(1000);

      myServo.write(30);          // close the chimney
      delay(1000);
      myStepper.step(-required_steps);
      Serial.println("Moving Dry Bucket");
      cool_motor();
      play_buzzer(500);
      delay(500);
    }
    else{
      Serial.println("Drop into wet bucket");
      delay(1000);

      myServo.write(140);         // open the object
      delay(1000);

      myServo.write(30);          // close the chimney
      delay(1000);
      play_buzzer(500);
    }
  }else{
    Serial.println("No object detected");
    cool_motor();
  }
}
