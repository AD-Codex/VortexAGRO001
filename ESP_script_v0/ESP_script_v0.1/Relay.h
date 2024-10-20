
#define BOIL_PMP_RELAY_PIN 19
#define BOIL_SOLE_RELAY_PIN 18
#define COOL_PMP_RELAY_PIN 5
#define COOL_SOLE_RELAY_PIN 17
#define TANK_PMP_RELAY_PIN 16
#define TANK_SOLE_RELAY_PIN 4
#define WATER_OUT_RELAY_PIN 2 
#define MILK_OUT_RELAY_PIN 15

void init_relay() {
  pinMode(BOIL_PMP_RELAY_PIN, OUTPUT);
  pinMode(BOIL_SOLE_RELAY_PIN, OUTPUT);
  pinMode(COOL_PMP_RELAY_PIN, OUTPUT);
  pinMode(COOL_SOLE_RELAY_PIN, OUTPUT);
  pinMode(TANK_PMP_RELAY_PIN, OUTPUT);
  pinMode(TANK_SOLE_RELAY_PIN, OUTPUT);
  pinMode(WATER_OUT_RELAY_PIN, OUTPUT);
  pinMode(MILK_OUT_RELAY_PIN, OUTPUT);

  digitalWrite(BOIL_PMP_RELAY_PIN, LOW);
  digitalWrite(BOIL_SOLE_RELAY_PIN, LOW);
  digitalWrite(COOL_PMP_RELAY_PIN, LOW);
  digitalWrite(COOL_SOLE_RELAY_PIN, LOW);
  digitalWrite(TANK_PMP_RELAY_PIN, LOW);
  digitalWrite(TANK_SOLE_RELAY_PIN, LOW);
  digitalWrite(WATER_OUT_RELAY_PIN, LOW);
  digitalWrite(MILK_OUT_RELAY_PIN, LOW);
  
}

void solenoid(int num, bool state) {
  if ( num == 1) {
    digitalWrite(BOIL_SOLE_RELAY_PIN, state);
  }
  else if ( num == 2) {
    digitalWrite(COOL_SOLE_RELAY_PIN, state);
  }
  else if ( num == 3) {
    digitalWrite(TANK_SOLE_RELAY_PIN, state);
  }
  else if ( num == 4) {
    digitalWrite(WATER_OUT_RELAY_PIN, state);
  }
  else if ( num == 5) {
    digitalWrite(MILK_OUT_RELAY_PIN, state);
  }
  
}

void pump(int num, bool state) {

  delay(1000);
  
  if ( num == 1) {
    digitalWrite(BOIL_PMP_RELAY_PIN, state);
  }
  else if ( num == 2) {
    digitalWrite(COOL_PMP_RELAY_PIN, state);
  }
  else if ( num == 3) {
    digitalWrite(TANK_PMP_RELAY_PIN, state);
  }
}
