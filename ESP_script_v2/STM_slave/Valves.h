
//Communication Protocol STM32 1
//A - valve 1 close call
//B - valve 1 open call
//C - valve 2 close call
//D - valve 2 open call
//E - valve 3 close call
//F - valve 3 open call
//G - valve 4 close call
//H - valve 4 open call
//I - valve 5 close call
//J - valve 5 open call
//K - valve 6 close call
//L - valve 6 open call


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
  valve_Close( switch_1A, motorSet1, "valve 1", "A");
}
void valve1Open() {
  valve_Open( switch_1B, motorSet1, "valve 1", "B");
}

// valve 2 ------------------------------------------
void valve2Close() {
  valve_Close( switch_2A, motorSet2, "valve 2", "C");
}
void valve2Open() {
  valve_Open( switch_2B, motorSet2, "valve 2", "D");
}

// valve 3 ------------------------------------------
void valve3Close() {
  valve_Close( switch_3A, motorSet3, "valve 3", "E");
}
void valve3Open() {
  valve_Open( switch_3B, motorSet3, "valve 3", "F");
}

// valve 4 ------------------------------------------
void valve4Close() {
  valve_Close( switch_4A, motorSet4, "valve 4", "G");
}
void valve4Open() {
  valve_Open( switch_4B, motorSet4, "valve 4", "H");
}

// valve 5 ------------------------------------------
void valve5Close() {
  valve_Close( switch_5A, motorSet5, "valve 5", "I");
}
void valve5Open() {
  valve_Open( switch_5B, motorSet5, "valve 5", "J");
}

// valve 6 ------------------------------------------
void valve6Close() {
  valve_Close( switch_6A, motorSet6, "valve 6", "K");
}
void valve6Open() {
  valve_Open( switch_6B, motorSet6, "valve 6", "L");
}
