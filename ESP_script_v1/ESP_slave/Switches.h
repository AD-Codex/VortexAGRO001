//index, close, open, EN1, EN2
//set1, 34, 35, 32, 33
//set2, 25, 26, 27, 14
//set3, 36, 39, 12, 13
//set4, 23, 22, 21, 19
//set5, 18, 5, 4, 2

// switch normslly close
// A - close switch
// B - open switchh

#define SWITCH_SET1_A_PIN 34
#define SWITCH_SET1_B_PIN 35

#define SWITCH_SET2_A_PIN 25
#define SWITCH_SET2_B_PIN 26

#define SWITCH_SET3_A_PIN 36
#define SWITCH_SET3_B_PIN 39
//
#define SWITCH_SET4_A_PIN 23
#define SWITCH_SET4_B_PIN 22

#define SWITCH_SET5_A_PIN 18
#define SWITCH_SET5_B_PIN 5



struct Switch {
  const uint8_t PIN;
  bool pressed;
  unsigned long last_button_time;
  unsigned long new_button_time;
 
  
};

Switch switch_1A = {SWITCH_SET1_A_PIN, true, 0, 0};
Switch switch_1B = {SWITCH_SET1_B_PIN, true, 0, 0};
Switch switch_2A = {SWITCH_SET2_A_PIN, true, 0, 0};
Switch switch_2B = {SWITCH_SET2_B_PIN, true, 0, 0};
Switch switch_3A = {SWITCH_SET3_A_PIN, true, 0, 0};
Switch switch_3B = {SWITCH_SET3_B_PIN, true, 0, 0};
Switch switch_4A = {SWITCH_SET4_A_PIN, true, 0, 0};
Switch switch_4B = {SWITCH_SET4_B_PIN, true, 0, 0};
Switch switch_5A = {SWITCH_SET5_A_PIN, true, 0, 0};
Switch switch_5B = {SWITCH_SET5_B_PIN, true, 0, 0};


void Switch_check() {
  Serial.println("---- Switch Checking -----");
  
  if ( digitalRead(switch_1A.PIN) == LOW ) {
    switch_1A.pressed = false;
    Serial.print("switch 1A open, ");
  }
  else {
    switch_1A.pressed = true;
    Serial.print("switch 1A close, ");
  }
  if ( digitalRead(switch_1B.PIN) == LOW ) {
    switch_1B.pressed = false;
    Serial.println("switch 1B open");
  }
  else {
    switch_1B.pressed = true;
    Serial.println("switch 1B close");
  }
  

  if ( digitalRead(switch_2A.PIN) == LOW ) {
    switch_2A.pressed = false;
    Serial.print("switch 2A open, ");
  }
  else {
    switch_2A.pressed = true;
    Serial.print("switch 2A close, ");
  }
  if ( digitalRead(switch_2B.PIN) == LOW ) {
    switch_2B.pressed = false;
    Serial.println("switch 2B open");
  }
  else {
    switch_2B.pressed = true;
    Serial.println("switch 2B close");
  }


  if ( digitalRead(switch_3A.PIN) == LOW ) {
    switch_3A.pressed = false;
    Serial.print("switch 3A open, ");
  }
  else {
    switch_3A.pressed = true;
    Serial.print("switch 3A close, ");
  }
  if ( digitalRead(switch_3B.PIN) == LOW ) {
    switch_3B.pressed = false;
    Serial.println("switch 3B open");
  }
  else {
    switch_3B.pressed = true;
    Serial.println("switch 3B close");
  }


  if ( digitalRead(switch_4A.PIN) == LOW ) {
    switch_4A.pressed = false;
    Serial.print("switch 4A open, ");
  }
  else {
    switch_4A.pressed = true;
    Serial.print("switch 4A close, ");
  }
  if ( digitalRead(switch_4B.PIN) == LOW ) {
    switch_4B.pressed = false;
    Serial.println("switch 4B open");
  }
  else {
    switch_4B.pressed = true;
    Serial.println("switch 4B close");
  }



  if ( digitalRead(switch_5A.PIN) == LOW ) {
    switch_5A.pressed = false;
    Serial.print("switch 5A open, ");
  }
  else {
    switch_5A.pressed = true;
    Serial.print("switch 5A close, ");
  }
  if ( digitalRead(switch_5B.PIN) == LOW ) {
    switch_5B.pressed = false;
    Serial.println("switch 5B open");
  }
  else {
    switch_5B.pressed = true;
    Serial.println("switch 5B close");
  }

}


// Switch 1 define -------------------------------------------
void IRAM_ATTR switch_1A_pressed() {
  switch_1A.new_button_time = millis();
  if ( switch_1A.new_button_time - switch_1A.last_button_time > 500) 
  {
    if ( digitalRead(switch_1A.PIN) == HIGH) {
      switch_1A.pressed = true;
      switch_1A.last_button_time = switch_1A.new_button_time;
    }
  }
}

void IRAM_ATTR switch_1B_pressed() {
  switch_1B.new_button_time = millis();
  if ( switch_1B.new_button_time - switch_1B.last_button_time > 500) 
  {
    if ( digitalRead(switch_1B.PIN) == HIGH) {
      switch_1B.pressed = true;
      switch_1B.last_button_time = switch_1B.new_button_time;
    }
  }
}


