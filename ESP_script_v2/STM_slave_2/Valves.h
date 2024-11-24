
//Communication Protocol STM32 2
//2010 - valve A1 close call
//2011 - valve A1 open call
//2020 - valve A2 close call
//2021 - valve A2 open call
//2030 - valve A3 close call
//2031 - valve A3 open call
//2040 - valve A4 close call
//2041 - valve A4 open call
//2050 - valve A5 close call
//2051 - valve A5 open call
//2060 - valve A6 close call
//2061 - valve A6 open call

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
    if ( (millis() - time_start) > 5000) {
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
  valve_Close( switch_1A, motorSet1, "valve 1", "2010");
}
void valve1Open() {
  valve_Open( switch_1B, motorSet1, "valve 1", "2011");
}
void valve1Clkwise() {
  valve_Clkwise( motorSet1, "valve 1", "2013");
}
void valve1Aclkwise() {
  valve_Aclkwise( motorSet1, "valve 1", "2014");
}

// valve 2 ------------------------------------------
void valve2Close() {
  valve_Close( switch_2A, motorSet2, "valve 2", "2020");
}
void valve2Open() {
  valve_Open( switch_2B, motorSet2, "valve 2", "2021");
}
void valve2Clkwise() {
  valve_Clkwise( motorSet2, "valve 2", "2023");
}
void valve2Aclkwise() {
  valve_Aclkwise( motorSet2, "valve 2", "2024");
}

// valve 3 ------------------------------------------
void valve3Close() {
  valve_Close( switch_3A, motorSet3, "valve 3", "2030");
}
void valve3Open() {
  valve_Open( switch_3B, motorSet3, "valve 3", "2031");
}
void valve3Clkwise() {
  valve_Clkwise( motorSet3, "valve 3", "2033");
}
void valve3Aclkwise() {
  valve_Aclkwise( motorSet3, "valve 3", "2034");
}

// valve 4 ------------------------------------------
void valve4Close() {
  valve_Close( switch_4A, motorSet4, "valve 4", "2040");
}
void valve4Open() {
  valve_Open( switch_4B, motorSet4, "valve 4", "2041");
}
void valve4Clkwise() {
  valve_Clkwise( motorSet4, "valve 4", "2043");
}
void valve4Aclkwise() {
  valve_Aclkwise( motorSet4, "valve 4", "2044");
}

// valve 5 ------------------------------------------
void valve5Close() {
  valve_Close( switch_5A, motorSet5, "valve 5", "2050");
}
void valve5Open() {
  valve_Open( switch_5B, motorSet5, "valve 5", "2051");
}
void valve5Clkwise() {
  valve_Clkwise( motorSet5, "valve 5", "2053");
}
void valve5Aclkwise() {
  valve_Aclkwise( motorSet5, "valve 5", "2054");
}

// valve 6 ------------------------------------------
void valve6Close() {
  valve_Close( switch_6A, motorSet6, "valve 6", "2060");
}
void valve6Open() {
  valve_Open( switch_6B, motorSet6, "valve 6", "2061");
}
void valve6Clkwise() {
  valve_Clkwise( motorSet6, "valve 6", "2063");
}
void valve6Aclkwise() {
  valve_Aclkwise( motorSet6, "valve 6", "2064");
}
