

#define BUTTON_EMERG_PIN 12   // emergency stop
#define BUTTON_UP_PIN 14      // up
#define BUTTON_EN_PIN 25      // enter
#define BUTTON_BK_PIN 27      // back
#define BUTTON_DN_PIN 26      // down

#define ERROR_LED 32
#define BUZZ_PIN 33



unsigned long last_button_time = 0;

// Button object deffine ------------------------------------------------------------
struct Button {
  const uint8_t PIN;
  bool pressed;
  unsigned long button_time;

};

Button enter_BN = { BUTTON_EN_PIN, false, 0};
Button back_BN = { BUTTON_BK_PIN, false, 0};
Button up_BN = { BUTTON_UP_PIN, false, 0};
Button down_BN = { BUTTON_DN_PIN, false, 0};
Button emergeny_BN = { BUTTON_EMERG_PIN, false, 0};


// interrupt Fn ---------------------------------------------------------------------
void IRAM_ATTR emergency_pressed() {
  emergeny_BN.button_time = millis();
  if ( emergeny_BN.button_time - last_button_time > 250) 
  {
    if ( digitalRead(emergeny_BN.PIN == LOW)) {
      emergeny_BN.pressed = true;
      last_button_time = emergeny_BN.button_time;
    }
  }
}

void IRAM_ATTR enter_pressed() {
  enter_BN.button_time = millis();
  if ( enter_BN.button_time - last_button_time > 250) 
  {
    if ( digitalRead(enter_BN.PIN == LOW)) {
      enter_BN.pressed = true;
      last_button_time = enter_BN.button_time;
    }
  }
}

void IRAM_ATTR back_pressed() {
  back_BN.button_time = millis();
  if ( back_BN.button_time - last_button_time > 250) 
  {
    if ( digitalRead(back_BN.PIN == LOW)) {
      back_BN.pressed = true;
      last_button_time = back_BN.button_time;
    }
  }
}

void IRAM_ATTR up_pressed() {
  up_BN.button_time = millis();
  if ( up_BN.button_time - last_button_time > 250) 
  {
    if ( digitalRead(up_BN.PIN == LOW)) {
      up_BN.pressed = true;
      last_button_time = up_BN.button_time;
    }
  }
}

void IRAM_ATTR down_pressed() {
  down_BN.button_time = millis();
  if ( down_BN.button_time - last_button_time > 250) 
  {
    if ( digitalRead(down_BN.PIN == LOW)) {
      down_BN.pressed = true;
      last_button_time = down_BN.button_time;
    }
  }
}


// init H M I input buttons -----------------------------------------------------
void init_HMI() {
  pinMode(emergeny_BN.PIN, INPUT_PULLUP);
  pinMode(enter_BN.PIN, INPUT_PULLUP);
  pinMode(back_BN.PIN, INPUT_PULLUP);
  pinMode(up_BN.PIN, INPUT_PULLUP);
  pinMode(down_BN.PIN, INPUT_PULLUP);

  attachInterrupt(emergeny_BN.PIN, emergency_pressed, FALLING);
  attachInterrupt(enter_BN.PIN, enter_pressed, FALLING);
  attachInterrupt(back_BN.PIN, back_pressed, FALLING);
  attachInterrupt(up_BN.PIN, up_pressed, FALLING);
  attachInterrupt(down_BN.PIN, down_pressed, FALLING);
   
  
}

// reset butto state --------------------------------------------------------
void reset_buttons(){
  enter_BN.pressed = false;
  back_BN.pressed = false;
  up_BN.pressed = false;
  down_BN.pressed = false;
}


// test cases for buttons ----------------------------------------------------------
void button_Test() {
  if ( emergeny_BN.pressed)  {
    Serial.println("E pressed");
    emergeny_BN.pressed = false;
  }

  if ( enter_BN.pressed)  {
    Serial.println("Enter pressed");
    enter_BN.pressed = false;
  }

  if (back_BN.pressed)  {
    Serial.println("Back pressed");
    back_BN.pressed = false;
  }

  if ( up_BN.pressed)  {
    Serial.println("Up pressed");
    up_BN.pressed = false;
  }

  if ( down_BN.pressed)  {
    Serial.println("Down pressed");
    down_BN.pressed = false;
  }
}


// init indicators Fn ----------------------------------------------
void init_Indicators() {
  pinMode( BUZZ_PIN, OUTPUT);
  pinMode( ERROR_LED, OUTPUT);

  digitalWrite( BUZZ_PIN, LOW);
  digitalWrite( ERROR_LED, LOW);
}

void buzzerBeep( int num) {
  for (int beep = 0; beep<num; beep++){
    digitalWrite( BUZZ_PIN, HIGH);
    delay(200);
    digitalWrite( BUZZ_PIN, LOW);
    delay(200);
  }
  
}

void buzzerHigh( bool state) {
  digitalWrite( BUZZ_PIN, state);  
}

void  errorLED( bool state) {
  digitalWrite( ERROR_LED, state);
}
