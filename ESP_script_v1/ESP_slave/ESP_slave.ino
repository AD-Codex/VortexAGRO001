//index, close, open, EN1, EN2
//set1, 34, 35, 32, 33
//set2, 25, 26, 27, 14
//set3, 36, 39, 12, 13
//set4, 23, 22, 21, 19
//set5, 18, 5, 4, 2

# include <HardwareSerial.h>

HardwareSerial SerialPort(2); // use UART2

# include "Switches.h"
# include "Motors.h"
# include "Valve.h"

char number  = ' ';

void setup() {
  Serial.begin(115200);
  Serial.println("----- Vortex Lab Project 001 -----");

  init_Switch();
  init_motors();

  SerialPort.begin(115200, SERIAL_8N1, 16, 17); 


}

void loop() {

//  switchTest();
//  delay(10);
//
//  valve1Open();
//  delay(2000);
//  valve1Close();
//  delay(2000);
//
//  valve2Open();
//  delay(2000);
//  valve2Close();
//  delay(2000);
//  
//  valve3Open();
//  delay(2000);
//  valve3Close();
//  delay(2000);
//
//  valve4Open();
//  delay(2000);
//  valve4Close();
//  delay(2000);
//  
//  valve5Open();
//  delay(2000);
//  valve5Close();
//  delay(2000);

  if (SerialPort.available()) {
    char number = SerialPort.read();
//    Serial.println(number);
    
    if (number == 'a') {
      Serial.println("reading a");
      valve1Close();
    }
    else if (number == 'b') {
      Serial.println("reading b");
      valve1Open();
    }

    if (number == 'c') {
      Serial.println("reading c");
      valve2Close();
    }
    else if (number == 'd') {
      Serial.println("reading d");
      valve2Open();
    }

    if (number == 'e') {
      Serial.println("reading e");
      valve3Close();
    }
    else if (number == 'f') {
      Serial.println("reading f");
      valve3Open();
    }

    if (number == 'g') {
      Serial.println("reading g");
      valve4Close();
    }
    else if (number == 'h') {
      Serial.println("reading h");
      valve4Open();
    }

    if (number == 'i') {
      Serial.println("reading i");
      valve5Close();
    }
    else if (number == 'j') {
      Serial.println("reading j");
      valve5Open();
    }
  }

}
