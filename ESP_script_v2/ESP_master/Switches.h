
// switch status check
// STM-1 valve check, sending-1002
// STM-2 valve check, sending-2002
// receving 2 pair of 12 bit data
// 2 pairs 1bit high - valve close, 2bit high - valve open
//         1,2 bit high - valve not connected or error in limit switch
//         1,2 bit low - valve not close and open
// time limit 3000 mils



int valve_stats( String receivedMessage) {
  for (int i=0; i<12; i=i+2){
    if ( receivedMessage[i] == '1' and receivedMessage[i+1] == '1') {
      Serial.println( String((i/2)+1) + " valve not connected or error in limit switch.");
      return 1;
    }
    else if ( receivedMessage[i] == '0' and receivedMessage[i+1] == '1') {
      Serial.println( String((i/2)+1) + " valve opened.");
      return 1;
    }
    else if ( receivedMessage[i] == '1' and receivedMessage[i+1] == '0') {
      Serial.println( String((i/2)+1) + " valve closed.");
      return 1;
    }
    else if ( receivedMessage[i] == '0' and receivedMessage[i+1] == '0') {
      Serial.println( String((i/2)+1) + " valve not close and open.");
      return 1;
    }
    else {
      Serial.println( String((i/2)+1) + " error in recived data");
      return 0;
    }
  }

}


void Switch_status() {
  String receivedMessage;
  int time_start = 0;

  // STM 1 status check ---------------------
  Serial.println("STM1 valve check sending 1002\n");
  SerialPort.print("1002\n");

  time_start = millis();
  while (true) {
    if ( (millis() - time_start) > 3000) {
      Serial.println("STM 1 switch status check fail ...");
      break;
    }
    else if ( SerialPort.available()) {
      char receivedChar = SerialPort.read();
      if ( receivedChar == '\n') {
        // Serial.println(receivedMessage);
        if ( receivedMessage.length()  == 12) {
          Serial.println(" STM_1 valve status ...");
          if (valve_stats( receivedMessage)){
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

  // STM 2 status check ---------------------
  Serial.println("STM2 valve check sending 2002\n");
  SerialPort.print("2002\n");

  time_start = millis();
  while (true) {
    if ( (millis() - time_start) > 3000) {
      Serial.println("STM 2 switch status check fail ...");
      break;
    }
    else if ( SerialPort.available()) {
      char receivedChar = SerialPort.read();
      if ( receivedChar == '\n') {
        // Serial.println(receivedMessage);
        if ( receivedMessage.length() == 12) {
          Serial.println(" STM_2 valve status ...");
          valve_stats( receivedMessage);
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