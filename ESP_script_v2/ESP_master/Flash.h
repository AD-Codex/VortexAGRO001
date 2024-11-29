
#include <Preferences.h>

Preferences preferences;


int BOILER_RATED_TEMP; //= 100;      // B_R_T - boiler max heat temp
int WATER_HEAT_TEMP; // = 95;         // W_H_T - vat tank water heat temp

int WATER_HIGH_KEEP_TIME; // = 10;    // W_H_K_T - Clean process vat high heat water keep time
int HOMOGENIZER_CLEAN_TIME; // = 10;  // H_C_T - Clean process homogenizer clean time

int MILK_HIGH_TEMP; // = 95;          // M_H_T - Milk process milk high heat temp
int MILK_MIDDLE_TEMP; // = 65;        // M_M_T - Milk process milk middle heat temp
int MILK_LOW_TEMP; // = 45;           // M_L_T - Milk process milk low heat temp

int MILK_HIGH_TEMP_TIME; // = 10;     // M_H_T_T - Time milk keep at hig temp
// int MILK_MIDDLE_TEMP_TIME = 10;
// int MILK_LOW_TEMP_TIME = 10;

int MILK_HOMOGENIZE_TIME; // = 10;    // M_H_T - homogenize time
int HEAT_WATER_DRAIN_TIME; // = 5;    // H_W_D_T - darin water time in coile, heat to cool change

int EEPROM_state;                     // state, 0-no save



// begin flash EEPROM at first time --------------------------------------
void begin_Flash() {
  preferences.begin("project001", false);
  preferences.clear();

  preferences.putUInt("state", 0);

  preferences.putUInt("B_R_T", 100);

  preferences.putUInt("W_H_T", 95);

  preferences.putUInt("W_H_K_T", 15);
  preferences.putUInt("H_C_T", 10);

  preferences.putUInt("M_H_T", 95);
  preferences.putUInt("M_M_T", 65);
  preferences.putUInt("M_L_T", 45);

  preferences.putUInt("M_H_T_T", 10);
  preferences.putUInt("M_H_T", 10);

  preferences.putUInt("H_W_D_T", 45);

  preferences.end();

}



// initialize EEPROM at the begining ----------------------------------------------
void init_Flash() {
  preferences.begin("project001", false);

  EEPROM_state = preferences.getUInt("state", 0);

  BOILER_RATED_TEMP = preferences.getUInt("B_R_T", 100);             // boiler max heat temp
  WATER_HEAT_TEMP = preferences.getUInt("W_H_T", 95);                  // vat tank water heat temp

  WATER_HIGH_KEEP_TIME = preferences.getUInt("W_H_K_T", 10);        // Clean process vat high heat water keep time
  HOMOGENIZER_CLEAN_TIME = preferences.getUInt("H_C_T", 10);    // Clean process homogenizer clean time

  MILK_HIGH_TEMP = preferences.getUInt("M_H_T", 95);                    // Milk process milk high heat temp
  MILK_MIDDLE_TEMP = preferences.getUInt("M_M_T", 65);                // Milk process milk middle heat temp
  MILK_LOW_TEMP = preferences.getUInt("M_L_T", 45);                      // Milk process milk low heat temp

  MILK_HIGH_TEMP_TIME = preferences.getUInt("M_H_T_T", 10);          // Time milk keep at hig temp
  // MILK_MIDDLE_TEMP_TIME = preferences.getUInt("MILK_MIDDLE_TEMP_TIME", 10);
  // MILK_LOW_TEMP_TIME = preferences.getUInt("MILK_LOW_TEMP_TIME", 10);

  MILK_HOMOGENIZE_TIME = preferences.getUInt("M_H_T", 10);        // homogenize time
  HEAT_WATER_DRAIN_TIME = preferences.getUInt("H_W_D_T", 5);       // darin water time in coile, heat to cool change

  preferences.end();

}


// save the customize setting values according to state  -------------------------------------------------------
void flash_save(int state, int dis_val) {
  Serial.printf("state %d, val %d ", state, dis_val);
  dash_4901.display_(0);

  enter_BN.pressed = false; enter_BN.pressed = false;
  while(true) {
    if ( enter_BN.pressed ) {
      enter_BN.pressed = false;

      if ( state == 4111) {
        if ( dis_val != WATER_HEAT_TEMP) {
          preferences.begin("project001", false);
          preferences.putUInt("W_H_T", dis_val);
          WATER_HEAT_TEMP = dis_val;
          // WATER_HEAT_TEMP = preferences.getUInt("W_H_T", 95); 
          preferences.end();
        }
      }
      else if ( state == 4121) {
        if ( dis_val != MILK_HIGH_TEMP) {
          preferences.begin("project001", false);
          preferences.putUInt("M_H_T", dis_val);
          MILK_HIGH_TEMP = dis_val;
          // MILK_HIGH_TEMP = preferences.getUInt("M_H_T", 95); 
          preferences.end();
        }
      }
      else if ( state == 4131) {
        if ( dis_val != MILK_MIDDLE_TEMP) {
          preferences.begin("project001", false);
          preferences.putUInt("M_M_T", dis_val);
          MILK_MIDDLE_TEMP = dis_val;
          // MILK_MIDDLE_TEMP = preferences.getUInt("M_M_T", 65); 
          preferences.end();
        }
      }
      else if ( state == 4141) {
        if ( dis_val != MILK_LOW_TEMP) {
          preferences.begin("project001", false);
          preferences.putUInt("M_M_T", dis_val);
          MILK_LOW_TEMP = dis_val;
          // MILK_LOW_TEMP = preferences.getUInt("M_L_T", 45); 
          preferences.end();
        }
      }
      else if ( state == 4211) {
        if ( dis_val != WATER_HIGH_KEEP_TIME) {
          preferences.begin("project001", false);
          preferences.putUInt("W_H_K_T", dis_val);
          WATER_HIGH_KEEP_TIME = dis_val;
          // WATER_HIGH_KEEP_TIME = preferences.getUInt("W_H_K_T", 10); 
          preferences.end();
        }
      }
      else if ( state == 4221) {
        if ( dis_val != HOMOGENIZER_CLEAN_TIME) {
          preferences.begin("project001", false);
          preferences.putUInt("H_C_T", dis_val);
          HOMOGENIZER_CLEAN_TIME = dis_val;
          // HOMOGENIZER_CLEAN_TIME = preferences.getUInt("H_C_T", 10); 
          preferences.end();
        }
      }
      else if ( state == 4231) {
        if ( dis_val != MILK_HIGH_TEMP_TIME) {
          preferences.begin("project001", false);
          preferences.putUInt("M_H_T_T", dis_val);
          MILK_HIGH_TEMP_TIME = dis_val;
          // MILK_HIGH_TEMP_TIME = preferences.getUInt("M_H_T_T", 10); 
          preferences.end();
        }
      }
      else if ( state == 4241) {
        if ( dis_val != MILK_HOMOGENIZE_TIME) {
          preferences.begin("project001", false);
          preferences.putUInt("M_H_T", dis_val);
          MILK_HOMOGENIZE_TIME = dis_val;
          // MILK_HOMOGENIZE_TIME = preferences.getUInt("M_H_T", 10); 
          preferences.end();
        }
      }


      break;
    }
    else if ( back_BN.pressed) {
      enter_BN.pressed = false;
      
      break;
    }

    delay(10);
  }
  
}


// save the process state ----------------------------------
void state_save( int state) {
  EEPROM_state = state;
  preferences.begin("project001", false);
  preferences.putUInt("state", state);
  preferences.end();
}

