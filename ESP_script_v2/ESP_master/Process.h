
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
# include "Flash.h"


// valve reset Fn ----------------------------------------
void valve_reset( int valve_numbers[], int size) {
  int valve_reset_status = 1;
  int operation_valve[size];
    
  
  for (int i = 0; i < size; i++) {
      operation_valve[i] = valve_numbers[i];
  }

  dash_0025.display_(0);
  while (true) {
    if ( Switch_status() == 1) {
      break;
    }
    delay(10);
  }
  delay(1000);

  dash_0027.display_(0);
  for (int i=0; i<9; i=i+1) {
    int valveOpen_state = valveOpen( operation_valve[i]);
    if ( valveOpen_state == 0) {
      break;
    }
    else if ( valveOpen_state == -1 || valveOpen_state == -2 ) {
      dash_0015.display_( operation_valve[i]);
      valve_reset_status = 0;
      break;
    }
    
    int valveClose_state = valveClose( operation_valve[i]);
    if ( valveClose_state == 0) {
      break;
    }
    else if ( valveClose_state== -1 || valveClose_state == -2) {
       dash_0020.display_( operation_valve[i]);
       valve_reset_status = 0;
       break;
    }
  }


  // enter button press
  if ( valve_reset_status == 0) {
    enter_BN.pressed = false; back_BN.pressed = false;
    while ( true) {
      if (enter_BN.pressed || back_BN.pressed) {
        enter_BN.pressed = false;
        back_BN.pressed = false;
        break;
      }
      delay(100);
    }

  }


}


