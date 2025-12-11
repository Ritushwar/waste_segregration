const int rain_drop = 32;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(rain_drop, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int raw_data = analogRead(rain_drop);
  Serial.println(raw_data);
  delay(500);
}
