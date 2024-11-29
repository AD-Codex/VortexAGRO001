// boiler pump - pump1
// cooler pump - pump2
// tank pump   - pump3

#define BOIL_PMP_RELAY_PIN 19
#define COOL_PMP_RELAY_PIN 18
#define TANK_MIXER_REAY_PIN 5
#define HOMOGENIZER_ON_PIN 4
#define HOMOGENIZER_OFF_PIN 2


// Relay object deffine ----------------------------------------------
struct Relay {
  const uint8_t PIN;
  bool state;
  String name;

  void init() {
    pinMode(PIN, OUTPUT);
    digitalWrite(PIN, LOW);
  }
  
  void Trigger( bool open) {
    if ( open != state ) {
      digitalWrite( PIN, open);
      state = open;
    }
    Serial.print(name );
    Serial.print(" state : ");
    Serial.println(open);
  }

  void Click() {
    digitalWrite( PIN, LOW);
    delay(1000);
    digitalWrite( PIN, HIGH);
    Serial.print(name );
    Serial.println(" Clicked");

  }
  
};


// define relays -----------------------------------------------------------
Relay boilPump = {BOIL_PMP_RELAY_PIN, false, "boilPump"};
Relay coolPump = {COOL_PMP_RELAY_PIN, false, "coolPump"};
Relay mixer = {TANK_MIXER_REAY_PIN, false, "mixer"};
Relay homogenizerOn = {HOMOGENIZER_ON_PIN, false, "homogenizerOn"};
Relay homogenizerOff = {HOMOGENIZER_OFF_PIN, false, "homogenizerOff"};


// init relay pins ---------------------------------------------------------
void init_Relay() {
  boilPump.init();
  coolPump.init();
  mixer.init();
  homogenizerOn.init();
  homogenizerOff.init();

  boilPump.Trigger(false);
  coolPump.Trigger(false);
  mixer.Trigger(false);
  homogenizerOn.Trigger(true);
  homogenizerOff.Trigger(true);
  
  
}
