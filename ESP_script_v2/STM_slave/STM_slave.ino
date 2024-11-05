
# include "Serial.h"
# include "Switches.h"
# include "Motors.h"
# include "Valves.h"

String Msg;
String receivedMessage;

void setup() {
  Serial.begin(115200);
  Serial.println("Initilizing STM32_1");
  
  // initialize serial com.
  init_serialBus();
  // initialize limit switches
  init_Switch();
  // initialize motor ENs
  init_motors();


}


void loop() {


  if (Serial2.available()) {

    char receivedChar = Serial2.read();
    Serial.println(receivedChar);
      if ( receivedChar == '\n') {
        Msg = receivedMessage;
        Serial.println(receivedMessage);
        receivedMessage = "";
      }
      else {
        receivedMessage =  receivedMessage + receivedChar;
      }

  }

  if ( Msg == "1001") {
    serialBus_check(Msg);
  }
  else if ( Msg == "1002") {
    Switch_status();
  }

  else if ( Msg == "1010") {
    valve1Close();
  }
  else if ( Msg == "1011") {
    valve1Open();
  }
  else if ( Msg == "1013") {
    valve1Clkwise();
  }
  else if ( Msg == "1014") {
    valve1Aclkwise();
  }

  else if ( Msg == "1020") {
    valve2Close();
  }
  else if ( Msg == "1021") {
    valve2Open();
  }
  else if ( Msg == "1023") {
    valve2Clkwise();
  }
  else if ( Msg == "1024") {
    valve2Aclkwise();
  }

  else if ( Msg == "1030") {
    valve3Close();
  }
  else if ( Msg == "1031") {
    valve3Open();
  }
  else if ( Msg == "1033") {
    valve3Clkwise();
  }
  else if ( Msg == "1034") {
    valve3Aclkwise();
  }

  else if ( Msg == "1040") {
    valve4Close();
  }
  else if ( Msg == "1041") {
    valve4Open();
  }
  else if ( Msg == "1043") {
    valve4Clkwise();
  }
  else if ( Msg == "1044") {
    valve4Aclkwise();
  }

  else if ( Msg == "1050") {
    valve5Close();
  }
  else if ( Msg == "1051") {
    valve5Open();
  }
  else if ( Msg == "1053") {
    valve5Clkwise();
  }
  else if ( Msg == "1054") {
    valve5Aclkwise();
  }

  else if ( Msg == "1060") {
    valve6Close();
  }
  else if ( Msg == "1061") {
    valve6Open();
  }
  else if ( Msg == "1063") {
    valve6Clkwise();
  }
  else if ( Msg == "1064") {
    valve6Aclkwise();
  }
  

  Msg = "";


  

}

