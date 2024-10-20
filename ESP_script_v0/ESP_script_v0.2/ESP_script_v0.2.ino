
# include "LCD.h"
# include "Relay.h"
# include "HMI.h"
# include "TSensor.h"
# include "main_Fn.h"
# include "waterHeat.h"
# include "milkHeat.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  init_HMI();
  init_Relay();
  init_TSensor();
}

void loop() {
  // put your main code here, to run repeatedly:
  button_Test();
}
