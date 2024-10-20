
# include "Serial.h"
# include "Switches.h"
# include "Motors.h"
# include "Valves.h"


void setup() {
  Serial.begin(115200);
  Serial.println("Initilizing STM32_2");
  
  // initialize serial com.
  init_serialBus();
  // initialize limit switches
  init_Switch();
  // initialize motor ENs
  init_motors();

  // Update limit switch states
  Switch_update();

}


void loop() {

  if (Serial2.available()) {
    char number = Serial2.read();
    // Serial.println(number);

    if (number == 'm') {
      Serial.println("reading m");
      valve1Close();
    }
    else if (number == 'n') {
      Serial.println("reading n");
      valve1Open();
    }

    if (number == 'o') {
      Serial.println("reading o");
      valve2Close();
    }
    else if (number == 'p') {
      Serial.println("reading p");
      valve2Open();
    }

    if (number == 'q') {
      Serial.println("reading q");
      valve3Close();
    }
    else if (number == 'r') {
      Serial.println("reading r");
      valve3Open();
    }

    if (number == 's') {
      Serial.println("reading s");
      valve4Close();
    }
    else if (number == 't') {
      Serial.println("reading t");
      valve4Open();
    }

    if (number == 'u') {
      Serial.println("reading u");
      valve5Close();
    }
    else if (number == 'v') {
      Serial.println("reading v");
      valve5Open();
    }

    if (number == 'w') {
      Serial.println("reading w");
      valve6Close();
    }
    else if (number == 'x') {
      Serial.println("reading x");
      valve6Open();
    }

  }

  

}

