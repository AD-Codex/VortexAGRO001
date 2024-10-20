
# include "LCD.h"
# include "Relay.h"
# include "TSensor.h"
# include "Valves.h"
# include "HMI.h"
# include "Dashboard.h"


char number  = ' ';

void setup() {
  SerialPort.begin(115200, SERIAL_8N1, 16, 17); 
  Serial.begin(115200);

  lcd.init();
  lcd.backlight();
  
  init_HMI();
  state_list_index_update();
  init_Relay();
  init_TSensor();

  dash_0000.display_(0);
  delay(1000);
  dash_1000.display_(0);

}

void loop() {

  dashboard_update();
  delay(500);

}
