
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
    else {
      sprintf( str, "   %d", number);
      lcd.setCursor(-4,3);
      lcd.print(str);
    }
    
  }
  
};


// 0000 --------------------------------
Dashboard dash_0000 = { "", " Vortex Labs", " Peoject 001", ""};


// 1000 --------------------------------
Dashboard dash_1000 = { ">1.Start", " 2.Clean Process", " 3.Milk Process", " 4.Settings"};


// 2000 --------------------------------
Dashboard dash_2000 = { " 1.Start", ">2.Clean Process", " 3.Milk Process", " 4.Settings"};

Dashboard dash_2010 = { " Process", " ", " Water Heating to", "Rated Water temp"};
Dashboard dash_2020 = { " Process", " ", " Water Temperature", "Keaping at 90 C"};
Dashboard dash_2030 = { " Process", " ", " Water Heating", " done"};
Dashboard dash_2040 = { " Process", " Cleaning process", " Time Counting", " "};
Dashboard dash_2050 = { " Process", " ", " Milk heating to", " Rated Milk temp"};
Dashboard dash_2060 = { " Process", " Homogi Clean", " Time counting", " "};
Dashboard dash_2070 = { " Process", " ", " Homogenizer", " Cleaning done"};
Dashboard dash_2080 = { " Process", " ", " Draining water", " "};
Dashboard dash_2090 = { " Process", " ", " Tank Cleaning", " Process Done"};

Dashboard dash_2510 = { " Warning", " Boiler Temp", " bellow", " "};
Dashboard dash_2520 = { " Warning", " Tank Temp", " bellow", " "};
Dashboard dash_2530 = { " Warning", " ", " Clean Process", " Faild"};


// 3000 --------------------------------
Dashboard dash_3000 = { " 1.Start", " 2.Clean Process", ">3.Milk Process", " 4.Settings"};

Dashboard dash_3010 = { " Process", " ", " Add milk", " "};
Dashboard dash_3015 = { " Process", " ", " Milk heating", " "};
Dashboard dash_3020 = { " Process", " ", " Milk heated to the", "90 C"};
Dashboard dash_3025 = { " Milk Process", " ", " Time counting", " "};
Dashboard dash_3030 = { " Milk Process", " ", " Temp maintaining", " done"};
Dashboard dash_3035 = { " Process", " ", " Milk cooling to", "65 C"};
Dashboard dash_3040 = { " Process", " Homoginizing", "Time counting", " "};
Dashboard dash_3045 = { " Process", " ",  " Homoginization", " done"};
Dashboard dash_3050 = { " Process", " Cooling", " Milk", " "};
Dashboard dash_3055 = { " Process", " ", " Culture adding", " "};
Dashboard dash_3060 = { " Process", " ", " Culture Mixing", " "};

Dashboard dash_3110 = { " Temperature", " Below milk keep", "Temperature", " "};
Dashboard dash_3120 = { " Temperature", " In milk keep", "Temperature", " "};
Dashboard dash_3130 = { " Temperature", " Above milk keep", "Temperature", " "};

Dashboard dash_3510 = { " Warning", " ", " Boiler Temperature", "below 90 C"};
Dashboard dash_3520 = { " Warning", " ", " Milk Process", "Faild"};
Dashboard dash_3900 = { " ", " Milking", " Process Done", " "};


// 4000 --------------------------------
Dashboard dash_4000 = { " 1.Start", " 2.Clean Process", " 3.Milk Process", ">4.Settings"};

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

Dashboard dash_4901 = { " Setting:", " ", " Save Change", " "};


// 5000 ---------------------------------
Dashboard dash_5000 = { " 2.Clean Process", " 3.Milk Process", " 4.Settings", ">5.Testing"};

Dashboard dash_5001 = { ">01.Temp sens", " 02.Valves", " 03.Pumps", " "};
Dashboard dash_5010 = { ">01.T1 read", " 02.T2 read", " 03.T3 read", " "};
Dashboard dash_5015 = { " Testing :", " T1", " Temp read 'C", " 90"};
Dashboard dash_5020 = { " 01.T1 read", ">02.T2 read", " 03.T3 read", " "};
Dashboard dash_5025 = { " Testing :", " T2", " Temp read 'C", " 90"};
Dashboard dash_5030 = { " 01.T1 read", " 02.T2 read", ">03.T3 read", " "};
Dashboard dash_5035 = { " Testing :", " T3", " Temp read 'C", " 90"};

