// using ADC1, ADC2 may used for wifi setups

#define TMP_BOIL_PIN 34
#define TMP_MILK1_PIN 35
//#define TMP_BOIL_PIN 32
//#define TMP_MILK1_PIN 33


struct TSensor {
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
TSensor TSensor1 = { TMP_BOIL_PIN};
TSensor TSensor2 = { TMP_MILK1_PIN};


// init sensors ----------------------------------------------------------
void init_TSensor() {
  TSensor1.init();
  TSensor2.init();
}
