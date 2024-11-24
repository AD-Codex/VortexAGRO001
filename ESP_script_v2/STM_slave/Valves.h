
//Communication Protocol STM32 1
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

// if succes send- recive data
// time limit at 5s, if time exceed send-9999



void valve_Close( Switch &switch_A, Motor &motorSet_, const char* valve, String index) {
  int time_start = 0;

  Serial.println("closing " + String(valve));

  time_start = millis();
  while (true) {
    if ( (millis() - time_start) > 5000) {
      motorSet_.motorClose();
      Serial.println("valve close time exceed..");
      Serial2.print( "9999\n");
      break;
    }
    else if ( digitalRead(switch_A.PIN) == HIGH ) {
      motorSet_.motorClose();
      Serial.println( String(valve) + " closed");
      Serial2.print(index + "\n");
      Serial.println("sending " + String(index));
      break;
    }
    else {
      motorSet_.motorRunClk();
      delay(10);
    }
  }


}



void valve_Open( Switch &switch_B, Motor &motorSet_, const char* valve, String index) {
  int time_start = 0;

  Serial.println("opening " + String(valve));

  time_start = millis();
  while (true) {
    if ( (millis() - time_start) > 4000) {
      motorSet_.motorClose();
      Serial.println("valve open time exceed..");
      Serial2.print( "9999\n");
      break;
    }
    else if ( digitalRead(switch_B.PIN) == HIGH ) {
      motorSet_.motorClose();
      Serial.println( String(valve) + " opended");
      Serial2.print(index + "\n");
      Serial.println("sending " + String(index));
      break;
    }
    else {
      motorSet_.motorRunAClk();
      delay(10);
    }
  }


}


void valve_Clkwise( Motor &motorSet_, const char* valve, String index) {
  Serial.println("turn clkwise valve " + String(valve));
  motorSet_.motorRunClk();
  delay(100);
  motorSet_.motorClose();

}

void valve_Aclkwise( Motor &motorSet_, const char* valve, String index) {
  Serial.println("turn Aclkwise valve " + String(valve));
  motorSet_.motorRunAClk();
  delay(100);
  motorSet_.motorClose();

}




// valve 1 ------------------------------------------
void valve1Close() {
  valve_Close( switch_1A, motorSet1, "valve 1", "1010");
}
void valve1Open() {
  valve_Open( switch_1B, motorSet1, "valve 1", "1011");
}
void valve1Clkwise() {
  valve_Clkwise( motorSet1, "valve 1", "1013");
}
void valve1Aclkwise() {
  valve_Aclkwise( motorSet1, "valve 1", "1014");
}

// valve 2 ------------------------------------------
void valve2Close() {
  valve_Close( switch_2A, motorSet2, "valve 2", "1020");
}
void valve2Open() {
  valve_Open( switch_2B, motorSet2, "valve 2", "1021");
}
void valve2Clkwise() {
  valve_Clkwise( motorSet2, "valve 2", "1023");
}
void valve2Aclkwise() {
  valve_Aclkwise( motorSet2, "valve 2", "1024");
}

// valve 3 ------------------------------------------
void valve3Close() {
  valve_Close( switch_3A, motorSet3, "valve 3", "1030");
}
void valve3Open() {
  valve_Open( switch_3B, motorSet3, "valve 3", "1031");
}
void valve3Clkwise() {
  valve_Clkwise( motorSet3, "valve 3", "1033");
}
void valve3Aclkwise() {
  valve_Aclkwise( motorSet3, "valve 3", "1034");
}

// valve 4 ------------------------------------------
void valve4Close() {
  valve_Close( switch_4A, motorSet4, "valve 4", "1040");
}
void valve4Open() {
  valve_Open( switch_4B, motorSet4, "valve 4", "1041");
}
void valve4Clkwise() {
  valve_Clkwise( motorSet4, "valve 4", "1043");
}
void valve4Aclkwise() {
  valve_Aclkwise( motorSet4, "valve 4", "1044");
}

// valve 5 ------------------------------------------
void valve5Close() {
  valve_Close( switch_5A, motorSet5, "valve 5", "1050");
}
void valve5Open() {
  valve_Open( switch_5B, motorSet5, "valve 5", "1051");
}
void valve5Clkwise() {
  valve_Clkwise( motorSet5, "valve 5", "1053");
}
void valve5Aclkwise() {
  valve_Aclkwise( motorSet5, "valve 5", "1054");
}

// valve 6 ------------------------------------------
void valve6Close() {
  valve_Close( switch_6A, motorSet6, "valve 6", "1060");
}
void valve6Open() {
  valve_Open( switch_6B, motorSet6, "valve 6", "1061");
}
void valve6Clkwise() {
  valve_Clkwise( motorSet6, "valve 6", "1063");
}
void valve6Aclkwise() {
  valve_Aclkwise( motorSet6, "valve 6", "1064");
}
