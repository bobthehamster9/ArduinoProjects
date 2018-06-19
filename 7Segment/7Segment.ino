int pins[]={13, 12, 11, 10, 9, 8, 7};

void setup() {
  for(int i=0;i<7;i++){
    pinMode(pins[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  if(Serial.available() > 0){
    int incomingByte = Serial.read();

    switch(incomingByte){
     case 97:
      //a segment
      turnOffPins();
      digitalWrite(pins[0], LOW);
      break;
     case 98:
      //b segment
      turnOffPins();
      digitalWrite(pins[1], LOW);
      break;
     case 99:
      //c segment
      turnOffPins();
      digitalWrite(pins[2], LOW);
      break;
     case 100:
      //d segment
      turnOffPins();
      digitalWrite(pins[3], LOW);
      break;
     case 101:
      //e segment
      turnOffPins();
      digitalWrite(pins[4], LOW);
      break;
     case 102:
      //f segment
      turnOffPins();
      digitalWrite(pins[5], LOW);
      break;
     case 103:
      //g segment
      turnOffPins();
      digitalWrite(pins[6], LOW);
      break;
    }
  }

}

void turnOffPins(){
    for(int i=0;i<7;i++){
    digitalWrite(pins[i], HIGH);
  }
}

