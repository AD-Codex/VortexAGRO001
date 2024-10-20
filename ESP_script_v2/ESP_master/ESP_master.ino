
# include "LCD.h"
# include "HMI.h"
# include "Relay.h"
# include "TSensor.h"
# include "Valves.h"
# include "Dashboard.h"
# include "Serial.h"


char number  = ' ';

void setup() {
  Serial.begin(115200);
  Serial.println("ESP32 booting");


  // init the display at beginning
  lcd.init();
  lcd.backlight();

  
  // init user buttons
  init_HMI();
  dash_0000.display_(0);


  // init serial connection
  init_serial();
  // serialCom_check();

  
  // update state to 0
  state_list_index_update();


  // init the relay module
  init_Relay();


  // init the temp sensors
  init_TSensor();


  // init valves
  valveCheck();


  delay(1000);
  // start system
  dash_1000.display_(0);

}

void loop() {

  dashboard_update();
  delay(200);

  // if (SerialPort.available()) {
  //     char number = SerialPort.read();
  //     Serial.println(number);
  // }


}
