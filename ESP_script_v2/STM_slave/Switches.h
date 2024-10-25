//index, close, open, EN1 , EN2 INTURUPT
//unit1, PB12 , PB13, PA8 , PA11
//unit2, PB14 , PB15, PA12, PB9
//unit3, PB3  , PB4 , PC14, PC15
//unit4, PB5  , PB6 , PA0 , PA1
//unit5, PB7  , PB8 , PA4 , PA5
//unit6, PB0  , PB1 , PA6 , PA7

//index, close, open, EN1 , EN2
//unit1, PB14 , PB15, PB12, PB13
//unit2, PA12 , PB3 , PA8 , PA11
//unit3, PB6  , PB7 , PB4 , PB5 
//unit4, PC14 , PC15, PB8 , PB9 
//unit5, PA4  , PA5 , PA0 , PA1 
//unit6, PB0  , PB1 , PA6 , PA7

// switch normslly close ( pin read 0), when swith trigger (pin read HIGH)
// A - close switch
// B - open switchh

// sending 2pair of 12bit data
// switch close -1, switch open -0

#define SWITCH_SET1_A_PIN PB14
#define SWITCH_SET1_B_PIN PB15

#define SWITCH_SET2_A_PIN PA12
#define SWITCH_SET2_B_PIN PB3

#define SWITCH_SET3_A_PIN PB6
#define SWITCH_SET3_B_PIN PB7

#define SWITCH_SET4_A_PIN PC14
#define SWITCH_SET4_B_PIN PC15

#define SWITCH_SET5_A_PIN PA4
#define SWITCH_SET5_B_PIN PA5

#define SWITCH_SET6_A_PIN PB0
#define SWITCH_SET6_B_PIN PB1


struct Switch {
  const uint8_t PIN;
  bool pressed;
  
};

Switch switch_1A = {SWITCH_SET1_A_PIN, true};
Switch switch_1B = {SWITCH_SET1_B_PIN, true};
Switch switch_2A = {SWITCH_SET2_A_PIN, true};
Switch switch_2B = {SWITCH_SET2_B_PIN, true};
Switch switch_3A = {SWITCH_SET3_A_PIN, true};
Switch switch_3B = {SWITCH_SET3_B_PIN, true};
Switch switch_4A = {SWITCH_SET4_A_PIN, true};
Switch switch_4B = {SWITCH_SET4_B_PIN, true};
Switch switch_5A = {SWITCH_SET5_A_PIN, true};
Switch switch_5B = {SWITCH_SET5_B_PIN, true};
Switch switch_6A = {SWITCH_SET6_A_PIN, true};
Switch switch_6B = {SWITCH_SET6_B_PIN, true};


void checkSwitch_pair( Switch &switch_A, Switch &switch_B, const char* labelA, const char* labelB) {
  // Check switch A
  if (digitalRead(switch_A.PIN) == LOW) {
    switch_A.pressed = false;
    Serial.print(labelA);
    Serial.print(" open, ");
  } else {
    switch_A.pressed = true;
    Serial.print(labelA);
    Serial.print(" close, ");
  }

  // Check switch B
  if (digitalRead(switch_B.PIN) == LOW) {
    switch_B.pressed = false;
    Serial.print(labelB);
    Serial.println(" open");
  } else {
    switch_B.pressed = true;
    Serial.print(labelB);
    Serial.println(" close");
  }

}

void Switch_update() {
  Serial.println("---- Switch Checking -----");

  checkSwitch_pair(switch_1A, switch_1B, "switch 1A", "switch 1B");
  checkSwitch_pair(switch_2A, switch_2B, "switch 2A", "switch 2B");
  checkSwitch_pair(switch_3A, switch_3B, "switch 3A", "switch 3B");
  checkSwitch_pair(switch_4A, switch_4B, "switch 4A", "switch 4B");
  checkSwitch_pair(switch_5A, switch_5B, "switch 5A", "switch 5B");
  checkSwitch_pair(switch_6A, switch_6B, "switch 6A", "switch 6B");

}

void Switch_status() {
  Switch_update();

  String switch_status = String(switch_1A.pressed) + String(switch_1B.pressed) + String(switch_2A.pressed) + String(switch_2B.pressed) + String(switch_3A.pressed) + String(switch_3B.pressed) + String(switch_4A.pressed) + String(switch_4B.pressed) + String(switch_5A.pressed) + String(switch_5B.pressed) + String(switch_6A.pressed) + String(switch_6B.pressed);

  Serial.println(switch_status);
  Serial2.println(switch_status + "\n");
}


void init_Switch() {
  
  pinMode(switch_1A.PIN, INPUT_PULLUP);
  pinMode(switch_1B.PIN, INPUT_PULLUP);
  
  pinMode(switch_2A.PIN, INPUT_PULLUP);
  pinMode(switch_2B.PIN, INPUT_PULLUP);
  
  pinMode(switch_3A.PIN, INPUT_PULLUP);
  pinMode(switch_3B.PIN, INPUT_PULLUP);

  pinMode(switch_4A.PIN, INPUT_PULLUP);
  pinMode(switch_4B.PIN, INPUT_PULLUP);

  pinMode(switch_5A.PIN, INPUT_PULLUP);
  pinMode(switch_5B.PIN, INPUT_PULLUP);

  pinMode(switch_6A.PIN, INPUT_PULLUP);
  pinMode(switch_6B.PIN, INPUT_PULLUP);

  Switch_update();
  
}

