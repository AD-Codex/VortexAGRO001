// STM32-1 serial com check, sending-1001 , need-1001
// STM32-2 serial com check, sending-2001 , need-2001
// time limit 3s
// if time exceed try in 5s

int time_space = 0;


// initializing serial bus --------------------------------------
void init_serial() {
  SerialPort.begin(115200, SERIAL_8N1, 16, 17);  //uart 2

}

// STM32 chip check Fn ------------------------------------------
int stm32_check() {
  String receivedMessage;
  int time_start = 0;
  int Serial_com = 1;

  // STM1 checking process -----------------------------------------
  if (Serial_com == 1) {
    // communicate with STM 1 ..............
    SerialPort.println("1001\n");

    time_start = millis();
    while (true) {
      if ( (millis() - time_start) > 3000) {
        Serial.println("STM 1 not detected..");
        Serial_com = 0;
        break;
      }
      else if ( SerialPort.available()) {
        char receivedChar = SerialPort.read();
        Serial.println(receivedChar);
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

  }

  delay(500);
  
  // STM2 checking process -----------------------------------------
  if ( Serial_com == 1) {
    // communicate with STM 2 ..............
    SerialPort.println("2001\n");

    time_start = millis();
    while (true) {
      if ( (millis() - time_start) > 3000) {
        Serial.println("STM 2 not detected..");
        Serial_com = 0;
        break;
      }
      else if ( SerialPort.available()) {
        char receivedChar = SerialPort.read();
        if ( receivedChar == '\n') {
          Serial.println(receivedMessage);
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


  return Serial_com;
  
}

// checking the STM32 chips serial connection ------------------------------
void serialCom_check() {
  Serial.println("checking serial connecting -----------");
  dash_0005.display_(0);
  delay(2000);

  int Serial_process = 1;

  while (true) {
    if ( stm32_check() == 1) {
      Serial.println("serial connecting completed -----------");
      break;
    }
    else {
      Serial.println("serial connection checking faile. Recheck in 5s");
      dash_0010.display_(0);
      buzzerBeep(3);

      delay(5000);

      if ( back_BN.pressed) {
        back_BN.pressed = false;
        break;
      }

    }


  }

}
