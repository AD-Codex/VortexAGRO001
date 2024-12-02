
// using ADC1, ADC2 may used for wifi setups
// boiler temperature - TSensor1
// milk temperature   - Tsensor2

// #define TMP_BOIL_PIN 33
#define TMP_MILK1_PIN 32
//#define TMP_BOIL_PIN 32
//#define TMP_MILK1_PIN 33


#include <OneWire.h>
#include <DallasTemperature.h>

// #define TMP_BOIL_PIN 33
//#define 34
//#define 33
#define TMP_MILK1_PIN 32

OneWire oneWire( TMP_MILK1_PIN);
DallasTemperature sensors( &oneWire);


struct Sensor {
  const uint8_t PIN;
  
  void init() {
    pinMode( PIN, INPUT);
  }
  
  float Read() {
    sensors.requestTemperatures();
    int temp = sensors.getTempCByIndex(0);

    if ( temp < 0) {
      sensors.begin();
      sensors.requestTemperatures();
      temp = sensors.getTempCByIndex(0);
    }

    Serial.print(" Temperature: ");
    Serial.println( temp);

    return temp;
  }
  
};


// define sensors --------------------------------------------------------
// Sensor TSensor1 = { TMP_BOIL_PIN};
Sensor TSensor2 = { TMP_MILK1_PIN};


// init sensors ----------------------------------------------------------
void init_TSensor() {
  sensors.begin();
}




