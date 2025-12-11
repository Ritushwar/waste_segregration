int object_pin = 15;
void setup() {
  // put your setup code here, to run once:
  pinMode(object_pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int data = digitalRead(object_pin);
  Serial.println(data);                    // LOW if object detect
  delay(500);
}