// clean process --------------------------------------
void Clean_Process() {
  int continue_process = 0;

  // Starting clean Process
  if ( EEPROM_state == 0) {
    dash_2001.display_(0);
    Serial.println(" Starting Cleaing process");
    continue_process = delay5s();
  }

  // Add water to tank ,  EN-continue Bk - main menue
  if ( continue_process == 1 || EEPROM_state == 2005) {
    dash_2005.display_(0);
    state_save(2005);
    Serial.println(" Add water to tank");
    continue_process = FillVat();
  }

  // heat water to WATER_HEAT_TEMP
  if ( continue_process == 1 || EEPROM_state == 2010) {
    dash_2010.display_(-1*WATER_HEAT_TEMP);
    state_save(2010);
    Serial.println(" heat water to WATER_HEAT_TEMP");
    continue_process = HeatToTemp( WATER_HEAT_TEMP);
  }

  // keep water temp WATER_HEAT_TEMP at WATER_HIGH_KEEP_TIME seconds
  if ( continue_process == 1 || EEPROM_state == 2020) {
    dash_2020.display_(WATER_HIGH_KEEP_TIME);
    state_save(2020);
    Serial.println(" keep water temp WATER_HEAT_TEMP at WATER_HIGH_KEEP_TIME seconds");
    continue_process = KeepTempLvl( WATER_HIGH_KEEP_TIME);
  }
    
  // homogenize clean
  if ( continue_process == 1 || EEPROM_state == 2060){
    dash_2060.display_(0);
    state_save(2060);
    Serial.println(" homogenize clean");
    continue_process = Homogenize( HOMOGENIZER_CLEAN_TIME);
  }

  // Drain water
  if ( continue_process == 1 || EEPROM_state == 2080){
    dash_2080.display_(0);
    state_save(2080);
    Serial.println(" Drain water");
    continue_process = DrainVat();
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

  state_save(0);


}


// curd process ---------------------------------------
void Milk_Process() {
  int continue_process = 0;

  // Starting Milk Process
  if ( EEPROM_state == 0) {
    dash_3001.display_(0);
    Serial.println(" Starting Milk process");
    continue_process = delay5s();
  }
  

  // Add Milk to tank ,  EN-continue Bk - main menue
  if ( continue_process == 1 || EEPROM_state == 3005) {
    dash_3005.display_(0);
    state_save(3005);
    Serial.println(" Add Milk to tank");
    continue_process = FillVat();
  }

  // heat Milk to MILK_HIGH_TEMP
  if ( continue_process == 1 || EEPROM_state == 3010) {
    dash_3010.display_(0);
    state_save(3010);
    Serial.println(" heat milk to MILK_HIGH_TEMP");
    continue_process = HeatToTemp( MILK_HIGH_TEMP);
  }

  // keep milk temp MILK_HIGH_TEMP at MILK_HIGH_TEMP_TIME seconds
  if ( continue_process == 1 || EEPROM_state == 3020) {
    dash_3020.display_( MILK_HIGH_TEMP_TIME);
    state_save(3020);
    Serial.println(" keep water temp MILK_HIGH_TEMP at MILK_HIGH_TEMP_TIME seconds");
    continue_process = KeepTempLvl( MILK_HIGH_TEMP_TIME);
  }

  // Cool milk to MILK_MIDDLE_TEMP
  if ( continue_process == 1 || EEPROM_state == 3030) {
    dash_3030.display_( -1 * MILK_MIDDLE_TEMP);
    state_save(3030);
    Serial.println(" cool milk to MILK_MIDDLE_TEMP");
    continue_process = CoolToTemp( MILK_MIDDLE_TEMP, HEAT_WATER_DRAIN_TIME);
  }

  // Add Culture to milk in 
  if ( continue_process == 1 || EEPROM_state == 3050) {
    dash_3050.display_(0);
    state_save(3050);
    Serial.println(" Add Culture Milk tank");
    continue_process = AddCulture();
  }

  // Homogenize process at MILK_HOMOGENIZE_TIME
  if ( continue_process == 1 || EEPROM_state == 3060) {
    dash_3060.display_( MILK_HOMOGENIZE_TIME);
    state_save(3060);
    Serial.println(" Homogenize process at MILK_HOMOGENIZE_TIME");
    continue_process = Homogenize(MILK_HOMOGENIZE_TIME);
  }

  // Cool milk to MILK_LOW_TEMP
  if ( continue_process == 1 || EEPROM_state == 3070) {
    dash_3070.display_( -1 * MILK_LOW_TEMP);
    state_save(3070);
    Serial.println(" cool milk to MILK_LOW_TEMP");
    continue_process = CoolToTemp( MILK_LOW_TEMP, 0);
  }


  if ( continue_process == 1 ) {
    dash_3900.display_(0);
    Serial.println("Process Complete");
    delay(2000);
  }
  else {
    dash_3520.display_(0);
    Serial.println("Milk Process fail");
    delay(2000);
  }

  state_save(0);
  
}


// incomplete process continue ----------------------------
void PowerOff_process() {
  int PowerOff_process = 1;

  if ( EEPROM_state == 0 ) {
    Serial.println("EEPROM_state = 0");
  }
  else {
    dash_0060.display_(0);
    while ( true) {
      if ( enter_BN.pressed ) {
        enter_BN.pressed = false;
        if ( EEPROM_state > 3000 && EEPROM_state < 4000) {
          Milk_Process();
        }
        else if (EEPROM_state > 2000 && EEPROM_state < 3000 ) {
          Clean_Process();
        }
        break;
      }
      else if ( back_BN.pressed) {
        back_BN.pressed = false;
        state_save(0);
        break;
      }
      delay(10);

    }
  }

}


// system diagnostic process ------------------------------
void Diagnostic_process( ) {

  // boil pump check
  boilPump.Trigger(true);
  dash_6010.display_(0);
  Serial.println("Does Boil pump on");
  while (true) {
    if ( enter_BN.pressed ) {
      enter_BN.pressed = false;
      break;
    }
    else if ( back_BN.pressed )  {
      back_BN.pressed = false;
      Serial.println("Boil pump not on");
      break;
    }
    delay(10);
  }
  boilPump.Trigger(false);

  delay(2000);


  // cool pump check
  coolPump.Trigger(true);
  dash_6020.display_(0);
  Serial.println("Does cool pump on");
  while (true) {
    if ( enter_BN.pressed ) {
      enter_BN.pressed = false;
      break;
    }
    else if ( back_BN.pressed )  {
      back_BN.pressed = false;
      Serial.println("cool pump not on");
      break;
    }
    delay(10);
  }
  coolPump.Trigger(false);

  
  // mixer pump check
  mixer.Trigger(true);
  dash_6030.display_(0);
  Serial.println("Does mixer on");
  while (true) {
    if ( enter_BN.pressed ) {
      enter_BN.pressed = false;
      break;
    }
    else if ( back_BN.pressed )  {
      back_BN.pressed = false;
      Serial.println("mixer not on");
      break;
    }
    delay(10);
  }
  mixer.Trigger(false);

  
  // Homoginizer on check
  homogenizerOn.Trigger(false);
  delay(1000);
  homogenizerOn.Trigger(true);
  dash_6040.display_(0);
  Serial.println("Does homogenizer on");
  while (true) {
    if ( enter_BN.pressed ) {
      enter_BN.pressed = false;
      break;
    }
    else if ( back_BN.pressed )  {
      back_BN.pressed = false;
      Serial.println("homogenizer not on");
      break;
    }
    delay(10);
  }


  // Homoginizer off check
  homogenizerOff.Trigger(false);
  delay(1000);
  homogenizerOff.Trigger(true);
  dash_6050.display_(0);
  Serial.println("Does homogenizer off");
  while (true) {
    if ( enter_BN.pressed ) {
      enter_BN.pressed = false;
      break;
    }
    else if ( back_BN.pressed )  {
      back_BN.pressed = false;
      Serial.println("homogenizer not off");
      break;
    }
    delay(10);
  }

  
}

