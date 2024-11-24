
// list - current state, enter state, back state, up state, down state  
// 9999 - update comming soon
// 0 - invalid

int state_list[][5] = {
  // 1000 ---------------------
  {1000, 1001,    0,    0, 2000},  
  {1001,    0, 1000,    0,    0}, 

  // 2000 ----------------------
  {2000, 2001,    0, 1000, 3000},
  {2001,    0, 2000,    0,    0},

  // 3000 ----------------------
  {3000, 3001,    0, 2000, 4000},
  {3001,    0, 3000,    0,    0},

  // 4000 -----------------------
  {4000, 4010,    0, 3000, 5000},

  {4010, 4110, 4000,    0, 4020},

  {4110, 4111, 4010,    0, 4120},
  {4111, 4901, 4110,    8,    2},
  {4120, 4121, 4010, 4110, 4130},
  {4121, 4901, 4120,    8,    2},
  {4130, 4131, 4010, 4120, 4140},
  {4131, 4901, 4130,    8,    2},
  {4140, 4141, 4010, 4130,    0},
  {4141, 4901, 4140,    8,    2},

  {4020, 4210, 4000, 4010,    0},

  {4210, 4211, 4020,    0, 4220},
  {4211, 4901, 4210,    8,    2},
  {4220, 4221, 4020, 4210, 4230},
  {4221, 4901, 4220,    8,    2},
  {4230, 4231, 4020, 4220, 4240},
  {4231, 4901, 4230,    8,    2},
  {4240, 4241, 4020, 4230,    0},
  {4241, 4901, 4240,    8,    2},

  {4901, 4010, 4010,    0,    0},

  
  // 5000 -----------------------
  {5000, 5001,    0, 4000, 6000},

  {5001, 5010, 5000,    0, 5002},

  {5010, 5015, 5001,    0, 5020},
  {5015,    0, 5010,    0,    0},
  {5020, 5025, 5001, 5010, 5030},
  {5025,    0, 5020,    0,    0},
  {5030, 5035, 5001, 5020,    0},
  {5035,    0, 5030,    0,    0},


  {5002, 5201, 5000, 5001, 5003},

  {5201, 5251, 5002,    0, 5202},
  {5202, 5251, 5002, 5201, 5203},
  {5203, 5251, 5002, 5202, 5204},
  {5204, 5251, 5002, 5203, 5205},
  {5205, 5251, 5002, 5204, 5206},
  {5206, 5251, 5002, 5205, 5207},
  {5207, 5251, 5002, 5206, 5208},
  {5208, 5251, 5002, 5207, 5209},
  {5209, 5251, 5002, 5208, 5210},
  {5210, 5251, 5002, 5209, 5211},
  {5211, 5251, 5002, 5210, 5212},
  {5212, 5251, 5002, 5211,    0},

  {5251, 5260, 5201,    0, 5252},
  {5252, 5261, 5201, 5251, 5253},
  {5253, 5262, 5201, 5252, 5254},
  {5254, 5263, 5201, 5253,    0},

  {5260,    0, 5251,    0,    0},
  {5261,    0, 5252,    0,    0},
  {5262, 5262,    0,    0,    0},
  {5263, 5263,    0,    0,    0},
  {5270,    0, 5251,    0,    0},
  {5271,    0, 5252,    0,    0},


  {5003, 5320, 5000, 5002,    0},

  {5320, 5325, 5003,    0, 5330},
  {5325,    0, 5320,    0,    0},
  {5330, 5335, 5003, 5320, 5340},
  {5335,    0, 5330,    0,    0},
  {5340, 5345, 5003, 5330, 5350},
  {5345,    0, 5340,    0,    0},
  {5350, 5355, 5003, 5340, 5360},
  {5355,    0, 5350,    0,    0},
  {5360, 5365, 5003, 5350, 5370},
  {5365,    0, 5360,    0,    0},
  {5370, 5375, 5003, 5360,    0},
  {5375,    0, 5370,    0,    0},

  // 6000 ----------------

  {6000, 6001,     0, 5000,    0},
  {6001,    0, 6000,    0,    0}
  
};

int state_list_index = -1;
int current_state = 1000;
int display_value = 0;
int old_state = current_state;
int valve_no = 0;


