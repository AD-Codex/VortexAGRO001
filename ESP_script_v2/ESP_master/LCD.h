
#define LCD_SCL_PIN 22
#define LCD_SDA_PIN 21

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,4);  // set the LCD address to 0x3F for a 16 chars and 2 line display

struct Dashboard {
  String row0;
  String row1;
  String row2;
  String row3;

  void display_(int number) {
    char str[15];
    lcd.clear();         
//    lcd.backlight();
    
    lcd.setCursor(0,0);
    lcd.print(row0);
    lcd.setCursor(0,1);
    lcd.print(row1);
    lcd.setCursor(-4,2);
    lcd.print(row2);
    if (number == 0) {
      lcd.setCursor(-4,3);
      lcd.print(row3);
    }
    else if (number > 0) {
      int s = number % 60;
      number = (number - s)/60;
      int m = number % 60;

      sprintf( str, "   %02d:%02d", m, s);
      lcd.setCursor(-4,3);
      lcd.print(str);
    }
    else {
      sprintf( str, "   %d", number);
      lcd.setCursor(-4,3);
      lcd.print(str);
    }
    
  }

  void valveState( String Astate, String Bstate) {
    lcd.clear();        
    
    lcd.setCursor(0,0);
    lcd.print(row0);
    lcd.setCursor(0,1);
    lcd.print(Astate);
    lcd.setCursor(-4,2);
    lcd.print(Bstate);
    lcd.setCursor(-4,3);
    lcd.print(row3);
  }
  
};


// 0000 --------------------------------
Dashboard dash_0000 = { "", " Vortex Labs", " Project 001", ""};

Dashboard dash_0005 = {"", " Initializing", " Com system", ""};
Dashboard dash_0010 = {" Warning :", " Com fail ...", " recheck in", " after 5s"};
Dashboard dash_0015 = {" Warning :", " Fail to open", " Valve No", " "};
Dashboard dash_0020 = {" Warning :", " Fail to close", " Valve No", " "};
Dashboard dash_0025 = {"", " Initializing", " Valve system", ""};
Dashboard dash_0026 = {"Valve 1-12 state", "", "", "EN-ok,BK-recheck"};
Dashboard dash_0027 = {" ", " Valve Testing", "", "BK - skip"};
Dashboard dash_0030 = {" Syatem Halt !", " EN - Continue"," DN - skip", " BK - Stop"};
Dashboard dash_0040 = {" Process :", " Vat cycle", " Time Count ", "    00:00"};
Dashboard dash_0050 = {" Process :", " Homogenize cycle", " Time Count s", "    00:00"};
Dashboard dash_0060 = {" Warning :", " Continue process", "    EN - Yes", "    BK - No"};

// 1000 --------------------------------
Dashboard dash_1000 = { ">1.Initialize System", " 2.Clean Process", " 3.Milk Process", " 4.Settings"};


// 2000 --------------------------------
Dashboard dash_2000 = { " 1.Initialize System", ">2.Clean Process", " 3.Milk Process", " 4.Settings"};

Dashboard dash_2001 = { " Process : ", " Starting clean", " Process", "   BK - Stop"};
Dashboard dash_2005 = { " Process : ", " Add water ", " EN - Continue", " BK - Stop"};
Dashboard dash_2010 = { " Process :"," Water Heating to", " Rated Temperature", " 90 c"};
// Dashboard dash_2015 = { " Process :", " Water Heating", " done" , " "};
Dashboard dash_2020 = { " Process :"," Water Temperature", " Keaping at s", " 00:00"};
Dashboard dash_2060 = { " Process :", " Homogenize Clean", " Starting", " "};
// Dashboard dash_2070 = { " Process :", " ", " Homogenizer", " Cleaning done"};
Dashboard dash_2080 = { " Process :", " Drain water", " EN - Continue", " BK - Stop"};
Dashboard dash_2090 = { " Process :", " Tank Cleaning", " Process Done", " "};

// Dashboard dash_2510 = { " Warning", " Boiler Temp", " bellow", " "};
// Dashboard dash_2520 = { " Warning", " Tank Temp", " bellow", " "};
Dashboard dash_2530 = { " Warning", " Clean Process", " Faild", " "};


// 3000 --------------------------------
Dashboard dash_3000 = { " 1.Initialize System", " 2.Clean Process", ">3.Milk Process", " 4.Settings"};

