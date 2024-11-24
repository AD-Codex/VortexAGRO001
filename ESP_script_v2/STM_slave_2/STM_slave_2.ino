
# include "Serial.h"
# include "Switches.h"
# include "Motors.h"
# include "Valves.h"

String Msg;
String receivedMessage;

void setup() {
  Serial.begin(115200);
  Serial.println("Initilizing STM32_2");
  
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

  

  if ( Msg == "2001") {
    serialBus_check(Msg);
  }
  else if ( Msg == "2002") {
    Switch_status();
  }

  else if ( Msg == "2010") {
    valve1Close();
  }
  else if ( Msg == "2011") {
    valve1Open();
  }
  else if ( Msg == "2013") {
    valve1Clkwise();
  }
  else if ( Msg == "2014") {
    valve1Aclkwise();
  }

  else if ( Msg == "2020") {
    valve2Close();
  }
  else if ( Msg == "2021") {
    valve2Open();
  }
  else if ( Msg == "2023") {
    valve2Clkwise();
  }
  else if ( Msg == "2024") {
    valve2Aclkwise();
  }

  else if ( Msg == "2030") {
    valve3Close();
  }
  else if ( Msg == "2031") {
    valve3Open();
  }
  else if ( Msg == "2033") {
    valve3Clkwise();
  }
  else if ( Msg == "2034") {
    valve3Aclkwise();
  }

  else if ( Msg == "2040") {
    valve4Close();
  }
  else if ( Msg == "2041") {
    valve4Open();
  }
  else if ( Msg == "2043") {
    valve4Clkwise();
  }
  else if ( Msg == "2044") {
    valve4Aclkwise();
  }

  else if ( Msg == "2050") {
    valve5Close();
  }
  else if ( Msg == "2051") {
    valve5Open();
  }
  else if ( Msg == "2053") {
    valve5Clkwise();
  }
  else if ( Msg == "2054") {
    valve5Aclkwise();
  }

  else if ( Msg == "2060") {
    valve6Close();
  }
  else if ( Msg == "2061") {
    valve6Open();
  }
  else if ( Msg == "2063") {
    valve6Clkwise();
  }
  else if ( Msg == "2064") {
    valve6Aclkwise();
  }
  

  Msg = "";
  

}