void dashboard(int state){
  int valveOpen_state = 0;
  int number = 0;

  Serial.println(state);

  if ( state == old_state) {
// continuos update set
    if ( state == 5263) {
      current_state = 5254;
    }
    else if ( state == 5262) {
      current_state = 5253;
    }

    switch (state) {
      case 4111:
          dash_4111.display_(-1*display_value);
          break;
      case 4121:
          dash_4121.display_(-1*display_value);
          break;
      case 4131:
          dash_4131.display_(-1*display_value);
          break;
      case 4141:
          dash_4141.display_(-1*display_value);
          break;
      case 4211:
          dash_4211.display_(display_value);
          break;
      case 4221:
          dash_4221.display_(display_value);
          break;
      case 4231:
          dash_4231.display_(display_value);
          break;
      case 4241:
          dash_4241.display_(display_value);
          break;
    }
    
  }
  else {
// update if and only state change --------------------------------
    switch (state) {
      case 1000:  
          dash_1000.display_(0);
          break;

      case 1001:
          valve_reset( FUNCTIONAL_VALES, FUNCTIONAL_VALES_SIZE);
          current_state = 1000;
          break;
          

  // Clean process -------------------------
      case 2000:  
          dash_2000.display_(0);
          break;

      case 2001:  
          Clean_Process();
          current_state = 2000;
          break;


  // Milk process ---------------------------
      case 3000:  
          dash_3000.display_(0);
          break;

      case 3001:  
          Milk_Process();
          current_state = 3000;
          break;


  // Settings ----------------------------------
      case 4000:  
          dash_4000.display_(0);
          break;
  // Temp setting    
      case 4010:
          dash_4010.display_(0);
          break;
  // Temp options
      case 4110:
          dash_4110.display_(0);
          break;
      case 4111:
          display_value = WATER_HEAT_TEMP;
          dash_4111.display_(-1*display_value);
          break;

      case 4120:
          dash_4120.display_(0);
          break;
      case 4121:
          display_value = MILK_HIGH_TEMP;
          dash_4121.display_(-1*display_value);
          break;

      case 4130:
          dash_4130.display_(0);
          break;
      case 4131:
          display_value = MILK_MIDDLE_TEMP;
          dash_4131.display_(-1*display_value);
          break;

      case 4140:
          dash_4140.display_(0);
          break;
      case 4141:
          display_value = MILK_LOW_TEMP;
          dash_4141.display_(-1*display_value);
          break;
  // Time setting    
      case 4020:
          dash_4020.display_(0);
          break;
  // Time options
      case 4210:
          dash_4210.display_(0);
          break;
      case 4211:
          display_value = WATER_HIGH_KEEP_TIME;
          dash_4211.display_(display_value);
          break;

      case 4220:
          dash_4220.display_(0);
          break;
      case 4221:
          display_value = HOMOGENIZER_CLEAN_TIME;
          dash_4221.display_(display_value);
          break;

      case 4230:
          dash_4230.display_(0);
          break;
      case 4231:
          display_value = MILK_HIGH_TEMP_TIME;
          dash_4231.display_(display_value);
          break;

      case 4240:
          dash_4240.display_(0);
          break;
      case 4241:
          display_value = MILK_HOMOGENIZE_TIME;
          dash_4241.display_(display_value);
          break;


      case 4901:
          dash_4901.display_(0);
          flash_save( old_state, display_value);
          break;



  // Testing -----------------------------------        
      case 5000:  
          dash_5000.display_(0);
          break;

      case 5001:  
          dash_5001.display_(0);
          break;

      case 5002:  
          valve_no = 0;
          dash_5002.display_(0);
          break;

      case 5003:  
          dash_5003.display_(0);
          break;
  // temp sensor testing ----------------------        
      case 5010:  
          dash_5010.display_(0);
          break;
      case 5015:  
          number = TSensor1.Read();
          dash_5015.display_(number);
          break;
          
      case 5020:  
          dash_5020.display_(0);
          break;
      case 5025:
          number = TSensor2.Read();
          dash_5025.display_(number);
          break;
          
      case 5030:  
          dash_5030.display_(0);
          break;
      case 5035:
          number = display_value;
          dash_5035.display_(number);
          break;
  // valve testing -----------------        
      case 5201:  
          valve_no = 1;
          dash_5201.display_(0);
          break;
      case 5202:  
          valve_no = 2;
          dash_5202.display_(0);
          break;
      case 5203:  
          valve_no = 3;
          dash_5203.display_(0);
          break;
      case 5204:  
          valve_no = 4;
          dash_5204.display_(0);
          break;
      case 5205:  
          valve_no = 5;
          dash_5205.display_(0);
          break;
      case 5206:  
          valve_no = 6;
          dash_5206.display_(0);
          break;
      case 5207:  
          valve_no = 7;
          dash_5207.display_(0);
          break;
      case 5208:  
          valve_no = 8;
          dash_5208.display_(0);
          break;
      case 5209:  
          valve_no = 9;
          dash_5209.display_(0);
          break;
      case 5210:  
          valve_no = 10;
          dash_5210.display_(0);
          break;
      case 5211:  
          valve_no = 11;
          dash_5211.display_(0);
          break;
      case 5212:  
          valve_no = 12;
          dash_5212.display_(0);
          break;

      case 5251:
          dash_5251.display_(0);
          break;
      case 5252:
          dash_5252.display_(0);
          break;
      case 5253:
          dash_5253.display_(0);
          break;
      case 5254:
          dash_5254.display_(0);
          break;

      case 5260:
          dash_5260.display_(0);
          if ( valveOpen(valve_no) == -1) {
            dash_5270.display_(0);
            delay(2000);
            current_state = 5251;
          }
          else {
            current_state = 5251;
          }
          enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
          break;
      case 5261:
          dash_5261.display_(0);
          if ( valveClose(valve_no) == -1) {
            dash_5271.display_(0);
            delay(2000);
            current_state = 5252;
          }
          else {
            current_state = 5252;
          }
          enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
          break;
      case 5262:
          valveClkTurn(valve_no);
          current_state = 5253;
          enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
          break;
      case 5263:
          valveAclkTurn(valve_no);
          current_state = 5254;
          enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
          break;


  // pump tesing -------------     
      case 5320:  
          dash_5320.display_(0);
          break;
      case 5325:  
          dash_5325.display_(0);
          boilPump.Trigger(true);
          delay(1000);
          current_state = 5320;
          enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
          break;
          
      case 5330:  
          dash_5330.display_(0);
          break;
      case 5335:  
          dash_5335.display_(0);
          boilPump.Trigger(false);
          delay(1000);
          current_state = 5330;
          enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
          break;
          
      case 5340:  
          dash_5340.display_(0);
          break;
      case 5345:  
          dash_5345.display_(0);
          coolPump.Trigger(true);
          delay(1000);
          current_state = 5340;
          enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
          break;
          
      case 5350:  
          dash_5350.display_(0);
          break;
      case 5355:  
          dash_5355.display_(0);
          coolPump.Trigger(false);
          delay(1000);
          current_state = 5350;
          enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
          break;
          
      case 5360:  
          dash_5360.display_(0);
          break;
      case 5365:  
          dash_5365.display_(0);
          mixer.Trigger(true);
          delay(1000);
          current_state = 5360;
          enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
          break;
          
      case 5370:  
          dash_5370.display_(0);
          break;
      case 5375:  
          dash_5375.display_(0);
          mixer.Trigger(false);
          delay(1000);
          current_state = 5370;
          enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
          break;


      // Diagnostics -------------
      case 6000:
        dash_6000.display_(0);
        break;

      case 6001:
        Diagnostic_process();
        current_state = 6000;
        break;

          
    }

  }

  old_state = state ;

  
}


