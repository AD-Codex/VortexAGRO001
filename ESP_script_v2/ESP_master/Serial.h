

int Serial_com = 0;
int time_start = 0;
int time_space = 0;


void init_serial() {
  SerialPort.begin(115200, SERIAL_8N1, 16, 17);  //uart 2

}


void stm32_check() {
  // communicate with STM 1 ..............
  SerialPort.println(1);

  time_start = millis();
  while (true) {
    time_space = millis() - time_start;

    if ( time_space > 2000) {
      // Serial.println("STM 1 not detected..");
      Serial_com = 0;
      break;
    }
    else if ( SerialPort.available()) {
      char number = SerialPort.read();
      
      if ( number == '1') {
        // Serial.println("STM 1 detected..");
        Serial_com = 1;
      }
    }

  }


  // communicate with STM 2 ..............
  SerialPort.println(2);

  time_start = millis();
  while (true) {
    time_space = millis() - time_start;

    if ( time_space > 2000) {
      // Serial.println("STM 2 not detected..");
      Serial_com = 0;
      break;
    }
    else if ( SerialPort.available()) {
      char number = SerialPort.read();
      
      if ( number == '2') {
        // Serial.println("STM 2 detected..");
        Serial_com = 1;
      }
    }

  }


}


void serialCom_check() {
  Serial.println("checking serial connecting -----------");

  while (true) {
    stm32_check();
    if (Serial_com == 1) {
      Serial.println("serial connecting completed -----------");
      break;
    }
    else {
      Serial.println("serial connection checking faile. Recheck in 5s");
      delay(5000);
    }

  }

}
