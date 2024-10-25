
// list - current state, enter state, back state, up state, down state  
// 9999 - update comming soon
// 0 - invalid

int state_list[][5] = {
  {1000, 9999,    0,    0, 2000},
  {2000, 9999,    0, 1000, 3000},
  {3000, 9999,    0, 2000, 4000},


  // 4000 -----------------------
  {4000, 4010,    0, 3000, 5000},

  {4010, 4110, 4000,    0, 4020},

  {4110, 4111, 4010,    0, 4120},
  {4111, 4901, 4110,    2,    8},
  {4120, 4121, 4010, 4110, 4130},
  {4121, 4901, 4120,    2,    8},
  {4130, 4131, 4010, 4120, 4140},
  {4131, 4901, 4130,    2,    8},
  {4140, 4141, 4010, 4130,    0},
  {4141, 4901, 4140,    2,    8},

  {4020, 4210, 4000, 4010,    0},

  {4210, 4211, 4020,    0, 4220},
  {4211, 4901, 4210,    2,    8},
  {4220, 4221, 4020, 4210, 4230},
  {4221, 4901, 4220,    2,    8},
  {4230, 4231, 4020, 4220, 4240},
  {4231, 4901, 4230,    2,    8},
  {4240, 4241, 4020, 4230,    0},
  {4241, 4901, 4240,    2,    8},

  
  // 5000 -----------------------
  {5000, 5001,    0, 4000,    0},

  {5001, 5010, 5000,    0, 5002},

  {5010, 5015, 5001,    0, 5020},
  {5015,    0, 5010,    0,    0},
  {5020, 5025, 5001, 5010, 5030},
  {5025,    0, 5020,    0,    0},
  {5030, 5035, 5001, 5020,    0},
  {5035,    0, 5030,    2,    8},


  {5002, 5040, 5000, 5001, 5003},

  {5040, 5045, 5002,    0, 5050},
  {5045,    0, 5040,    0,    0},
  {5050, 5055, 5002, 5040, 5060},
  {5055,    0, 5050,    0,    0},
  {5060, 5065, 5002, 5050, 5070},
  {5065,    0, 5060,    0,    0},
  {5070, 5075, 5002, 5060, 5080},
  {5075,    0, 5070,    0,    0},
  {5080, 5085, 5002, 5070, 5090},
  {5085,    0, 5080,    0,    0},
  {5090, 5095, 5002, 5080, 5100},
  {5095,    0, 5090,    0,    0},
  {5100, 5105, 5002, 5090, 5110},
  {5105,    0, 5100,    0,    0},
  {5110, 5115, 5002, 5100, 5120},
  {5115,    0, 5110,    0,    0},
  {5120, 5125, 5002, 5110, 5130},
  {5125,    0, 5120,    0,    0},
  {5130, 5135, 5002, 5120, 5140},
  {5135,    0, 5130,    0,    0},
  {5140, 5145, 5002, 5130, 5150},
  {5145,    0, 5140,    0,    0},
  {5150, 5155, 5002, 5140, 5160},
  {5155,    0, 5150,    0,    0},
  {5160, 5165, 5002, 5150, 5170},
  {5165,    0, 5160,    0,    0},
  {5170, 5175, 5002, 5160, 5180},
  {5175,    0, 5170,    0,    0},
  {5180, 5185, 5002, 5170, 5190},
  {5185,    0, 5180,    0,    0},
  {5190, 5195, 5002, 5180, 5200},
  {5195,    0, 5190,    0,    0},
  {5200, 5205, 5002, 5190, 5210},
  {5205,    0, 5200,    0,    0},
  {5210, 5215, 5002, 5200, 5220},
  {5215,    0, 5210,    0,    0},
  {5220, 5225, 5002, 5210, 5230},
  {5225,    0, 5220,    0,    0},
  {5230, 5235, 5002, 5220, 5240},
  {5235,    0, 5230,    0,    0},
  {5240, 5245, 5002, 5230, 5250},
  {5245,    0, 5240,    0,    0},
  {5250, 5255, 5002, 5240,    0},
  {5255,    0, 5250,    0,    0},


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
  {5375,    0, 5370,    0,    0}
  
};

