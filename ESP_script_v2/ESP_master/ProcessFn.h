// valves in process
// v01 - valve_A1
// v02 - valve_A2
// v03 - valve_A3
// v04 - valve_A4
// v05 - valve_A5
// v06 - valve_A6
// v07 - valve_B1
// v08 - valve_B2
// v0 - valve_B3

// pump in process
// pump1 - heat pump
// pump2 - cooler pump


// delay 5s with input sensitive  .................
// return -1 if exit process
int delay5s() {
  int start_time = millis();
  int delay5s_state = 1;

  // reset_buttons();
  Serial.print("button ");
  Serial.println(back_BN.pressed);
  while ( (millis() - start_time) <= 5000  && delay5s_state == 1) {
    if ( back_BN.pressed == true ) {
      back_BN.pressed = false;
      dash_0030.display_(0);

      while ( true ) {
        if ( back_BN.pressed == true ) {
          back_BN.pressed = false;
          delay5s_state = -1;
          break;
        }
        else if (down_BN.pressed == true) {
          down_BN.pressed = false;
          delay5s_state = 0;
          break;
        }
        else if ( enter_BN.pressed == true) {
          enter_BN.pressed = false;
          delay5s_state = 1;
          break;
        }
        delay(10);

      }

    }

    delay(50);
  }

  return delay5s_state;
}


// heat the tank to given temp ..................
int HeatToTemp( int temp) {
  int HeatToTemp_process = 0;

  valve_A1.open(false);
  valve_A2.open(false);
  valve_A3.open(false);
  valve_A4.open(false);
  valve_A5.open(false);
  valve_A6.open(false);
  valve_B1.open(false);
  valve_B2.open(false);


  Serial.println(" Starting Heating Process");

  HeatToTemp_process = delay5s();
  if ( HeatToTemp_process == 1) {
    HeatToTemp_process = valve_A4.open(true);
    HeatToTemp_process = valve_A1.open(true);
    HeatToTemp_process = valve_A3.open(true);
    
    if ( HeatToTemp_process == 1) {
      boilPump.Trigger(true);
      mixer.Trigger(true);
      // delay(2000);

      int actualHeatTemp = 0;
      while ( HeatToTemp_process == 1) {
        HeatToTemp_process = delay5s();

        if ( true) {
          actualHeatTemp = TSensor2.Read();
          if ( actualHeatTemp >= temp ) {
            break;
          }

        }
        else {
          Serial.println(" Boiler Temp not at range");
        }

        dash_3010.display_( -1 * actualHeatTemp);

        
      }
    }
    

    mixer.Trigger(false);
    boilPump.Trigger(false);
    valve_A4.open(false);
    valve_A1.open(false);
    valve_A3.open(false);
    delay(2000);

  }


  if ( HeatToTemp_process == 1) {
    Serial.println(" Reach to given temp");
    HeatToTemp_process = 1;
  }
  else if ( HeatToTemp_process == 0) {
    Serial.println(" skip process");
    HeatToTemp_process = 1;
  } 
  else {
    Serial.println(" Process terminate with error");
    HeatToTemp_process = -1;
    buzzerBeep(3);
  }


  return HeatToTemp_process;
}


// cool the tank to given temp
int CoolToTemp( int temp, int drain_time) {
  int coolToTemp_process = 0;
  
  valve_A1.open(false);
  valve_A2.open(false);
  valve_A3.open(false);
  valve_A4.open(false);
  valve_A5.open(false);
  valve_A6.open(false);
  valve_B1.open(false);
  valve_B2.open(false);


  Serial.println(" Drain store water");

  coolToTemp_process = delay5s();
  if ( coolToTemp_process == 1) {
    valve_A5.open(true);
    valve_B1.open(true);

    if ( drain_time > 0) {
      valve_B2.open(true);
      coolPump.Trigger(true);
      delay(2000);

      for ( int DrainInt = 0; DrainInt < (drain_time*12); DrainInt = DrainInt + 1) {
        coolToTemp_process = delay5s();
        if ( coolToTemp_process != 1) {
          break;
        }
      }
      valve_B2.open(false);
      coolPump.Trigger(false);
    }
    

    Serial.println(" Starting Cooling process");
    coolToTemp_process = valve_A6.open(true);
    if ( coolToTemp_process == 1) {
      coolPump.Trigger(true);
      mixer.Trigger(true);
      delay(2000);

      while ( coolToTemp_process == 1) {
        int actualTemp = TSensor2.Read();
        if ( actualTemp <= temp ) {
          break;
        }

        dash_3030.display_( -1 * actualTemp);

        coolToTemp_process = delay5s();

      }
    }
    

    mixer.Trigger(false);
    coolPump.Trigger(false);
    valve_A6.open(false);
    valve_B1.open(false);
    valve_A5.open(false);
    delay(2000);

  }


  if ( coolToTemp_process == 1) {
    Serial.println(" Reach to given temp");
    coolToTemp_process = 1;
  }
  else if ( coolToTemp_process == 0) {
    Serial.println("  skip process");
    coolToTemp_process = 1;
  }
  else {
    Serial.println(" Process terminate with error");
    coolToTemp_process = -1;
    buzzerBeep(3);
  }


  return coolToTemp_process;
}


