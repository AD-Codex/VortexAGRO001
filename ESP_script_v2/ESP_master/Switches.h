
// switch status check
// STM-1 valve check, sending-1002
// STM-2 valve check, sending-2002
// receving 2 pair of 12 bit data
// 2 pairs 1st bit high - valve close, 2nd bit high - valve open
//         1,2 bit high - valve not connected or error in limit switch
//         1,2 bit low - valve not close and open
// time limit 3000 mils
// display valve states and ask to continu or recheck
// if EN - continue, BK - recheck

int detect_valve[] = {0,0,0,0,0,0};


// decode the received msg from STM32 --------------------------------------------
int valve_stats( String receivedMessage) {
  for (int i=0; i<12; i=i+2){
    if ( receivedMessage[i] == '1' and receivedMessage[i+1] == '1') {
      Serial.println( String((i/2)+1) + " valve not connected or error in limit switch.");
      detect_valve[(i/2)] = 0;
    }
    else if ( receivedMessage[i] == '0' and receivedMessage[i+1] == '1') {
      Serial.println( String((i/2)+1) + " valve opened.");
      detect_valve[(i/2)] = 1;
    }
    else if ( receivedMessage[i] == '1' and receivedMessage[i+1] == '0') {
      Serial.println( String((i/2)+1) + " valve closed.");
      detect_valve[(i/2)] = 1;
    }
    else if ( receivedMessage[i] == '0' and receivedMessage[i+1] == '0') {
      Serial.println( String((i/2)+1) + " valve not close and open.");
      detect_valve[(i/2)] = 1;
    }
    else {
      Serial.println( String((i/2)+1) + " error in recived data");
      return 0;
    }
  }

  return 1;

}

// check the switch states ----------------------------------------------------------------------------------
int Switch_status() {
  String receivedMessage;
  int time_start = 0;
  char Astr[15];
  char Bstr[15];

  dash_0025.display_(0);

  // STM 1 status check ----------------------------------------------------------------------
  Serial.println("STM1 valve check sending 1002\n");
  SerialPort.print("1002\n");

  time_start = millis();
  while (true) {
    if ( (millis() - time_start) > 3000) {
      Serial.println("STM 1 switch status check fail ...");
      buzzerBeep(3);
      time_start = millis();
      // break;
    }
    else if ( SerialPort.available()) {
      char receivedChar = SerialPort.read();
      if ( receivedChar == '\n') {
        // Serial.println(receivedMessage);
        if ( receivedMessage.length()  == 12) {
          Serial.println(" STM_1 valve status ...");
          if (valve_stats( receivedMessage)){
            Serial.print(" valve number 1,2,3,4,5,6 states ");
            sprintf( Astr, "1-6 %d,%d,%d,%d,%d,%d",  detect_valve[0], detect_valve[1], detect_valve[2], detect_valve[3], detect_valve[4], detect_valve[5]);
            Serial.println(Astr);
            break;
          }
          
        }
        receivedMessage = "";
        
      }
      else {
        receivedMessage += receivedChar;
      }
    }
  }
  delay(2000);

  // STM 2 status check --------------------------------------------------------------
  Serial.println("STM2 valve check sending 2002\n");
  SerialPort.print("2002\n");

  time_start = millis();
  while (true) {
    if ( (millis() - time_start) > 3000) {
      Serial.println("STM 2 switch status check fail ...");
      buzzerBeep(3);
      time_start = millis();
      // break;
    }
    else if ( SerialPort.available()) {
      char receivedChar = SerialPort.read();
      if ( receivedChar == '\n') {
        // Serial.println(receivedMessage);
        if ( receivedMessage.length() == 12) {
          Serial.println(" STM_2 valve status ...");
          if (valve_stats( receivedMessage)){
            Serial.print(" valve number 7,8,9,10,11,12 states ");
            sprintf( Bstr, "7-12 %d,%d,%d,%d,%d,%d",  detect_valve[0], detect_valve[1], detect_valve[2], detect_valve[3], detect_valve[4], detect_valve[5]);
            Serial.println(Bstr);
            break;
          }
        }
        receivedMessage = "";
      }
      else {
        receivedMessage += receivedChar;
      }
    }
  }

  // display switch states on lcd ---------------------------------------
  dash_0026.valveState( Astr, Bstr);
  buzzerHigh(true);
  enter_BN.pressed = false; back_BN.pressed = false;
  while (true) {
    if ( enter_BN.pressed) {
      enter_BN.pressed = false;
      buzzerHigh(false);
      return 1;
    }
    else if ( back_BN.pressed) {
      back_BN.pressed = false;
      buzzerHigh(false);
      return 0;
    }
    delay(100);
  }


}


