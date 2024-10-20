
//Communication Protocol
//a - valve 1 close call back
//b - valve 1 open call back
//c - valve 2 close call back
//d - valve 2 open call back
//e - valve 3 close call back
//f - valve 3 open call back
//g - valve 4 close call back
//h - valve 4 open call back
//i - valve 5 close call back
//j - valve 5 open call back

#include <HardwareSerial.h>

HardwareSerial SerialPort(2); // use UART2

void slave_callback(char send_) {
  while (1) {
    if (SerialPort.available()) {
      char number = SerialPort.read();

      if ( send_=='a' && number == 'A') {
        Serial.println("valve 1 close");
        break;
      }
      else if ( send_=='b' && number == 'B') {
        Serial.println("valve 1 open");
        break;
      }

      if ( send_=='c' && number == 'C') {
        Serial.println("valve 2 close");
        break;
      }
      else if ( send_=='d' && number == 'D') {
        Serial.println("valve 2 open");
        break;
      }

      if ( send_=='e' && number == 'E') {
        Serial.println("valve 3 close");
        break;
      }
      else if ( send_=='f' && number == 'F') {
        Serial.println("valve 3 open");
        break;
      }

      if ( send_=='g' && number == 'G') {
        Serial.println("valve 4 close");
        break;
      }
      else if ( send_=='h' && number == 'H') {
        Serial.println("valve 4 open");
        break;
      }

      if ( send_=='i' && number == 'I') {
        Serial.println("valve 5 close");
        break;
      }
      else if ( send_=='j' && number == 'J') {
        Serial.println("valve 5 open");
        break;
      }
    
    }
  }
}


struct Valve {
  String valve;
  char closeIndex;
  char openIndex;
  bool state;

  void open( bool state) {
    Serial.print(valve);
    if ( state == true) {
      Serial.println(" valve_opening.... ");
      
      SerialPort.print(openIndex);
//      slave_callback(openIndex);
    }
    else {
      Serial.println(" valve_closing.... ");
      
      SerialPort.print(closeIndex);
//      slave_callback(closeIndex);
    }
    
  }
  
};

Valve valve1 = {"valve1", 'a', 'b', false};
Valve valve2 = {"valve2", 'c', 'd', false};
Valve valve3 = {"valve3", 'e', 'f', false};
Valve valve4 = {"valve4", 'g', 'h', false};
Valve valve5 = {"valve5", 'i', 'j', false};


void valveExample() {
  SerialPort.print('i');
  Serial.println("i");
  slave_callback('i');
  delay(5000);

  SerialPort.print('j');
  Serial.println("j");
  slave_callback('j');
  delay(5000);
}
