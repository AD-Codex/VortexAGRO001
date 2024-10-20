int process_state = 0;

int water_loop_time = 20;
int max_water_temp = 90;
int max_milk_temp = 90;
int max_temp = 90;

void boiler_check() {
  while (1) {
    if ( Boil_Temp() > max_temp) {
      printD("Boiler at 90c");
      break;
    }
    else {
      printD("Boiler at lower 90c");
    }
    delay(1000);
  }
}

void tank_clear() {
  int time_count = 0;
  bool tank_clear = false;
  int start_time = millis();
  
  while (1){    
    if ( Boil_Temp() > max_water_temp) {
      tank_clear = true;
      if ( time_count >= water_loop_time ) {
        printD("Tank cleaning done");
        break;
      }
      else {
        if ( millis() - start_time >= 60000 ) {
          start_time = millis();
          time_count = time_count + 1;
          printD("Time counting");
        }
      }
    }
    else {
      printD("Warning Boiler at lower 90c");
      tank_clear = false;
      pump(2, false);
      solenoid(2, false);
      pump(1, false);
      solenoid(1, false);
    }

    if (tank_clear) {
      if ( Tank1_Temp() < max_water_temp) {
        pump(2, false);
        solenoid(2, false);    
        solenoid(1, true);
        pump(1, true);
      }
      else if (Tank1_Temp() < 100) {
        pump(2, false);
        solenoid(2, false);  
        pump(1, false);
        solenoid(1, false);
      }
      else if ( Tank1_Temp() >= 100) {
        pump(1, false);
        solenoid(1, false);
        solenoid(2,true);
        pump(2, true);
      }
    }
    delay(500); 
  }

  pump(2, false);
  solenoid(2, false);
  pump(1, false);
  solenoid(1, false);
}


void milk_process_1() {
  int time_count = 0;
  int start_time = millis();
  
  while (1) {
    if ( Boil_Temp() > max_water_temp) {
      
    }
    else {
      printD("Warning Boiler at lower 90c");
    }

    if ( millis() - start_time >= 60000) {
      start_time = millis();
      time_count = time_count + 1;
    }

    if( time_count >= 45) {
      break;
    }

    if ( Tank1_Temp() < max_milk_temp) {
      pump(2, false);
      solenoid(2, false);    
      solenoid(1, true);
      pump(1, true);
    }
    else if (Tank1_Temp() < 95) {
      pump(2, false);
      solenoid(2, false);  
      pump(1, false);
      solenoid(1, false);
    }
    else if ( Tank1_Temp() >= 95) {
      pump(1, false);
      solenoid(1, false);
      solenoid(2,true);
      pump(2, true);
    }
    delay(1000);
  }
  pump(2, false);
  solenoid(2, false);  
  pump(1, false);
  solenoid(1, false);
}

void milk_process_2() {
  int time_count = 0;
  int start_time = millis();
  
  while (1) {
    if ( Boil_Temp() > max_water_temp) {
      
    }
    else {
      printD("Warning Boiler at lower 90c");
    }

    if ( millis() - start_time >= 60000) {
      start_time = millis();
      time_count = time_count + 1;
    }

    if( time_count >= 20) {
      break;
    }

    if ( Tank1_Temp() < 60) {
      pump(2, false);
      solenoid(2, false);    
      solenoid(1, true);
      pump(1, true);
    }
    else if (Tank1_Temp() < 65) {
      pump(2, false);
      solenoid(2, false);  
      pump(1, false);
      solenoid(1, false);
    }
    else if ( Tank1_Temp() >= 65) {
      pump(1, false);
      solenoid(1, false);
      solenoid(2,true);
      pump(2, true);
    } 
    delay(1000);
  }

  pump(2, false);
  solenoid(2, false);  
  pump(1, false);
  solenoid(1, false);
}


void process_1() {
  boiler_check();
  tank_clear();
  delay(1000);

  printD("Water draing");
  solenoid(4, true);
    
}


void process_2() {
  boiler_check();
  milk_process_1();
  milk_process_2();
  delay(1000);

  printD("Milk draing");
  solenoid(5, true);
}
