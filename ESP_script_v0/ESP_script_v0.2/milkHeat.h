

int boilder_rated_temp_2 = 90;
int milk_heat_time = 20;   // 20s
int min_milk_temp = 90;
int milk_keep_temp = 95;


void milk_heat_process() {
  bool milk_heat_process = true;
  int time_count = 0;
  int start_time = 0;

  System_init();

  start_time = millis();

  while (1) {
    // -----------------process------
    // read the boiler temp. if it > ratedT and time is available milk_heat_process set to true.
    // if boilerT < T process stop and display boiler not at T
    if ( boilder_TSensor.Read() > boilder_rated_temp_2 ) {
      if( time_count >= (milk_heat_time / 5) ) {
        screenD("milk heating done");

        milk_heat_process = false;
        break;
      }
      else {
        milk_heat_process = true;
      }
    }
    else {
      screenD("Boiler at below 90c");

      milk_heat_process = false;
      boiler_pump.Trigger(false);
      boiler_solenide.Trigger(false);
      cooler_pump.Trigger(false);
      cooler_solenide.Trigger(false);
    }

    // milk heating ---------------------------------------
    if ( milk_heat_process ) {
      start_time = millis();
      if ( tank1_TSensor.Read() < min_milk_temp ) {
        screenD("tank1 temp below max milk temp");
        
        boiler_solenide.Trigger(true);
        boiler_pump.Trigger(true);
        cooler_solenide.Trigger(false);
        cooler_pump.Trigger(false);
        start_time = millis();
      }
      else {
        // water temp controller ---------------------------------------
        if ( tank1_TSensor.Read() < milk_keep_temp ) {
          screenD("tank1 temp below milk_keep_temp");
          
          boiler_solenide.Trigger(false);
          boiler_pump.Trigger(false);
          cooler_solenide.Trigger(false);
          cooler_pump.Trigger(false);
        }
        else {
          screenD("tank1 temp upper than milk_keep_temp");
          
          cooler_solenide.Trigger(true);
          cooler_pump.Trigger(true);
          boiler_pump.Trigger(false);
          boiler_solenide.Trigger(false);
        }
        // condition for time count ---------------------------------
        // at every 5s consider as one count
        // only count when milk_heat_process true and water T at consider level range
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
      screenD("milk_heat_process false");
    }
  }

  milk_heat_process = false;
  System_init();

}
