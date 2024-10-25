
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
    // Serial.println(receivedChar);
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
  else if ( Msg == "1011") {
    valve1Close();
  }
  else if ( Msg == "1010") {
    valve1Open();
  }
  else if ( Msg == "1021") {
    valve2Close();
  }
  else if ( Msg == "1020") {
    valve2Open();
  }

  Msg = "";

  

  // valve2Open();

  // valve2Close();
  
  // // Switch_update();

  // delay(1000);
  // Serial.println(" ");


  // if (Serial2.available()) {
  //   char number = Serial2.read();
  //   Serial.println(number);

  //   if (number == 'a') {
  //     Serial.println("reading a");
  //     valve1Close();
  //   }
  //   else if (number == 'b') {
  //     Serial.println("reading b");
  //     valve1Open();
  //   }

  //   if (number == 'c') {
  //     Serial.println("reading c");
  //     // valve2Close();
  //   }
  //   else if (number == 'd') {
  //     Serial.println("reading d");
  //     // valve2Open();
  //   }

  //   if (number == 'e') {
  //     Serial.println("reading e");
  //     // valve3Close();
  //   }
  //   else if (number == 'f') {
  //     Serial.println("reading f");
  //     // valve3Open();
  //   }

  //   if (number == 'g') {
  //     Serial.println("reading g");
  //     // valve4Close();
  //   }
  //   else if (number == 'h') {
  //     Serial.println("reading h");
  //     // valve4Open();
  //   }

  //   if (number == 'i') {
  //     Serial.println("reading i");
  //     // valve5Close();
  //   }
  //   else if (number == 'j') {
  //     Serial.println("reading j");
  //     // valve5Open();
  //   }

  //   if (number == 'k') {
  //     Serial.println("reading k");
  //     // valve6Close();
  //   }
  //   else if (number == 'l') {
  //     Serial.println("reading l");
  //     // valve6Open();
  //   }

  // }

  

}

