
// if 1001 recive send 1001

char number  = ' ';
int state = 1;

void init_serialBus() {
  Serial2.begin(115200);
  pinMode(PC13, OUTPUT);
}

void serialBus_check( String receivedMessage) {

  Serial.println("sending " +receivedMessage);
  Serial2.println("1001\n");


  // String receivedMessage;

  // while (true) {
  //   if (Serial2.available()) {
  //     char receivedChar = Serial2.read();
  //     // Serial.println(receivedChar);

  //     if ( receivedChar == '\n') {
  //       if ( receivedMessage == "1001") {
  //         Serial.println(receivedMessage);
  //         Serial2.println("1001\n");
  //         break;
  //       }
  //       receivedMessage = "";
  //     }
  //     else {
  //       receivedMessage += receivedChar;
  //     }

  //   }

  // }

}

