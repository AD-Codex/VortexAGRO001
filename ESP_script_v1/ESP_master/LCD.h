
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


Dashboard dash_0000 = { "", " Vortex Labs", " Peoject 001", ""};
Dashboard dash_1000 = { ">1.Start", " 2.Clean Process", " 3.Milk Process", " 4.Settings"};
Dashboard dash_2000 = { " 1.Start", ">2.Clean Process", " 3.Milk Process", " 4.Settings"};
Dashboard dash_3000 = { " 1.Start", " 2.Clean Process", ">3.Milk Process", " 4.Settings"};
Dashboard dash_4000 = { " 1.Start", " 2.Clean Process", " 3.Milk Process", ">4.Settings"};

Dashboard dash_5000 = { " 2.Clean Process", " 3.Milk Process", " 4.Settings", ">5.Testing"};
Dashboard dash_5010 = { ">01.T1 read", " 02.T2 read", " 03.T3 read", " 04.Val 1 open"};
Dashboard dash_5015 = { " Testing :", " T1", " Temp read 'C", " 90"};
Dashboard dash_5020 = { " 01.T1 read", ">02.T2 read", " 03.T3 read", " 04.Val 1 open"};
Dashboard dash_5025 = { " Testing :", " T2", " Temp read 'C", " 90"};
Dashboard dash_5030 = { " 02.T2 read", ">03.T3 read", " 04.Val 1 open", " 05.Val 1 close"};
Dashboard dash_5035 = { " Testing :", " T3", " Temp read 'C", " 90"};
Dashboard dash_5040 = { " 03.T3 read", ">04.Val 1 open", " 05.Val 1 close", " 06.Val 2 open"};
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
Dashboard dash_5120 = { " 11.Val 4 close", ">12.Val 5 open", " 13.Val 5 close", " 14.Pmp 1 open"};
Dashboard dash_5125 = { " Testing :", " Opening Valve", " 05", " "};
Dashboard dash_5130 = { " 12.Val 5 open", ">13.Val 5 close", " 14.Pmp 1 open", " 15.Pmp 1 close"};
Dashboard dash_5135 = { " Testing :", " Closing Valve", " 05", " "};
Dashboard dash_5140 = { " 13.Val 5 close", ">14.Pmp 1 open", " 15.Pmp 1 close", " 16.Pmp 2 open"};
Dashboard dash_5145 = { " Testing :", " Opening Pump", " 01", " "};
Dashboard dash_5150 = { " 14.Pmp 1 open", ">15.Pmp 1 close", " 16.Pmp 2 open", " 17.Pmp 2 close"};
Dashboard dash_5155 = { " Testing :", " Closing Pump", " 01", " "};
Dashboard dash_5160 = { " 15.Pmp 1 close", ">16.Pmp 2 open", " 17.Pmp 2 close", " 18.Pmp 3 open"};
Dashboard dash_5165 = { " Testing :", " Opening Pump", " 02", " "};
Dashboard dash_5170 = { " 16.Pmp 2 open", ">17.Pmp 2 close", " 18.Pmp 3 open", " 19.Pmp 3 close"};
Dashboard dash_5175 = { " Testing :", " Closing Pump", " 02", " "};
Dashboard dash_5180 = { " 17.Pmp 2 close", ">18.Pmp 3 open", " 19.Pmp 3 close", " 20.Pmp 4 open"};
Dashboard dash_5185 = { " Testing :", " Opening Pump", " 03", " "};
Dashboard dash_5190 = { " 18.Pmp 3 open", ">19.Pmp 3 close", " 20.Pmp 4 open", " 21.Pmp 4 close"};
Dashboard dash_5195 = { " Testing :", " Closing Pump", " 03", " "};
