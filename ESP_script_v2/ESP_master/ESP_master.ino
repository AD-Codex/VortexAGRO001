
# include "LCD.h"
# include "HMI.h"
# include "Relay.h"
# include "TSensor.h"
# include "Valves.h"
# include "Switches.h"
# include "Serial.h"
# include "Process.h"
# include "Dashboard.h"


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
  delay(1000);

  // init buzzer
  init_Indicators();

  // init serial connection
  init_serial();
  serialCom_check();
  
  // update state to 0
  state_list_index_update();

  // init the relay module
  init_Relay();

  // init the temp sensors
  init_TSensor();

  // init flash memory
  // begin_Flash();
  init_Flash();

  // check power off start
  PowerOff_process();

  // start system
  dash_1000.display_(0);

}

void loop() {


  dashboard_update();
  delay(200);

  // TSensor2.Read();
  // delay(1000);

  // if (SerialPort.available()) {
  //     char number = SerialPort.read();
  //     Serial.println(number);
  // }


}
