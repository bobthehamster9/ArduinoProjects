int light = 13;
int light1 = 12;
int light2 = 11;
int light3 = 10;

void setup() {
  pinMode(light, OUTPUT);
  pinMode(light1, OUTPUT);
  pinMode(light2, OUTPUT);
  pinMode(light3, OUTPUT);
}

void loop() {
  digitalWrite(light, HIGH);
  delay(500);
  digitalWrite(light, LOW);
  digitalWrite(light1, HIGH);
  delay(500);
  digitalWrite(light1, LOW);
  digitalWrite(light2, HIGH);
  delay(500);
  digitalWrite(light2, LOW);
  digitalWrite(light3, HIGH);
  delay(500);
  digitalWrite(light3, LOW);

}
