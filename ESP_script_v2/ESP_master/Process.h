
// valves in process
// v01 - valve_A1
// v02 - valve_A2
// v03 - valve_A3
// v04 - valve_A4
// v05 - valve_A5
// v06 - valve_A6
// v07 - valve_B1
// v08 - valve_B2
// v09 - valve_B3

// pump in process
// pump1 - heat pump
// pump2 - cooler pump


# include "ProcessFn.h"

int COIL_DRAIN_TIME = 5000;
int BOILER_RATED_TEMP = 100;
int WATER_CLEAN_TEMP = 95;
int WATER_HIGH_KEEP_TIME = 5;  // 10 seconds
int HOMOGENIZER_CLEAN_TIME = 5; // 10 seconds
int VAT_DRAIN_TIME = 5; // 10 seconds



int valve_reset() {
  int valve_reset_status = 1;
  int operation_valve[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9};

  dash_0025.display_(0);

  for (int i=0; i< sizeof(operation_valve); i=i+1) {
    if ( valveOpen( operation_valve[i]) == -1 || valveOpen( operation_valve[i]) == -2 ) {
      dash_0015.display_( operation_valve[i]);
      delay(1000);
      valve_reset_status = -1;
      break;
    }
    else if ( valveClose( operation_valve[i]) == -1 || valveOpen( operation_valve[i]) == -2) {
       dash_0020.display_( operation_valve[i]);
       delay(1000);
       valve_reset_status = -1;
       break;
    }
  }

  return valve_reset_status;

}




void Clean_Process() {
  int continue_process = 0;

  // Starting clean Process
  dash_2001.display_(0);
  Serial.println(" Starting Cleaing process");
  continue_process = 1;
  delay(2000);

  // Add water to tank ,  EN-continue Bk - main menue
  dash_2005.display_(0);
  Serial.println(" Add water to tank");
  reset_buttons();
  while (continue_process == 1) {
    if ( enter_BN.pressed ) {
      enter_BN.pressed = false;
      break;
    }
    else if ( back_BN.pressed) {
      enter_BN.pressed = false;
      continue_process = -1;
    }

    delay(10);
  }

  // heat water to WATER_CLEAN_TEMP
  if ( continue_process == 1) {
    dash_2010.display_(0);
    Serial.println(" heat water to WATER_CLEAN_TEMP");
    delay(2000);
    continue_process = HeatToTemp( WATER_CLEAN_TEMP);
  }

  // keep water temp WATER_CLEAN_TEMP at WATER_HIGH_KEEP_TIME seconds
  if ( continue_process == 1) {
    dash_2020.display_(0);
    Serial.println(" keep water temp WATER_CLEAN_TEMP at WATER_HIGH_KEEP_TIME seconds");
    delay(2000);
    continue_process = KeepTempLvl( WATER_HIGH_KEEP_TIME);
  }
    
  // homogenize clean
  if ( continue_process == 1){
    dash_2060.display_(0);
    Serial.println(" homogenize clean");
    delay(2000);
    continue_process = Homogenize( HOMOGENIZER_CLEAN_TIME);
  }

  // Drain water
  if ( continue_process == 1){
    dash_2080.display_(0);
    Serial.println(" Drain water");
    delay(2000);
    continue_process = DrainVat( VAT_DRAIN_TIME);
  }

    
  if ( continue_process == 1 ) {
    dash_2090.display_(0);
    Serial.println("Process Complete");
    delay(2000);
  }
  else {
    dash_2530.display_(0);
    Serial.println("Tank clean Process fail");
    delay(2000);
  }


}


void Milk_Process() {
  
}

