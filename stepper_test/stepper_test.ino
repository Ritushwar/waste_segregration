#include <Stepper.h>
Stepper mystepper(2048, 14, 26, 27, 25);   // IN1, IN3, IN2, IN4
int motorspeed = 20;
int STEPS_PER_REV = 2048;
long angle_to_steps(float angle) {
  long targetSteps = (angle * STEPS_PER_REV) / 360.0;
  return targetSteps;
}
void setup() {
  // put your setup code here, to run once:
  mystepper.setSpeed(motorspeed);
  Serial.begin(115200);
  Serial.println("Moving");
  //long required_steps = angle_to_steps(90);
  mystepper.step(-100);
  delay(1000);

  // De energized the coil
  digitalWrite(14, LOW);
  digitalWrite(26, LOW);
  digitalWrite(27, LOW);
  digitalWrite(25, LOW);
  delay(1000);
  digitalWrite(14, HIGH);
  digitalWrite(26, HIGH);
  digitalWrite(27, HIGH);
  digitalWrite(25, HIGH);
}
void loop() {
  // put your main code here, to run repeatedly:
}
