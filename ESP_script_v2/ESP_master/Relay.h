

#define BOIL_PMP_RELAY_PIN 19
#define COOL_PMP_RELAY_PIN 18
#define TANK_PMP_RELAY_PIN 5



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
Relay pump1 = {BOIL_PMP_RELAY_PIN, false};
Relay pump2 = {COOL_PMP_RELAY_PIN, false};
Relay pump3 = {TANK_PMP_RELAY_PIN, false};


// init relay pins ---------------------------------------------------------
void init_Relay() {
  pump1.init();
  pump2.init();
  pump3.init();

  pump1.Trigger(false);
  pump2.Trigger(false);
  pump3.Trigger(false);
  
  
}