// keep tank at stady temp ..........................
int KeepTempLvl( int time)  {
  int KeepTempLvl_process = 0;

  valve_A1.open(false);
  valve_A2.open(false);
  valve_A3.open(false);
  valve_A4.open(false);
  valve_A5.open(false);
  valve_A6.open(false);
  valve_B1.open(false);
  valve_B2.open(false);


  Serial.println(" Starting Keeping process");

  KeepTempLvl_process = delay5s();
  if ( KeepTempLvl_process == 1) {
    KeepTempLvl_process = valve_A4.open(true);
    KeepTempLvl_process = valve_A2.open(true);
    if ( KeepTempLvl_process == 1) {
      boilPump.Trigger(true);
      mixer.Trigger(true);
      delay(2000);

      for ( int KeepTempInt = 0; KeepTempInt < (time*12); KeepTempInt = KeepTempInt + 1) {
        dash_0040.display_(time*60 - KeepTempInt*5);
        KeepTempLvl_process = delay5s();
        buzzerBeep(1);
        if ( KeepTempLvl_process != 1) {
          break;
        }
      }
    }
    

    mixer.Trigger(false);
    boilPump.Trigger(false);
    valve_A4.open(false);
    valve_A2.open(false);
    delay(2000);

  }


  if ( KeepTempLvl_process == 1) {
    Serial.println(" keep time process complete");
    KeepTempLvl_process = 1;
  }
  else if ( KeepTempLvl_process == 0) {
    Serial.println(" skip process");
    KeepTempLvl_process = 1;
  }
  else {
    Serial.println(" keep time Process terminate with error");
    KeepTempLvl_process = -1;
    buzzerBeep(3);
  }


  return KeepTempLvl_process;
}


// Homogenize start ............................
int Homogenize( int time) {
  int Homogenize_process = 0;

  valve_B3.open(false);

  Serial.println(" Starting Homogenize process");

  Homogenize_process = delay5s();
  if ( Homogenize_process == 1) {
    Homogenize_process = valve_B3.open(true);
    if ( Homogenize_process == 1) {
      homogenizerOn.Click();
      delay(2000);

      for ( int HomogenizeInt = 0; HomogenizeInt < (time*12); HomogenizeInt = HomogenizeInt + 1 ) {
        dash_0050.display_(time*60 - HomogenizeInt*5);
        Homogenize_process = delay5s();
        buzzerBeep(1);
        if ( Homogenize_process != 1) {
          break;
        }
      }

      homogenizerOff.Click();
    }
    
    valve_B3.open(false);
    delay(2000);

  }


  if ( Homogenize_process == 1) {
    Serial.println(" Homogenize process complete");
    Homogenize_process = 1;
  }
  else if ( Homogenize_process == 0) {
    Serial.println(" skip process");
    Homogenize_process = 1;
  }
  else {
    Serial.println(" Homogenize Process terminate with error");
    Homogenize_process = -1;
    buzzerBeep(3);
  }


  return Homogenize_process;
}


// Fill the vat at given time .....................
int FillVat() {
  int Fill_process = 0;

  Fill_process = 1;
  reset_buttons();
  Serial.println("Start Fill process");
  buzzerHigh(true);
  while (Fill_process == 1) {
    if ( enter_BN.pressed ) {
      enter_BN.pressed = false;
      break;
    }
    else if ( back_BN.pressed) {
      back_BN.pressed = false;
      Fill_process = -1;
    }

    delay(10);
  }
  buzzerHigh(false);

  return Fill_process;
}


// Drain vat at given time ..........................
int DrainVat() {
  int Drain_process = 0;

  Drain_process = 1;
  reset_buttons();
  Serial.println("Start Drain process");
  buzzerHigh(true);
  while (Drain_process == 1) {
    if ( enter_BN.pressed ) {
      enter_BN.pressed = false;
      break;
    }
    else if ( back_BN.pressed) {
      back_BN.pressed = false;
      Drain_process = -1;
    }

    delay(10);
  }
  buzzerHigh(false);

  return Drain_process;
}


// Add culture ............................
int AddCulture() {
  int AddCulture_process = 0;

  AddCulture_process = 1;
  reset_buttons();
  Serial.println("Start Culture process");
  buzzerHigh(true);
  while (AddCulture_process == 1) {
    if ( enter_BN.pressed ) {
      enter_BN.pressed = false;
      break;
    }
    else if ( back_BN.pressed) {
      back_BN.pressed = false;
      AddCulture_process = -1;
    }

    delay(10);
  }
  buzzerHigh(false);

  return AddCulture_process;
}

