// using ADC1, ADC2 may used for wifi setups

#define TMP_BOIL_PIN 34
#define TMP_MILK1_PIN 35


struct TSensor {
  const uint8_t PIN;
  
  void init() {
    pinMode( PIN, INPUT);
  }
  
  float Read() {
    return analogRead( PIN) * 100/4095;
  }
  
};


// define sensors --------------------------------------------------------
TSensor boilder_TSensor = { TMP_BOIL_PIN};
TSensor tank1_TSensor = { TMP_MILK1_PIN};


// init sensors ----------------------------------------------------------
void init_TSensor() {
  boilder_TSensor.init();
  tank1_TSensor.init();
}
