//index, close, open, EN1, EN2
//set1, 34, 35, 32, 33
//set2, 25, 26, 27, 14
//set3, 36, 39, 12, 13
//set4, 23, 22, 21, 19
//set5, 18, 5, 4, 2


#define MOTOR_SET1_EN1_PIN 32
#define MOTOR_SET1_EN2_PIN 33

#define MOTOR_SET2_EN1_PIN 27
#define MOTOR_SET2_EN2_PIN 14

#define MOTOR_SET3_EN1_PIN 12
#define MOTOR_SET3_EN2_PIN 13
//
#define MOTOR_SET4_EN1_PIN 21
#define MOTOR_SET4_EN2_PIN 19

#define MOTOR_SET5_EN1_PIN 4
#define MOTOR_SET5_EN2_PIN 2


struct Motor {
  const uint8_t motorEN1_PIN;
  const uint8_t motorEN2_PIN;
  bool state;

  void init() {
    pinMode(motorEN1_PIN, OUTPUT);
    pinMode(motorEN2_PIN, OUTPUT);
  }

  void motorRunClk() {
    digitalWrite(motorEN1_PIN, LOW);
    digitalWrite(motorEN2_PIN, HIGH);
    state = 01;
  }

  void motorRunAClk() {
    digitalWrite(motorEN1_PIN, HIGH);
    digitalWrite(motorEN2_PIN, LOW);
    state = 10;
  }

  void motorClose() {
    digitalWrite(motorEN1_PIN, LOW);
    digitalWrite(motorEN2_PIN, LOW);
    state = 0;
  }
  
};


Motor motorSet1 = {MOTOR_SET1_EN1_PIN, MOTOR_SET1_EN2_PIN, 11};
Motor motorSet2 = {MOTOR_SET2_EN1_PIN, MOTOR_SET2_EN2_PIN, 11};
Motor motorSet3 = {MOTOR_SET3_EN1_PIN, MOTOR_SET3_EN2_PIN, 11};
Motor motorSet4 = {MOTOR_SET4_EN1_PIN, MOTOR_SET4_EN2_PIN, 11};
Motor motorSet5 = {MOTOR_SET5_EN1_PIN, MOTOR_SET5_EN2_PIN, 11};

void init_motors() {
  
  motorSet1.init();
  motorSet2.init();
  motorSet3.init();
  motorSet4.init();
  motorSet5.init();

}
