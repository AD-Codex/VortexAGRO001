

#define BOIL_PMP_RELAY_PIN 19
#define COOL_PMP_RELAY_PIN 5
#define TANK_PMP_RELAY_PIN 16
#define BOIL_SOLE_RELAY_PIN 18
#define COOL_SOLE_RELAY_PIN 17
#define TANK_SOLE_RELAY_PIN 4
#define WATER_OUT_RELAY_PIN 2 
#define MILK_OUT_RELAY_PIN 15



struct Relay {
  const uint8_t PIN;
  bool state;

  void init() {
    pinMode(PIN, OUTPUT);
    digitalWrite(PIN, LOW);
  }
  
  void Trigger( bool open) {
    if ( open != state ) {
      digitalWrite( PIN, open);
      state = open;
    }
    Serial.print(PIN );
    Serial.print(" relay state : ");
    Serial.println(open);
  }
  
};


// define relays -----------------------------------------------------------
Relay boiler_pump = {BOIL_PMP_RELAY_PIN, false};
Relay cooler_pump = {COOL_PMP_RELAY_PIN, false};
Relay tank_pump = {TANK_PMP_RELAY_PIN, false};
Relay boiler_solenide = {BOIL_SOLE_RELAY_PIN, false};
Relay cooler_solenide = {COOL_SOLE_RELAY_PIN, false};
Relay tank_solenide = {TANK_SOLE_RELAY_PIN, false};
Relay Wout_solenide = {WATER_OUT_RELAY_PIN, false};
Relay Mout_solenide = {MILK_OUT_RELAY_PIN, false};


// init relay pins ---------------------------------------------------------
void init_Relay() {
  boiler_pump.init();
  cooler_pump.init();
  tank_pump.init();
  
  boiler_solenide.init();
  cooler_solenide.init();
  tank_solenide.init();
  Wout_solenide.init();
  Mout_solenide.init();

  boiler_pump.Trigger(false);
  cooler_pump.Trigger(false);
  tank_pump.Trigger(false);
  
  boiler_solenide.Trigger(false);
  cooler_solenide.Trigger(false);
  tank_solenide.Trigger(false);
  Wout_solenide.Trigger(false);
  Mout_solenide.Trigger(false);
  
}