Dashboard dash_3001 = { " Process : ", " Starting Milk", " Process", "   BK - Stop"};
Dashboard dash_3005 = { " Process : ", " Add Milk ", " EN - Continue", " BK - Stop"};
Dashboard dash_3010 = { " Process :"," Milk Heating to", " Rated Temperature ", " 90 c"};
// Dashboard dash_3015 = { " Process :", " Milk Heating", " done", " "};
Dashboard dash_3020 = { " Process :"," Milk Temperature", " Keaping at ", " 00:00"};
Dashboard dash_3030 = { " Process :"," Milk Cooling to", " Temperature ", " 65 c"};
// Dashboard dash_3035 = { " Process :", " Milk Cooling", " done", " "};
Dashboard dash_3040 = { " Process :"," Starting Homogenize", " Process", " "};
Dashboard dash_3050 = { " Process", " Culture adding", " EN - Continue", " BK - Stop"};
Dashboard dash_3060 = { " Process :"," Homogenizing ", " Keaping at", " 00:00"};
// Dashboard dash_3065 = { " Process :", " Homogenizing", " done", " "};
Dashboard dash_3070 = { " Process :"," Milk Cooling to", " Temperature ", " 45 c"};
// Dashboard dash_3075 = { " Process :", " Milk Cooling", " done", " "};
Dashboard dash_3900 = { " ", " Milking", " Process Done", " "};


// Dashboard dash_3110 = { " Temperature", " Below milk keep", "Temperature", " "};
// Dashboard dash_3120 = { " Temperature", " In milk keep", "Temperature", " "};
// Dashboard dash_3130 = { " Temperature", " Above milk keep", "Temperature", " "};

// Dashboard dash_3510 = { " Warning", " ", " Boiler Temperature", "below 90 C"};
Dashboard dash_3520 = { " Warning", " ", " Milk Process", "Faild"};


// 4000 --------------------------------
Dashboard dash_4000 = { " 1.Initialize System", " 2.Clean Process", " 3.Milk Process", ">4.Settings"};

Dashboard dash_4010 = { ">1.Temp set", " 2.Time set", " ", " "};
Dashboard dash_4110 = { ">1.Water Temp", " 2.Milk Temp_1", " 3.Milk Temp_2", " 4.Milk Temp_3"};
Dashboard dash_4120 = { " 1.Water Temp", ">2.Milk Temp_1", " 3.Milk Temp_2", " 4.Milk Temp_3"};
Dashboard dash_4130 = { " 1.Water Temp", " 2.Milk Temp_1", ">3.Milk Temp_2", " 4.Milk Temp_3"};
Dashboard dash_4140 = { " 1.Water Temp", " 2.Milk Temp_1", " 3.Milk Temp_2", ">4.Milk Temp_3"};

Dashboard dash_4111 = { " Setting:", " Clean process", " water temp", " 90C"};
Dashboard dash_4121 = { " Setting:", " Milk process", " milk temp_1", " 90C"};
Dashboard dash_4131 = { " Setting:", " Milk process", " milk temp_2", " 65C"};
Dashboard dash_4141 = { " Setting:", " Milk process", " milk temp_3", " 45C"};

Dashboard dash_4020 = { " 1.Temp set", ">2.Time set", " ", " "};
Dashboard dash_4210 = { ">1.Clean time_1", " 2.Clean time_2", " 3.Milk set T1", " 4.Milk set T2"};
Dashboard dash_4220 = { " 1.Clean time_1", ">2.Clean time_2", " 3.Milk set T1", " 4.Milk set T2"};
Dashboard dash_4230 = { " 1.Clean time_1", " 2.Clean time_2", ">3.Milk set T1", " 4.Milk set T2"};
Dashboard dash_4240 = { " 1.Clean time_1", " 2.Clean time_2", " 3.Milk set T1", ">4.Milk set T2"};

Dashboard dash_4211 = { " Setting:", " Clean process", " Time set_1", " 15.00"};
Dashboard dash_4221 = { " Setting:", " Clean process", " Time set_2", " 16.00"};
Dashboard dash_4231 = { " Setting:", " Milk process", " Time set_1", " 17.00"};
Dashboard dash_4241 = { " Setting:", " Milk process", " Time set_1", " 18.00"};

Dashboard dash_4901 = { " Setting:", " Save Change", "   EN - yes", "   BK - skip"};


// 5000 ---------------------------------
Dashboard dash_5000 = { " 2.Clean Process", " 3.Milk Process", " 4.Settings", ">5.Testing"};


Dashboard dash_5001 = { ">01.Temp sens", " 02.Valves", " 03.Pumps", " "};

Dashboard dash_5010 = { ">01.T1 read", " 02.T2 read", " 03.T3 read", "" };
Dashboard dash_5015 = { " Testing :", " T1", " Temp read 'C", " 90"};
Dashboard dash_5020 = { " 01.T1 read", ">02.T2 read", " 03.T3 read", " "};
Dashboard dash_5025 = { " Testing :", " T2", " Temp read 'C", " 90"};
Dashboard dash_5030 = { " 01.T1 read", " 02.T2 read", ">03.T3 read", " "};
Dashboard dash_5035 = { " Testing :", " T3", " Temp read 'C", " 90"};


Dashboard dash_5002 = { " 01.Temp sens", ">02.Valves", " 03.Pumps", " "};