void state_list_index_update() {  
  for(int i; i<sizeof(state_list); i=i+1) {
    if ( current_state == state_list[i][0]) {
      state_list_index = i;
      break;
    }
  }
}

void dashboard_update() {

  if (state_list_index >= 0) {
    if ( enter_BN.pressed)  {
      Serial.println("Enter pressed");
      if ( state_list[state_list_index][1] != 0 && state_list[state_list_index][1] != 9999) {
        current_state = state_list[state_list_index][1];
        state_list_index_update();
      }
      
      enter_BN.pressed = false;
      back_BN.pressed = false;
      up_BN.pressed = false;
      down_BN.pressed = false;
    }
    else if (back_BN.pressed)  {
      Serial.println("Back pressed");
      if ( state_list[state_list_index][2] != 0 && state_list[state_list_index][2] != 9999) {
        current_state = state_list[state_list_index][2];
        state_list_index_update();
      }

      enter_BN.pressed = false;
      back_BN.pressed = false;
      up_BN.pressed = false;
      down_BN.pressed = false;
    }
    else if ( up_BN.pressed)  {
      Serial.println("Up pressed");
      if ( state_list[state_list_index][3] == 8) {
        if ( display_value >=5) {
          display_value = display_value + 5;
        }
      }
      else if ( state_list[state_list_index][3] != 0 && state_list[state_list_index][3] != 9999) {
        current_state = state_list[state_list_index][3];
        state_list_index_update();
      }
      
      enter_BN.pressed = false;
      back_BN.pressed = false;
      up_BN.pressed = false;
      down_BN.pressed = false;
    }
    else if ( down_BN.pressed)  {
      Serial.println("Down pressed");
      if ( state_list[state_list_index][4] == 2) {
        if (display_value >=10) {
          display_value = display_value - 5;
        }
      }
      else if ( state_list[state_list_index][4] != 0 && state_list[state_list_index][4] != 9999) {
        current_state = state_list[state_list_index][4];
        state_list_index_update();
      }
      
      enter_BN.pressed = false;
      back_BN.pressed = false;
      up_BN.pressed = false;
      down_BN.pressed = false;
    }
    
  }

  dashboard( current_state);
  state_list_index_update();
  
}
