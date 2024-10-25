
char number  = ' ';
int state = 1;

void init_serialBus() {
  Serial2.begin(115200);
  pinMode(PC13, OUTPUT);
}

void serialBus_check() {
  String receivedMessage;

  while (true) {
    if (Serial2.available()) {
      char receivedChar = Serial2.read();
      // Serial.println(receivedChar);

      if ( receivedChar == '\n') {
        if ( receivedMessage == "201") {
          Serial.println(receivedMessage);
          Serial2.println("201\n");
          break;
        }
        receivedMessage = "";
      }
      else {
        receivedMessage += receivedChar;
      }

    }

  }

}

