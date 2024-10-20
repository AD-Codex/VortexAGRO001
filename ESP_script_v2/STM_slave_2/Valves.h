
//Communication Protocol STM32 2
//M - valve 1 close call
//N - valve 1 open call
//O - valve 2 close call
//P - valve 2 open call
//Q - valve 3 close call
//R - valve 3 open call
//S - valve 4 close call
//T - valve 4 open call
//U - valve 5 close call
//V - valve 5 open call
//W - valve 6 close call
//X - valve 6 open call


void valve_Close( Switch &switch_A, Motor &motorSet_, const char* valve, const char* index) {
  Serial.println("closing " + String(valve));

  while (true) {
    if ( digitalRead(switch_A.PIN) == HIGH ) {
      motorSet_.motorClose();
      Serial.println( String(valve) + " closed");
      break;
    }
    else {
      motorSet_.motorRunClk();
      delay(10);
    }
  }

  Serial2.print(index);
  Serial.println("sending " + String(index));

  // Switch_update();

}

void valve_Open( Switch &switch_B, Motor &motorSet_, const char* valve, const char* index) {
  Serial.println("opening " + String(valve));

  while (true) {
    if ( digitalRead(switch_B.PIN) == HIGH ) {
      motorSet_.motorClose();
      Serial.println( String(valve) + " opend");
      break;
    }
    else {
      motorSet_.motorRunAClk();
      delay(10);
    }
  }

  Serial2.print(index);
  Serial.println("sending " + String(index));

  // Switch_update();

}





// valve 1 ------------------------------------------
void valve1Close() {
  valve_Close( switch_1A, motorSet1, "valve 1", "M");
}
void valve1Open() {
  valve_Open( switch_1B, motorSet1, "valve 1", "N");
}

// valve 2 ------------------------------------------
void valve2Close() {
  valve_Close( switch_2A, motorSet2, "valve 2", "O");
}
void valve2Open() {
  valve_Open( switch_2B, motorSet2, "valve 2", "P");
}

// valve 3 ------------------------------------------
void valve3Close() {
  valve_Close( switch_3A, motorSet3, "valve 3", "Q");
}
void valve3Open() {
  valve_Open( switch_3B, motorSet3, "valve 3", "R");
}

// valve 4 ------------------------------------------
void valve4Close() {
  valve_Close( switch_4A, motorSet4, "valve 4", "S");
}
void valve4Open() {
  valve_Open( switch_4B, motorSet4, "valve 4", "T");
}

// valve 5 ------------------------------------------
void valve5Close() {
  valve_Close( switch_5A, motorSet5, "valve 5", "U");
}
void valve5Open() {
  valve_Open( switch_5B, motorSet5, "valve 5", "V");
}

// valve 6 ------------------------------------------
void valve6Close() {
  valve_Close( switch_6A, motorSet6, "valve 6", "W");
}
void valve6Open() {
  valve_Open( switch_6B, motorSet6, "valve 6", "X");
}