Dashboard dash_5201 = { ">01.Valve 1", " 02.Valve 2", " 03.Valve 3", " 04.Valve 4"};
Dashboard dash_5202 = { " 01.Valve 1", ">02.Valve 2", " 03.Valve 3", " 04.Valve 4"};
Dashboard dash_5203 = { " 01.Valve 1", " 02.Valve 2", ">03.Valve 3", " 04.Valve 4"};
Dashboard dash_5204 = { " 01.Valve 1", " 02.Valve 2", " 03.Valve 3", ">04.Valve 4"};
Dashboard dash_5205 = { ">05.Valve 5", " 06.Valve 6", " 07.Valve 7", " 08.Valve 8"};
Dashboard dash_5206 = { " 05.Valve 5", ">06.Valve 6", " 07.Valve 7", " 08.Valve 8"};
Dashboard dash_5207 = { " 05.Valve 5", " 06.Valve 6", ">07.Valve 7", " 08.Valve 8"};
Dashboard dash_5208 = { " 05.Valve 5", " 06.Valve 6", " 07.Valve 7", ">08.Valve 8"};
Dashboard dash_5209 = { ">09.Valve 9", " 10.Valve 10", " 11.Valve 11", " 12.Valve 12"};
Dashboard dash_5210 = { " 09.Valve 9", ">10.Valve 10", " 11.Valve 11", " 12.Valve 12"};
Dashboard dash_5211 = { " 09.Valve 9", " 10.Valve 10", ">11.Valve 11", " 12.Valve 12"};
Dashboard dash_5212 = { " 09.Valve 9", " 10.Valve 10", " 11.Valve 11", ">12.Valve 12"};

Dashboard dash_5251 = { ">01.Open valve", " 02.Close valve", " 03.Clk turn", " 04.Aclk turn"};
Dashboard dash_5252 = { " 01.Open valve", ">02.Close valve", " 03.Clk turn", " 04.Aclk turn"};
Dashboard dash_5253 = { " 01.Open valve", " 02.Close valve", ">03.Clk turn", " 04.Aclk turn"};
Dashboard dash_5254 = { " 01.Open valve", " 02.Close valve", " 03.Clk turn", ">04.Aclk turn"};

Dashboard dash_5260 = { " Testing :", " ", " Opening Valve", " "};
Dashboard dash_5261 = { " Testing :", " ", " Closing Valve", " "};

Dashboard dash_5270 = { " Warning :", " ", " Valve not ", " Opening"};
Dashboard dash_5271 = { " Warning :", " ", " Valve not ", " Closing"};


Dashboard dash_5003 = { " 01.Temp sens"  , " 02.Valves", ">03.Pumps", " "};

Dashboard dash_5320 = { ">01.Pmp 1 open" , " 02.Pmp 1 close", " 03.Pmp 2 open", " 04.Pmp 2 close"};
Dashboard dash_5325 = { " Testing :", " Opening Pump", " 01", " "};
Dashboard dash_5330 = { " 01.Pmp 1 open" , ">02.Pmp 1 close", " 03.Pmp 2 open", " 04.Pmp 2 close"};
Dashboard dash_5335 = { " Testing :", " Closing Pump", " 01", " "};
Dashboard dash_5340 = { " 02.Pmp 1 close", ">03.Pmp 2 open", " 04.Pmp 2 close", " 05.Pmp 3 open"};
Dashboard dash_5345 = { " Testing :", " Opening Pump", " 02", " "};
Dashboard dash_5350 = { " 03.Pmp 2 open" , ">04.Pmp 2 close", " 05.Pmp 3 open", " 06.Pmp 3 close"};
Dashboard dash_5355 = { " Testing :", " Closing Pump", " 02", " "};
Dashboard dash_5360 = { " 04.Pmp 2 close", ">05.Pmp 3 open", " 06.Pmp 3 close", " "};
Dashboard dash_5365 = { " Testing :", " Opening Pump", " 03", " "};
Dashboard dash_5370 = { " 05.Pmp 3 open" , ">06.Pmp 3 close", " ", " "};
Dashboard dash_5375 = { " Testing :", " Closing Pump", " 03", " "};


// 6000 ---------------------------------
Dashboard dash_6000 = {" 3.Milk Process", " 4.Settings", " 5.Testing", ">6.Diagnostics Run"};

Dashboard dash_6010 = {" Diagnostics :", " Boil pump on?", "     EN - Yes", "      BK - No"};
Dashboard dash_6020 = {" Diagnostics :", " cool pump on?", "     EN - Yes", "      BK - No"};
Dashboard dash_6030 = {" Diagnostics :", " mixer on?", "     EN - Yes", "      BK - No"};
Dashboard dash_6040 = {" Diagnostics :", " Homogenizer on?", "     EN - Yes", "      BK - No"};
Dashboard dash_6050 = {" Diagnostics :", " Homogenizer off?", "     EN - Yes", "      BK - No"};
