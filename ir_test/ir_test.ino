#define ir_1 15
void setup() {
  // put your setup code here, to run once:
  pinMode(ir_1, INPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = digitalRead(ir_1);
  Serial.println(value);
  delay(1000);
}
