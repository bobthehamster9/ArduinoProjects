int wirePin = 13;

void setup() {
  Serial.begin(57600);
  pinMode(wirePin, INPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  int wireState = digitalRead(wirePin);
  Serial.println(wireState);
  delay(100);

  if(wireState == 0){
    digitalWrite(12, LOW);
    digitalWrite(11, HIGH);
  }

  else if (wireState == 1){
    digitalWrite(12, HIGH);
    digitalWrite(11, LOW);
  }
}
