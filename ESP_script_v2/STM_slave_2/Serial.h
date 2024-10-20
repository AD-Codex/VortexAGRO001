
char number  = ' ';
int state = 1;

void init_serialBus() {
  Serial2.begin(115200);
  pinMode(PC13, OUTPUT);
}

void serialBus_check() {
  if (Serial2.available()) {
    char number = Serial2.read();
    Serial.println(number);
    if ( number == 'A') {
      state = state ^ 1;
    }
  }

  if (state == 1) {
    digitalWrite(PC13, HIGH);
  }
  else {
    digitalWrite(PC13, LOW);
  }

}

