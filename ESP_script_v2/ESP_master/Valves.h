
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


void slave_callback(String send_) {
  SerialPort.flush();

  int time_start = millis();
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
      break;
    }
    else if ( (millis() - time_start) > 8000 ) {
      Serial.println("error, time exceed");
      break;
    }
    else if ( Msg == "9999") {
      Serial.println("stm recived, time exceed");
      break;
    }


  }
}


struct Valve {
  String valve;
  String closeIndex;
  String openIndex;
  bool state;

  void open( bool state) {
    Serial.print(valve);
    if ( state == true) {
      Serial.println(" valve_opening.... ");
      
      SerialPort.print(openIndex + "\n");
      Serial.println(openIndex);
      slave_callback(openIndex);
    }
    else {
      Serial.println(" valve_closing.... ");
      
      SerialPort.print(closeIndex + "\n");
      Serial.println(closeIndex);
      slave_callback(closeIndex);
    }
    delay(1000);
    
  }

  
};

Valve valve_A1 = {"valve1", "1010", "1011", false};
Valve valve_A2 = {"valve2", "1020", "1021", false};
Valve valve_A3 = {"valve3", "1030", "1031", false};
Valve valve_A4 = {"valve4", "1040", "1041", false};
Valve valve_A5 = {"valve5", "1050", "1051", false};
Valve valve_A6 = {"valve6", "1060", "1061", false};
Valve valve_B1 = {"valve7", "2010", "2011", false};
Valve valve_B2 = {"valve8", "2020", "2021", false};
Valve valve_B3 = {"valve9", "2030", "2031", false};
Valve valve_B4 = {"valve10", "2040", "2041", false};
Valve valve_B5 = {"valve11", "2050", "2051", false};
Valve valve_B6 = {"valve12", "2060", "2061", false};



void valveReSet() {

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
