//index, close, open, EN1 , EN2
//unit1, PB14 , PB15, PB12, PB13
//unit2, PA12 , PB3 , PA8 , PA11
//unit3, PB6  , PB7 , PB4 , PB5 
//unit4, PC14 , PC15, PB8 , PB9 
//unit5, PA4  , PA5 , PA0 , PA1 
//unit6, PB0  , PB1 , PA6 , PA7 


#define MOTOR_SET1_EN1_PIN PA8
#define MOTOR_SET1_EN2_PIN PA11

#define MOTOR_SET2_EN1_PIN PB12
#define MOTOR_SET2_EN2_PIN PB13

#define MOTOR_SET3_EN1_PIN PB4
#define MOTOR_SET3_EN2_PIN PB5

#define MOTOR_SET4_EN1_PIN PB8
#define MOTOR_SET4_EN2_PIN PB9

#define MOTOR_SET5_EN1_PIN PA0
#define MOTOR_SET5_EN2_PIN PA1

#define MOTOR_SET6_EN1_PIN PA6
#define MOTOR_SET6_EN2_PIN PA7


struct Motor {
  const uint8_t motorEN1_PIN;
  const uint8_t motorEN2_PIN;
  bool state;

  void init() {
    pinMode(motorEN1_PIN, OUTPUT);
    pinMode(motorEN2_PIN, OUTPUT);

    digitalWrite(motorEN1_PIN, LOW);
    digitalWrite(motorEN2_PIN, LOW);

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
Motor motorSet6 = {MOTOR_SET6_EN1_PIN, MOTOR_SET6_EN2_PIN, 11};

void init_motors() {
  
  motorSet1.init();
  motorSet2.init();
  motorSet3.init();
  motorSet4.init();
  motorSet5.init();
  motorSet6.init();

}