// Switch 2 define -----------------------------------------------
void IRAM_ATTR switch_2A_pressed() {
  switch_2A.new_button_time = millis();
  if ( switch_2A.new_button_time - switch_2A.last_button_time > 500) 
  {
    if ( digitalRead(switch_2A.PIN) == HIGH) {
      switch_2A.pressed = true;
      switch_2A.last_button_time = switch_2A.new_button_time;
    }
  }
}

void IRAM_ATTR switch_2B_pressed() {
  switch_2B.new_button_time = millis();
  if ( switch_2B.new_button_time - switch_2B.last_button_time > 500) 
  {
    if ( digitalRead(switch_2B.PIN) == HIGH) {
      switch_2B.pressed = true;
      switch_2B.last_button_time = switch_2B.new_button_time;
    }
  }
}


// Switch 3 define ------------------------------------------------
void IRAM_ATTR switch_3A_pressed() {
  switch_3A.new_button_time = millis();
  if ( switch_3A.new_button_time - switch_3A.last_button_time > 500) 
  {
    if ( digitalRead(switch_3A.PIN) == HIGH) {
      switch_3A.pressed = true;
      switch_3A.last_button_time = switch_3A.new_button_time;
    }
  }
}

void IRAM_ATTR switch_3B_pressed() {
  switch_3B.new_button_time = millis();
  if ( switch_3B.new_button_time - switch_3B.last_button_time > 500) 
  {
    if ( digitalRead(switch_3B.PIN) == HIGH) {
      switch_3B.pressed = true;
      switch_3B.last_button_time = switch_3B.new_button_time;
    }
  }
}


// Switch 4 define ------------------------------------------------
void IRAM_ATTR switch_4A_pressed() {
  switch_4A.new_button_time = millis();
  if ( switch_4A.new_button_time - switch_4A.last_button_time > 500) 
  {
    if ( digitalRead(switch_4A.PIN) == HIGH) {
      switch_4A.pressed = true;
      switch_4A.last_button_time = switch_4A.new_button_time;
    }
  }
}

void IRAM_ATTR switch_4B_pressed() {
  switch_4B.new_button_time = millis();
  if ( switch_4B.new_button_time - switch_4B.last_button_time > 500) 
  {
    if ( digitalRead(switch_4B.PIN) == HIGH) {
      switch_4B.pressed = true;
      switch_4B.last_button_time = switch_4B.new_button_time;
    }
  }
}


// Switch 5 define ----------------------------------------------
void IRAM_ATTR switch_5A_pressed() {
  switch_5A.new_button_time = millis();
  if ( switch_5A.new_button_time - switch_5A.last_button_time > 500) 
  {
    if ( digitalRead(switch_5A.PIN) == HIGH) {
      switch_5A.pressed = true;
      switch_5A.last_button_time = switch_5A.new_button_time;
    }
  }
}

void IRAM_ATTR switch_5B_pressed() {
  switch_5B.new_button_time = millis();
  if ( switch_5B.new_button_time - switch_5B.last_button_time > 500) 
  {
    if ( digitalRead(switch_5B.PIN) == HIGH) {
      switch_5B.pressed = true;
      switch_5B.last_button_time = switch_5B.new_button_time;
    }
  }
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

  Switch_check();

  attachInterrupt(switch_1A.PIN, switch_1A_pressed, RISING);
  attachInterrupt(switch_1B.PIN, switch_1B_pressed, RISING);
  
  attachInterrupt(switch_2A.PIN, switch_2A_pressed, RISING);
  attachInterrupt(switch_2B.PIN, switch_2B_pressed, RISING);

  attachInterrupt(switch_3A.PIN, switch_3A_pressed, RISING);
  attachInterrupt(switch_3B.PIN, switch_3B_pressed, RISING);

  attachInterrupt(switch_4A.PIN, switch_4A_pressed, RISING);
  attachInterrupt(switch_4B.PIN, switch_4B_pressed, RISING);

  attachInterrupt(switch_5A.PIN, switch_5A_pressed, RISING);
  attachInterrupt(switch_5B.PIN, switch_5B_pressed, RISING);
  
}


void switchTest() {
  if (switch_1A.pressed == true) {
    Serial.println("switch_1A.pressed");
    switch_1A.pressed = false;
  }

  if (switch_1B.pressed == true) {
    Serial.println("switch_1B.pressed");
    switch_1B.pressed = false;
  }

  if (switch_2A.pressed == true) {
    Serial.println("switch_2A.pressed");
    switch_2A.pressed = false;
  }

  if (switch_2B.pressed == true) {
    Serial.println("switch_2B.pressed");
    switch_2B.pressed = false;
  }

  if (switch_3A.pressed == true) {
    Serial.println("switch_3A.pressed");
    switch_3A.pressed = false;
  }

  if (switch_3B.pressed == true) {
    Serial.println("switch_3B.pressed");
    switch_3B.pressed = false;
  }

  if (switch_4A.pressed == true) {
    Serial.println("switch_4A.pressed");
    switch_4A.pressed = false;
  }

  if (switch_4B.pressed == true) {
    Serial.println("switch_4B.pressed");
    switch_4B.pressed = false;
  }

  if (switch_5A.pressed == true) {
    Serial.println("switch_5A.pressed");
    switch_5A.pressed = false;
  }

  if (switch_5B.pressed == true) {
    Serial.println("switch_5B.pressed");
    switch_5B.pressed = false;
  }

}
