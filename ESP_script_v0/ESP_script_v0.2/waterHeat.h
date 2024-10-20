


int boilder_rated_temp = 90;
int water_heat_time = 20;   // 20s
int min_water_temp = 90;    // tank clean process minimum water temp
int water_keep_temp = 95;   // tank clean process water temp stady level


void water_heat_process() {
  bool water_heat_process = false;
  int time_count = 0;
  int start_time = 0;

  System_init();

  start_time = millis();
  
  while (1) {
    // checking the water heating conditions ----------------------
    // -----------------process------
    // read the boiler temp. if it > ratedT and time is available water_heat_process set to true.
    // if boilerT < T process stop and display boiler not at T
    if ( boilder_TSensor.Read() > boilder_rated_temp ) {
      if( time_count >= (water_heat_time / 5) ) {
        screenD("tank cleaning done");
        water_heat_process = false;
        break;
      }
      else {
        water_heat_process = true;
      }
    }
    else {
      screenD("Boiler at below 90c");
      water_heat_process = false;
      boiler_pump.Trigger(false);
      boiler_solenide.Trigger(false);
      cooler_pump.Trigger(false);
      cooler_solenide.Trigger(false);
    }
    
    // water heating ---------------------------------------
    if ( water_heat_process ) {
      start_time = millis();
      if ( tank1_TSensor.Read() < min_water_temp ) {
        // if tank1 temp below max water temp
        // heat the water to considerable level. reset count start time. if water temp at below min_water_temp counter not start
        screenD("tank1 temp below max water temp");
        
        boiler_solenide.Trigger(true);
        boiler_pump.Trigger(true);
        cooler_solenide.Trigger(false);
        cooler_pump.Trigger(false);
        start_time = millis();
      }
      else {
        // water temp controller ---------------------------------------
        if ( tank1_TSensor.Read() < water_keep_temp ) {
          // if tank1 temp below water_keep_temp
          screenD("tank1 temp below water_keep_temp");
          
          boiler_solenide.Trigger(false);
          boiler_pump.Trigger(false);
          cooler_solenide.Trigger(false);
          cooler_pump.Trigger(false);
        }
        else {
          // if tank1 temp upper than water_keep_temp
          screenD("tank1 temp upper than water_keep_temp");
          
          cooler_solenide.Trigger(true);
          cooler_pump.Trigger(true);
          boiler_pump.Trigger(false);
          boiler_solenide.Trigger(false);
        }
        // condition for time count ---------------------------------
        // at every 5s consider as one count
        // only count when water_heat_process true and water T at consider level range
        if ( millis() - start_time >= 5000 ) {
          time_count = time_count + 1;
          screenD("Time counting");
          start_time = millis();
        }
        else {
          time_count = time_count ;
        }
        
      }
    }
    else {
      screenD("water_heat_process false");
    }
  }
  water_heat_process = false;
  System_init();

}
