// Human Interface


#define BUTTON_EMERG_PIN 33    // emergency stop

#define BUTTON_EN_PIN 25      // enter
#define BUTTON_BK_PIN 26      // bank
#define BUTTON_UP_PIN 27      // up
#define BUTTON_DN_PIN 14      // down

#define BUZZER_PIN 32
#define LED_OUT1_PIN 12
#define LED_OUT2_PIN 13

void init_hmi() {
  pinMode(BUTTON_EMERG_PIN, INPUT);

  pinMode(LED_OUT1_PIN, OUTPUT);
  pinMode(LED_OUT2_PIN, OUTPUT);

  digitalWrite(LED_OUT1_PIN, LOW);
  digitalWrite(LED_OUT2_PIN, LOW);  
  
}

void led_set(int num, bool state){
  if (num == 1) {
    digitalWrite(LED_OUT1_PIN, state);
  }
  else if (num == 2) {
    digitalWrite(LED_OUT2_PIN, state);
  }
}
