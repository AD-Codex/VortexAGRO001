
// list - current state, enter state, back state, up state, down state  
// 9999 - update comming soon
// 0 - invalid

int state_list[][5] = {
  {1000, 9999,    0,    0, 2000},
  {2000, 9999,    0, 1000, 3000},
  {3000, 9999,    0, 2000, 4000},
  {4000, 9999,    0, 3000, 5000},
  {5000, 5010, 5010, 4000,    0},
  {5010, 5015, 5000,    0, 5020},
  {5015,    0, 5010,    0,    0},
  {5020, 5025, 5000, 5010, 5030},
  {5025,    0, 5020,    0,    0},
  {5030, 5035, 5000, 5020, 5040},
  {5035,    0, 5030,    8,    2},
  {5040, 5045, 5000, 5030, 5050},
  {5045,    0, 5040,    0,    0},
  {5050, 5055, 5000, 5040, 5060},
  {5055,    0, 5050,    0,    0},
  {5060, 5065, 5000, 5050, 5070},
  {5065,    0, 5060,    0,    0},
  {5070, 5075, 5000, 5060, 5080},
  {5075,    0, 5070,    0,    0},
  {5080, 5085, 5000, 5070, 5090},
  {5085,    0, 5080,    0,    0},
  {5090, 5095, 5000, 5080, 5100},
  {5095,    0, 5090,    0,    0},
  {5100, 5105, 5000, 5090, 5110},
  {5105,    0, 5100,    0,    0},
  {5110, 5115, 5000, 5100, 5120},
  {5115,    0, 5110,    0,    0},
  {5120, 5125, 5000, 5110, 5130},
  {5125,    0, 5120,    0,    0},
  {5130, 5135, 5000, 5120, 5140},
  {5135,    0, 5130,    0,    0},
  {5140, 5145, 5000, 5130, 5150},
  {5145,    0, 5140,    0,    0},
  {5150, 5155, 5000, 5140, 5160},
  {5155,    0, 5150,    0,    0},
  {5160, 5165, 5000, 5150, 5170},
  {5165,    0, 5160,    0,    0},
  {5170, 5175, 5000, 5160, 5180},
  {5175,    0, 5170,    0,    0},
  {5180, 5185, 5000, 5170, 5190},
  {5185,    0, 5180,    0,    0},
  {5190, 5195, 5000, 5180, 9999},
  {5195,    0, 5190,    0,    0}
  
};

int state_list_index = -1;
int current_state = 1000;
int display_value = 1000;


void dashboard(int state){
  int number = 1000;

  switch (state) {
    case 1000:  
        dash_1000.display_(0);
        break;
        
    case 2000:  
        dash_2000.display_(0);
        break;
        
    case 3000:  
        dash_3000.display_(0);
        break;
        
    case 4000:  
        dash_4000.display_(0);
        break;
        
    case 5000:  
        dash_5000.display_(0);
        break;
        
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
        
    case 5040:  
        dash_5040.display_(0);
        break;
    case 5045:  
        dash_5045.display_(0);
        valve1.open(true);
        current_state = 5040;
        enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
        break;
        
    case 5050:  
        dash_5050.display_(0);
        break;
    case 5055:  
        dash_5055.display_(0);
        valve1.open(false);
        current_state = 5050;
        enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
        break;
        
    case 5060:  
        dash_5060.display_(0);
        break;
    case 5065:  
        dash_5065.display_(0);
        valve2.open(true);
        current_state = 5060;
        enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
        break;
        
    case 5070:  
        dash_5070.display_(0);
        break;
    case 5075:  
        dash_5075.display_(0);
        valve2.open(false);
        current_state = 5070;
        enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
        break;
        
    case 5080:  
        dash_5080.display_(0);
        break;
    case 5085:  
        dash_5085.display_(0);
        valve3.open(true);
        current_state = 5080;
        enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
        break;
        
    case 5090:  
        dash_5090.display_(0);
        break;
    case 5095:  
        dash_5095.display_(0);
        valve3.open(false);
        current_state = 5090;
        enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
        break;
        
    case 5100:  
        dash_5100.display_(0);
        break;
    case 5105:  
        dash_5105.display_(0);
        valve4.open(true);
        current_state = 5100;
        enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
        break;
        
    case 5110:  
        dash_5110.display_(0);
        break;
    case 5115:  
        dash_5115.display_(0);
        valve4.open(false);
        current_state = 5110;
        enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
        break;
        
    case 5120:  
        dash_5120.display_(0);
        break;
    case 5125:  
        dash_5125.display_(0);
        valve4.open(true);
        current_state = 5120;
        enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
        break;
        
    case 5130:  
        dash_5130.display_(0);
        break;
    case 5135:  
        dash_5135.display_(0);
        valve1.open(false);
        current_state = 5130;
        enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
        break;
        
    case 5140:  
        dash_5140.display_(0);
        break;
    case 5145:  
        dash_5145.display_(0);
        pump1.Trigger(true);
        delay(1000);
        current_state = 5140;
        enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
        break;
        
    case 5150:  
        dash_5150.display_(0);
        break;
    case 5155:  
        dash_5155.display_(0);
        pump1.Trigger(false);
        delay(1000);
        current_state = 5150;
        enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
        break;
        
    case 5160:  
        dash_5160.display_(0);
        break;
    case 5165:  
        dash_5165.display_(0);
        pump2.Trigger(true);
        delay(1000);
        current_state = 5160;
        enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
        break;
        
    case 5170:  
        dash_5170.display_(0);
        break;
    case 5175:  
        dash_5175.display_(0);
        pump2.Trigger(false);
        delay(1000);
        current_state = 5170;
        enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
        break;
        
    case 5180:  
        dash_5180.display_(0);
        break;
    case 5185:  
        dash_5185.display_(0);
        pump3.Trigger(true);
        delay(1000);
        current_state = 5180;
        enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
        break;
        
    case 5190:  
        dash_5190.display_(0);
        break;
    case 5195:  
        dash_5195.display_(0);
        pump3.Trigger(false);
        delay(1000);
        current_state = 5190;
        enter_BN.pressed = false; back_BN.pressed = false; up_BN.pressed = false; down_BN.pressed = false;
        break;

        
  }

  
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
