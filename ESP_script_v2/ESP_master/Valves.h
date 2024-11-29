//Communication Protocol
//1010 - valve A1 close call
//1011 - valve A1 open call
//1020 - valve A2 close call
//1021 - valve A2 open call
//1030 - valve A3 close call
//1031 - valve A3 open call
//1040 - valve A4 close call
//1041 - valve A4 open call
//1050 - valve A5 close call
//1051 - valve A5 open call
//1060 - valve A6 close call
//1061 - valve A6 open call

//2010 - valve B1 close call
//2011 - valve B1 open call
//2020 - valve B2 close call
//2021 - valve B2 open call
//2030 - valve B3 close call
//2031 - valve B3 open call
//2040 - valve B4 close call
//2041 - valve B4 open call
//2050 - valve B5 close call
//2051 - valve B5 open call
//2060 - valve B6 close call
//2061 - valve B6 open call

// if recived send data break loop and print states
// time limit 8s. 
// if recived 9999 break with error


#include <HardwareSerial.h>

HardwareSerial SerialPort(2); // use UART2

int FUNCTIONAL_VALES[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
int FUNCTIONAL_VALES_SIZE = 9;


// STM32 feedback observer Fn ------------------------------------
int slave_callback(String send_) {
  SerialPort.flush();

  int time_start = millis();
  int slave_callback_state = 0;
  String receivedMessage;
  String Msg;

  while (true) {
    if (SerialPort.available()) {
      char receivedChar = SerialPort.read();
      // Serial.println(number);

      if ( receivedChar == '\n') {
        Msg = receivedMessage;
        Serial.println(receivedMessage);
        receivedMessage = "";
      }
      else {
        receivedMessage = receivedMessage + receivedChar;
      }
    }

    slave_callback_state = 1;

    if ( send_== "1010" && Msg == "1010") {
      Serial.println("valve A1 close");
      break;
    }
    else if ( send_== "1011" && Msg == "1011") {
      Serial.println("valve A1 open");
      break;
    }

    if ( send_== "1020" && Msg == "1020") {
      Serial.println("valve A2 close");
      break;
    }
    else if ( send_== "1021" && Msg == "1021") {
      Serial.println("valve A2 open");
      break;
    }

    if ( send_== "1030" && Msg == "1030") {
      Serial.println("valve A3 close");
      break;
    }
    else if ( send_== "1031" && Msg == "1031") {
      Serial.println("valve A3 open");
      break;
    }

    if ( send_== "1040" && Msg == "1040") {
      Serial.println("valve A4 close");
      break;
    }
    else if ( send_== "1041" && Msg == "1041") {
      Serial.println("valve A4 open");
      break;
    }

    if ( send_== "1050" && Msg == "1050") {
      Serial.println("valve A5 close");
      break;
    }
    else if ( send_== "1051" && Msg == "1051") {
      Serial.println("valve A5 open");
      break;
    }

    if ( send_== "1060" && Msg == "1060") {
      Serial.println("valve A6 close");
      break;
    }
    else if ( send_== "1061" && Msg == "1061") {
      Serial.println("valve A6 open");
      break;
    }

    if ( send_== "2010" && Msg == "2010") {
      Serial.println("valve B1 close");
      break;
    }
    else if ( send_== "2011" && Msg == "2011") {
      Serial.println("valve B1 open");
      break;
    }

    if ( send_== "2020" && Msg == "2020") {
      Serial.println("valve B2 close");
      break;
    }
    else if ( send_== "2021" && Msg == "2021") {
      Serial.println("valve B2 open");
      break;
    }

    if ( send_== "2030" && Msg == "2030") {
      Serial.println("valve B3 close");
      break;
    }
    else if ( send_== "2031" && Msg == "2031") {
      Serial.println("valve B3 open");
      break;
    }

    if ( send_== "2040" && Msg == "2040") {
      Serial.println("valve B4 close");
      break;
    }
    else if ( send_== "2041" && Msg == "2041") {
      Serial.println("valve B4 open");
      break;
    }

    if ( send_== "2050" && Msg == "2050") {
      Serial.println("valve B5 close");
      break;
    }
    else if ( send_== "2051" && Msg == "2051") {
      Serial.println("valve B5 open");
      break;
    }

    if ( send_== "2060" && Msg == "2060") {
      Serial.println("valve B6 close");
      break;
    }
    else if ( send_== "2061" && Msg == "2061") {
      Serial.println("valve B6 open");
      break;
    }
    
    

    if ( back_BN.pressed ) {
      Serial.println("Back pressed");
      back_BN.pressed = false;
      slave_callback_state = 0;
      break;
    }
    else if ( (millis() - time_start) > 5000 ) {
      Serial.println("error, time exceed");
      buzzerBeep(3);
      slave_callback_state = -2;
      break;
    }
    else if ( Msg == "9999") {
      Serial.println("stm recived, time exceed");
      buzzerBeep(3);
      slave_callback_state = -1;
      break;
    }


  }

  return slave_callback_state;
}

// Valve object deffine ------------------------------------------
struct Valve {
  String valve;
  String closeIndex;
  String openIndex;
  String clkIndex;
  String AclkIndex;
  bool state;

  int open( bool state) {
    int open_state = 0;
    Serial.print(valve);
    if ( state == true) {
      Serial.println(" valve_opening.... ");
      
      SerialPort.print(openIndex + "\n");
      Serial.println(openIndex);
      open_state = slave_callback(openIndex);

      if ( open_state == 1) {
        Serial.println(" valve_opend ");
        state = state;
      }
      else if ( open_state == -1) {
        Serial.println(" valve_opening failed");
      }
      if ( open_state == -2) {
        Serial.println(" valve_opening again.... ");      
        SerialPort.print(openIndex + "\n");
        // Serial.println(openIndex);
        open_state = slave_callback(openIndex);
      }
    }
    else {
      Serial.println(" valve_closing.... ");
      
      SerialPort.print(closeIndex + "\n");
      Serial.println(closeIndex);
      open_state = slave_callback(closeIndex);

      if ( open_state == 1) {
        Serial.println(" valve_closed ");
        state = state;
      }
      else if ( open_state == -1) {
        Serial.println(" valve_closing failed");
      }
      else if ( open_state == -2) {
        Serial.println(" valve_closing again.... ");      
        SerialPort.print(closeIndex + "\n");
        // Serial.println(closeIndex);
        open_state = slave_callback(closeIndex);
      }
    }
    delay(1000);

    return open_state;
  }

  void clkTurn( bool state) {
    Serial.print(valve);
    if ( state == true) {
      Serial.println(" valve_clkTurn.... ");
      
      SerialPort.print(clkIndex + "\n");
      Serial.println(clkIndex);
    }
    else {
      Serial.println(" valve_aclkTurn.... ");
      
      SerialPort.print(AclkIndex + "\n");
      Serial.println(AclkIndex);
    }
    delay(100);
  }

  
};

Valve valve_A1 = {"valve1", "1010", "1011", "1013", "1014", false};
Valve valve_A2 = {"valve2", "1020", "1021", "1023", "1024", false};
Valve valve_A3 = {"valve3", "1030", "1031", "1033", "1034", false};
Valve valve_A4 = {"valve4", "1040", "1041", "1043", "1044", false};
Valve valve_A5 = {"valve5", "1050", "1051", "1053", "1054", false};
Valve valve_A6 = {"valve6", "1060", "1061", "1063", "1064", false};
Valve valve_B1 = {"valve7", "2010", "2011", "2013", "2014", false};
Valve valve_B2 = {"valve8", "2020", "2021", "2023", "2024", false};
Valve valve_B3 = {"valve9", "2030", "2031", "2033", "2034", false};
Valve valve_B4 = {"valve10", "2040", "2041", "2043", "2044", false};
Valve valve_B5 = {"valve11", "2050", "2051", "2053", "2054", false};
Valve valve_B6 = {"valve12", "2060", "2061", "2063", "2064", false};





// valve open Fn with valve numbers ------------------------------------
int valveOpen( int num) {
  int valveOpen_state = 0;
  switch (num) {
    case 1:
      valveOpen_state = valve_A1.open(true);
      break;
    case 2:
      valveOpen_state = valve_A2.open(true);
      break;
    case 3:
      valveOpen_state = valve_A3.open(true);
      break;
    case 4:
      valveOpen_state = valve_A4.open(true);
      break;
    case 5:
      valveOpen_state = valve_A5.open(true);
      break;
    case 6:
      valveOpen_state = valve_A6.open(true);
      break;
    case 7:
      valveOpen_state = valve_B1.open(true);
      break;
    case 8:
      valveOpen_state = valve_B2.open(true);
      break;
    case 9:
      valveOpen_state = valve_B3.open(true);
      break;
    case 10:
      valveOpen_state = valve_B4.open(true);
      break;
    case 11:
      valveOpen_state = valve_B5.open(true);
      break;
    case 12:
      valveOpen_state = valve_B6.open(true);
      break;
  }

  return valveOpen_state;

}

// valve close Fn with valve numbers ------------------------------------
int valveClose(int num) {
  int valveClose_state = 0;
  switch (num) {
    case 1:
      valveClose_state = valve_A1.open(false);
      break;
    case 2:
      valveClose_state = valve_A2.open(false);
      break;
    case 3:
      valveClose_state = valve_A3.open(false);
      break;
    case 4:
      valveClose_state = valve_A4.open(false);
      break;
    case 5:
      valveClose_state = valve_A5.open(false);
      break;
    case 6:
      valveClose_state = valve_A6.open(false);
      break;
    case 7:
      valveClose_state = valve_B1.open(false);
      break;
    case 8:
      valveClose_state = valve_B2.open(false);
      break;
    case 9:
      valveClose_state = valve_B3.open(false);
      break;
    case 10:
      valveClose_state = valve_B4.open(false);
      break;
    case 11:
      valveClose_state = valve_B5.open(false);
      break;
    case 12:
      valveClose_state = valve_B6.open(false);
      break;
  }

  return valveClose_state;

}

// valve turn clockwise Fn with valve numbers ---------------------------
void valveClkTurn( int num) {
  switch (num) {
    case 1:
      valve_A1.clkTurn(true);
      break;
    case 2:
      valve_A2.clkTurn(true);
      break;
    case 3:
      valve_A3.clkTurn(true);
      break;
    case 4:
      valve_A4.clkTurn(true);
      break;
    case 5:
      valve_A5.clkTurn(true);
      break;
    case 6:
      valve_A6.clkTurn(true);
      break;
    case 7:
      valve_B1.clkTurn(true);
      break;
    case 8:
      valve_B2.clkTurn(true);
      break;
    case 9:
      valve_B3.clkTurn(true);
      break;
    case 10:
      valve_B4.clkTurn(true);
      break;
    case 11:
      valve_B5.clkTurn(true);
      break;
    case 12:
      valve_B6.clkTurn(true);
      break;
  }

}

// valve turn anticlockwise Fn with valve numbers -----------------------
void valveAclkTurn( int num) {
  switch (num) {
    case 1:
      valve_A1.clkTurn(false);
      break;
    case 2:
      valve_A2.clkTurn(false);
      break;
    case 3:
      valve_A3.clkTurn(false);
      break;
    case 4:
      valve_A4.clkTurn(false);
      break;
    case 5:
      valve_A5.clkTurn(false);
      break;
    case 6:
      valve_A6.clkTurn(false);
      break;
    case 7:
      valve_B1.clkTurn(false);
      break;
    case 8:
      valve_B2.clkTurn(false);
      break;
    case 9:
      valve_B3.clkTurn(false);
      break;
    case 10:
      valve_B4.clkTurn(false);
      break;
    case 11:
      valve_B5.clkTurn(false);
      break;
    case 12:
      valve_B6.clkTurn(false);
      break;
  }

}



void valveExample() {
  SerialPort.print("1010\n");
  Serial.println("1010");
  slave_callback("1010");
  delay(5000);

  SerialPort.print("1011\n");
  Serial.println("1010");
  slave_callback("1010");
  delay(5000);
}
