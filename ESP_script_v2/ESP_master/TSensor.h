
// using ADC1, ADC2 may used for wifi setups
// boiler temperature - TSensor1
// milk temperature   - Tsensor2

#define TMP_BOIL_PIN 35
#define TMP_MILK1_PIN 34
//#define TMP_BOIL_PIN 32
//#define TMP_MILK1_PIN 33
#define BUZZ_PIN 33


struct Sensor {
  const uint8_t PIN;
  
  void init() {
    pinMode( PIN, INPUT);
  }
  
  float Read() {
//    return analogRead( PIN) * 100/4095;
    return 65;
  }
  
};


// define sensors --------------------------------------------------------
Sensor TSensor1 = { TMP_BOIL_PIN};
Sensor TSensor2 = { TMP_MILK1_PIN};


// init sensors ----------------------------------------------------------
void init_TSensor() {
  TSensor1.init();
  TSensor2.init();
}

void init_Buzzer() {
  pinMode( BUZZ_PIN, OUTPUT);
  digitalWrite( BUZZ_PIN, LOW);
}

void buzzerBeep( int num) {
  for (int beep = 0; beep<num; beep++){
    digitalWrite( BUZZ_PIN, HIGH);
    delay(200);
    digitalWrite( BUZZ_PIN, LOW);
    delay(200);
  }
  
}

void buzzerHigh( bool state) {
  if ( state) {
    digitalWrite( BUZZ_PIN, HIGH);
  }
  else {
    digitalWrite( BUZZ_PIN, LOW);
  }
  
}