int state_list_index = -1;
int current_state = 1000;
int display_value = 1000;
int old_state = current_state;


void dashboard(int state){
  int number = 1000;

  if ( state == old_state) {
    
  }
  else {
    switch (state) {
      case 1000:  
          dash_1000.display_(0);
          break;
          

  // Clean process -------------------------
      case 2000:  
          dash_2000.display_(0);
          break;

      case 2010:  
          dash_2010.display_(0);
          break;

      case 2020:  
          dash_2020.display_(0);
          break;

      case 2030:  
          dash_2030.display_(0);
          break;


  // Milk process ---------------------------
      case 3000:  
          dash_3000.display_(0);
          break;


  // Settings ----------------------------------
      case 4000:  
          dash_4000.display_(0);
          break;
  // Temp setting    
      case 4010:
          dash_4010.display_(0);
          break;
      
      case 4110:
          dash_4110.display_(0);
          break;

      case 4111:
          number = display_value;
          dash_4111.display_(number);
          break;

      case 4120:
          dash_4120.display_(0);
          break;

      case 4121:
          number = display_value;
          dash_4121.display_(number);
          break;

      case 4130:
          dash_4130.display_(0);
          break;

      case 4131:
          number = display_value;
          dash_4131.display_(number);
          break;

      case 4140:
          dash_4140.display_(0);
          break;

      case 4141:
          number = display_value;
          dash_4141.display_(number);
          break;
  // Time setting    
      case 4020:
          dash_4020.display_(0);
          break;

      case 4210:
          dash_4210.display_(0);
          break;

      case 4211:
          number = display_value;
          dash_4211.display_(number);
          break;

      case 4220:
          dash_4220.display_(0);
          break;

      case 4221:
          number = display_value;
          dash_4221.display_(number);
          break;

      case 4230:
          dash_4230.display_(0);
          break;

      case 4231:
          number = display_value;
          dash_4231.display_(number);
          break;

      case 4240:
          dash_4240.display_(0);
          break;

      case 4241:
          number = display_value;
          dash_4241.display_(number);
          break;


  // Testing -----------------------------------        
      case 5000:  
          dash_5000.display_(0);
          break;

      case 5001:  
          dash_5001.display_(0);
          break;

      case 5002:  
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
      case 5040:  
          dash_5040.display_(0);
          break;
      case 5045:  
          dash_5045.display_(0);
          valve_A1.open(true);
          current_state = 5040;
          enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
          break;
          
      case 5050:  
          dash_5050.display_(0);
          break;
      case 5055:  
          dash_5055.display_(0);
          valve_A1.open(false);
          current_state = 5050;
          enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
          break;
          
      case 5060:  
          dash_5060.display_(0);
          break;
      case 5065:  
          dash_5065.display_(0);
          valve_A2.open(true);
          current_state = 5060;
          enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
          break;
          
      case 5070:  
          dash_5070.display_(0);
          break;
      case 5075:  
          dash_5075.display_(0);
          valve_A2.open(false);
          current_state = 5070;
          enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
          break;
          
      case 5080:  
          dash_5080.display_(0);
          break;
      case 5085:  
          dash_5085.display_(0);
          valve_A3.open(true);
          current_state = 5080;
          enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
          break;
          
      case 5090:  
          dash_5090.display_(0);
          break;
      case 5095:  
          dash_5095.display_(0);
          valve_A3.open(false);
          current_state = 5090;
          enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
          break;
          
      case 5100:  
          dash_5100.display_(0);
          break;
      case 5105:  
          dash_5105.display_(0);
          valve_A4.open(true);
          current_state = 5100;
          enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
          break;
          
      case 5110:  
          dash_5110.display_(0);
          break;
      case 5115:  
          dash_5115.display_(0);
          valve_A4.open(false);
          current_state = 5110;
          enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
          break;
          
      case 5120:  
          dash_5120.display_(0);
          break;
      case 5125:  
          dash_5125.display_(0);
          valve_A5.open(true);
          current_state = 5120;
          enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
          break;
          
      case 5130:  
          dash_5130.display_(0);
          break;
      case 5135:  
          dash_5135.display_(0);
          valve_A5.open(false);
          current_state = 5130;
          enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
          break;

      case 5140:  
          dash_5140.display_(0);
          break;
      case 5145:  
          dash_5145.display_(0);
          valve_A6.open(true);
          current_state = 5140;
          enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
          break;
          
      case 5150:  
          dash_5150.display_(0);
          break;
      case 5155:  
          dash_5155.display_(0);
          valve_A6.open(false);
          current_state = 5150;
          enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
          break;

      case 5160:  
          dash_5160.display_(0);
          break;
      case 5165:  
          dash_5165.display_(0);
          valve_B1.open(true);
          current_state = 5160;
          enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
          break;
          
      case 5170:  
          dash_5170.display_(0);
          break;
      case 5175:  
          dash_5175.display_(0);
          valve_B1.open(false);
          current_state = 5170;
          enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
          break;

      case 5180:  
          dash_5180.display_(0);
          break;
      case 5185:  
          dash_5185.display_(0);
          valve_B2.open(true);
          current_state = 5180;
          enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
          break;
          
      case 5190:  
          dash_5190.display_(0);
          break;
      case 5195:  
          dash_5195.display_(0);
          valve_B2.open(false);
          current_state = 5190;
          enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
          break;

      case 5200:  
          dash_5200.display_(0);
          break;
      case 5205:  
          dash_5205.display_(0);
          valve_B3.open(true);
          current_state = 5200;
          enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
          break;
          
      case 5210:  
          dash_5210.display_(0);
          break;
      case 5215:  
          dash_5215.display_(0);
          valve_B3.open(false);
          current_state = 5210;
          enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
          break;

      case 5220:  
          dash_5220.display_(0);
          break;
      case 5225:  
          dash_5225.display_(0);
          valve_B4.open(true);
          current_state = 5220;
          enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
          break;
          
      case 5230:  
          dash_5230.display_(0);
          break;
      case 5235:  
          dash_5235.display_(0);
          valve_B4.open(false);
          current_state = 5230;
          enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
          break;

      case 5240:  
          dash_5240.display_(0);
          break;
      case 5245:  
          dash_5245.display_(0);
          valve_B5.open(true);
          current_state = 5240;
          enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
          break;

      case 5250:  
          dash_5250.display_(0);
          break;
      case 5255:  
          dash_5255.display_(0);
          valve_B5.open(false);
          current_state = 5250;
          enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
          break;
  // pump tesing -------------     
      case 5320:  
          dash_5320.display_(0);
          break;
      case 5325:  
          dash_5325.display_(0);
          pump1.Trigger(true);
          delay(1000);
          current_state = 5320;
          enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
          break;
          
      case 5330:  
          dash_5330.display_(0);
          break;
      case 5335:  
          dash_5335.display_(0);
          pump1.Trigger(false);
          delay(1000);
          current_state = 5330;
          enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
          break;
          
      case 5340:  
          dash_5340.display_(0);
          break;
      case 5345:  
          dash_5345.display_(0);
          pump2.Trigger(true);
          delay(1000);
          current_state = 5340;
          enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
          break;
          
      case 5350:  
          dash_5350.display_(0);
          break;
      case 5355:  
          dash_5355.display_(0);
          pump2.Trigger(false);
          delay(1000);
          current_state = 5350;
          enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
          break;
          
      case 5360:  
          dash_5360.display_(0);
          break;
      case 5365:  
          dash_5365.display_(0);
          pump3.Trigger(true);
          delay(1000);
          current_state = 5360;
          enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
          break;
          
      case 5370:  
          dash_5370.display_(0);
          break;
      case 5375:  
          dash_5375.display_(0);
          pump3.Trigger(false);
          delay(1000);
          current_state = 5370;
          enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
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
        if (display_value >=5) {
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
