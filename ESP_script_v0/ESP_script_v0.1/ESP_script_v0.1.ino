
#include "Display.h"
#include "TempSensor.h"
#include "hmi.h"
#include "Relay.h"
#include "Tank_clear.h"


int Boil_Temp();
int Tank1_Temp();
void printD(char* msg);
void led_set(int num, bool state);
void solenoid(int num, bool state);
void pump(int num, bool state);


void setup() {
  Serial.begin(9600);

  init_dispay();
  init_hmi();
  init_Tsensor();
  init_relay();
   
}

void loop() {

  process_1();
  process_2();
}
