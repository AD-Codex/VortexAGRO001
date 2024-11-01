
// valves in process
// v01 - valve_A1
// v02 - valve_A2
// v03 - valve_A3
// v04 - valve_A4
// v05 - valve_A5
// v06 - valve_A6
// v07 - valve_B1
// v08 - valve_B2
// v08 - valve_B3
// v09 - valve_B4



int valve_reset() {
  int valve_reset_status = 1;
  int operation_valve[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9};

  dash_0025.display_(0);

  for (int i=0; i<len(operation_valve); i=i+1) {
    if ( valveOpen( operation_valve[i]) == -1 || valveOpen( operation_valve[i]) == -2 ) {
      dash_0015.display_( operation_valve[i]);
      delay(1000);
      valve_reset_status = -1;
      break;
    }
    else if ( valveClose( operation_valve[i]) == -1 || valveOpen( operation_valve[i]) == -2) {
       dash_0020.display( operation_valve[i]);
       delay(1000);
       valve_reset_status = -1;
       break;
    }
  }

  return valve_reset_status;

}

void HeatToLevel( int temp) {
  valve_A1.open(false);
  valve_A2.open(false);
  valve_A3.open(false);
  valve_A4.open(false);
  valve_A5.open(false);
  valve_B2.open(false);

  while ( true) {
    if ( TSensor1.Read > temp) {

    }
    else {
      Serial.println(" Boiler Temp not");
    }

    delay(1000);
  }

  
}

void Clean_Process() {
  int continue_process = 0;

  // Starting clean Process
  dash_2001.display_(0);
  delay(1000);

  // Add water to tank ,  EN-continue Bk - main menue
  dash_2005.display_(0);
  while (true) {
    if ( enter_BN.pressed ) {
      enter_BN.pressed = false;
      continue_process = 1;
      break;
    }
    else if ( back_BN.pressed) {
      enter_BN.pressed = false;
      continue_process = -1;
    }

    delay(10);
  }

  // continue if En pressed
  if ( continue_process == 1) {

  }




}