Dashboard dash_5002 = { " 01.Temp sens", ">02.Valves", " 03.Pumps", " "};
Dashboard dash_5040 = { ">04.Val 1 open", " 05.Val 1 close", " 06.Val 2 open", " 07.Val 2 close"};
Dashboard dash_5045 = { " Testing :", " Opening Valve", " 01", " "};
Dashboard dash_5050 = { " 04.Val 1 open", ">05.Val 1 close", " 06.Val 2 open", " 07.Val 2 close"};
Dashboard dash_5055 = { " Testing :", " Closing Valve", " 01", " "};
Dashboard dash_5060 = { " 05.Val 1 close", ">06.Val 2 open", " 07.Val 2 close", " 08.Val 3 open"};
Dashboard dash_5065 = { " Testing :", " Opening Valve", " 02", " "};
Dashboard dash_5070 = { " 06.Val 2 open", ">07.Val 2 close", " 08.Val 3 open", " 09.Val 3 close"};
Dashboard dash_5075 = { " Testing :", " Closing Valve", " 02", " "};
Dashboard dash_5080 = { " 07.Val 2 close", ">08.Val 3 open", " 09.Val 3 close", " 10.Val 4 open"};
Dashboard dash_5085 = { " Testing :", " Opening Valve", " 03", " "};
Dashboard dash_5090 = { " 08.Val 3 open", ">09.Val 3 close", " 10.Val 4 open", " 11.Val 4 close"};
Dashboard dash_5095 = { " Testing :", " Closing Valve", " 03", " "};
Dashboard dash_5100 = { " 09.Val 3 close", ">10.Val 4 open", " 11.Val 4 close", " 12.Val 5 open"};
Dashboard dash_5105 = { " Testing :", " Opening Valve", " 04", " "};
Dashboard dash_5110 = { " 10.Val 4 open", ">11.Val 4 close", " 12.Val 5 open", " 13.Val 5 close"};
Dashboard dash_5115 = { " Testing :", " Closing Valve", " 04", " "};
Dashboard dash_5120 = { " 11.Val 4 close", ">12.Val 5 open", " 13.Val 5 close", " 14.Val 6 open"};
Dashboard dash_5125 = { " Testing :", " Opening Valve", " 05", " "};
Dashboard dash_5130 = { " 12.Val 5 open", ">13.Val 5 close", " 14.Val 6 open", " 15.Val 6 close"};
Dashboard dash_5135 = { " Testing :", " Closing Valve", " 05", " "};
Dashboard dash_5140 = { " 13.Val 5 close", ">14.Val 6 open", " 15.Val 6 close", " 16.Val 7 open"};
Dashboard dash_5145 = { " Testing :", " Opening Valve", " 06", " "};
Dashboard dash_5150 = { " 14.Val 6 open", ">15.Val 6 close", " 16.Val 7 open", " 17.Val 7 close"};
Dashboard dash_5155 = { " Testing :", " Closing Valve", " 06", " "};
Dashboard dash_5160 = { " 15.Val 6 close", ">16.Val 7 open", " 17.Val 7 close", " 18.Val 8 open"};
Dashboard dash_5165 = { " Testing :", " Opening Valve", " 07", " "};
Dashboard dash_5170 = { " 16.Val 7 open", ">17.Val 7 close", " 18.Val 8 open", " 19.Val 8 close"};
Dashboard dash_5175 = { " Testing :", " Closing Valve", " 07", " "};
Dashboard dash_5180 = { " 17.Val 7 close", ">18.Val 8 open", " 19.Val 8 close", " 20.Val 9 open"};
Dashboard dash_5185 = { " Testing :", " Opening Valve", " 08", " "};
Dashboard dash_5190 = { " 18.Val 8 open", ">19.Val 8 close", " 20.Val 9 open", " 21.Val 9 close"};
Dashboard dash_5195 = { " Testing :", " Closing Valve", " 08", " "};
Dashboard dash_5200 = { " 19.Val 8 close", ">20.Val 9 open", " 21.Val 9 close", " 22.Val 10 open"};
Dashboard dash_5205 = { " Testing :", " Opening Valve", " 09", " "};
Dashboard dash_5210 = { " 20.Val 9 open", ">21.Val 9 close", " 22.Val 10 open", " 23.Val 10 close"};
Dashboard dash_5215 = { " Testing :", " Closing Valve", " 09", " "};
Dashboard dash_5220 = { " 21.Val 9 close", ">22.Val 10 open", " 23.Val 10 close", " 24.Val 11 open"};
Dashboard dash_5225 = { " Testing :", " Opening Valve", " 10", " "};
Dashboard dash_5230 = { " 22.Val 10 open", ">23.Val 10 close", " 24.Val 11 open", " 25.Val 11 close"};
Dashboard dash_5235 = { " Testing :", " Closing Valve", " 10", " "};
Dashboard dash_5240 = { " 23.Val 10 close", ">24.Val 11 open", " 25.Val 11 close", " "};
Dashboard dash_5245 = { " Testing :", " Opening Valve", " 11", " "};
Dashboard dash_5250 = { " 24.Val 11 open", ">25.Val 11 close", " ", " "};
Dashboard dash_5255 = { " Testing :", " Closing Valve", " 11", " "};

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
