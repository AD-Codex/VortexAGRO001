// STM32-1 serial com check, sending-1001 , need-1001
// STM32-2 serial com check, sending-2001 , need-2001
// time limit 3s
// if time exceed try in 5s

int Serial_com = 0;
int time_space = 0;


void init_serial() {
  SerialPort.begin(115200, SERIAL_8N1, 16, 17);  //uart 2

}


void stm32_check() {
  String receivedMessage;
  int time_start = 0;

  // communicate with STM 1 ..............
  SerialPort.println("1001\n");

  time_start = millis();
  while (true) {
    if ( (millis() - time_start) > 3000) {
      // Serial.println("STM 1 not detected..");
      Serial_com = 0;
      break;
    }
    else if ( SerialPort.available()) {
      char receivedChar = SerialPort.read();
      // Serial.println(receivedChar);
      if ( receivedChar == '\n') {
        Serial.println(receivedMessage);
        if ( receivedMessage == "1001") {
          Serial.println("STM 1 detected..");
          Serial_com = 1;
          break;
        }
        receivedMessage = "";
      }
      else {
        receivedMessage =  receivedMessage + receivedChar;
      }
    }

  }


  // communicate with STM 2 ..............
  SerialPort.println("2001\n");

  time_start = millis();
  while (true) {
    if ( (millis() - time_start) > 3000) {
      // Serial.println("STM 1 not detected..");
      Serial_com = 0;
      break;
    }
    else if ( SerialPort.available()) {
      char receivedChar = SerialPort.read();
      if ( receivedChar == '\n') {
        // Serial.println(receivedMessage);
        if ( receivedMessage == "2001") {
          Serial.println("STM 2 detected..");
          Serial_com = 1;
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


void serialCom_check() {
  Serial.println("checking serial connecting -----------");
  dash_0005.display_(0);

  while (true) {
    stm32_check();
    if (Serial_com == 1) {
      Serial.println("serial connecting completed -----------");
      break;
    }
    else {
      Serial.println("serial connection checking faile. Recheck in 5s");
      dash_0010.display_(0);
      delay(5000);
    }

  }

}
