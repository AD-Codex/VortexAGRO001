
//Communication Protocol
//a - valve A1 close call
//b - valve A1 open call
//c - valve A2 close call
//d - valve A2 open call
//e - valve A3 close call
//f - valve A3 open call
//g - valve A4 close call
//h - valve A4 open call
//i - valve A5 close call
//j - valve A5 open call
//k - valve A6 close call
//l - valve A6 open call

//m - valve B1 close call
//n - valve B1 open call
//o - valve B2 close call
//p - valve B2 open call
//q - valve B3 close call
//r - valve B3 open call
//s - valve B4 close call
//t - valve B4 open call
//u - valve B5 close call
//v - valve B5 open call
//w - valve B6 close call
//x - valve B6 open call

#include <HardwareSerial.h>

HardwareSerial SerialPort(2); // use UART2




void slave_callback(char send_) {
  SerialPort.flush();
  while (true) {
    if (SerialPort.available()) {
      char number = SerialPort.read();
      Serial.println(number);

      if ( send_=='a' && number == 'A') {
        Serial.println("valve A1 close");
        break;
      }
      else if ( send_=='b' && number == 'B') {
        Serial.println("valve A1 open");
        break;
      }

      if ( send_=='c' && number == 'C') {
        Serial.println("valve A2 close");
        break;
      }
      else if ( send_=='d' && number == 'D') {
        Serial.println("valve A2 open");
        break;
      }

      if ( send_=='e' && number == 'E') {
        Serial.println("valve A3 close");
        break;
      }
      else if ( send_=='f' && number == 'F') {
        Serial.println("valve A3 open");
        break;
      }

      if ( send_=='g' && number == 'G') {
        Serial.println("valve A4 close");
        break;
      }
      else if ( send_=='h' && number == 'H') {
        Serial.println("valve A4 open");
        break;
      }

      if ( send_=='i' && number == 'I') {
        Serial.println("valve A5 close");
        break;
      }
      else if ( send_=='j' && number == 'J') {
        Serial.println("valve A5 open");
        break;
      }

      if ( send_=='k' && number == 'K') {
        Serial.println("valve A6 close");
        break;
      }
      else if ( send_=='l' && number == 'L') {
        Serial.println("valve A6 open");
        break;
      }

      if ( send_=='m' && number == 'M') {
        Serial.println("valve B1 close");
        break;
      }
      else if ( send_=='n' && number == 'N') {
        Serial.println("valve B1 open");
        break;
      }

      if ( send_=='o' && number == 'O') {
        Serial.println("valve B2 close");
        break;
      }
      else if ( send_=='p' && number == 'P') {
        Serial.println("valve B2 open");
        break;
      }

      if ( send_=='q' && number == 'Q') {
        Serial.println("valve B3 close");
        break;
      }
      else if ( send_=='r' && number == 'R') {
        Serial.println("valve B3 open");
        break;
      }

      if ( send_=='s' && number == 'S') {
        Serial.println("valve B4 close");
        break;
      }
      else if ( send_=='t' && number == 'T') {
        Serial.println("valve B4 open");
        break;
      }

      if ( send_=='u' && number == 'U') {
        Serial.println("valve B5 close");
        break;
      }
      else if ( send_=='v' && number == 'V') {
        Serial.println("valve B5 open");
        break;
      }

      if ( send_=='w' && number == 'W') {
        Serial.println("valve B6 close");
        break;
      }
      else if ( send_=='x' && number == 'X') {
        Serial.println("valve B6 open");
        break;
      }
    
    }

    if ( back_BN.pressed ) {
      Serial.println("Back pressed");
      back_BN.pressed = false;
      break;
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
      Serial.println(openIndex);
      slave_callback(openIndex);
    }
    else {
      Serial.println(" valve_closing.... ");
      
      SerialPort.print(closeIndex);
      Serial.println(closeIndex);
      slave_callback(closeIndex);
    }
    delay(1000);
    
  }
  
};

Valve valve_A1 = {"valve1", 'a', 'b', false};
Valve valve_A2 = {"valve2", 'c', 'd', false};
Valve valve_A3 = {"valve3", 'e', 'f', false};
Valve valve_A4 = {"valve4", 'g', 'h', false};
Valve valve_A5 = {"valve5", 'i', 'j', false};
Valve valve_A6 = {"valve6", 'k', 'l', false};
Valve valve_B1 = {"valve7", 'm', 'n', false};
Valve valve_B2 = {"valve8", 'o', 'p', false};
Valve valve_B3 = {"valve9", 'q', 'r', false};
Valve valve_B4 = {"valve10", 's', 't', false};
Valve valve_B5 = {"valve11", 'u', 'v', false};
Valve valve_B6 = {"valve12", 'w', 'x', false};


void valveCheck() {
  
}


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
