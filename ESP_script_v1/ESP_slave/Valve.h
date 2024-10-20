
//Communication Protocol
//A - valve 1 close call back
//B - valve 1 open call back
//C - valve 2 close call back
//D - valve 2 open call back
//E - valve 3 close call back
//F - valve 3 open call back
//G - valve 4 close call back
//H - valve 4 open call back
//I - valve 5 close call back
//J - valve 5 open call back


// valve 1 ------------------------------------------
void valve1Close() {
  Serial.println("closing valve 1");

  if ( digitalRead(switch_1A.PIN) == LOW ) {
    while (switch_1A.pressed != true) {
      motorSet1.motorRunClk();
      delay(10);
    }
  }
  switch_1B.pressed = false;
  motorSet1.motorClose();
  Serial.println("valve 1 closed");
  
  SerialPort.print("A");
  Serial.println("sending A");
}

void valve1Open() {
  Serial.println("opening valve 1");

  if ( digitalRead(switch_1B.PIN) == LOW ) {
    while (switch_1B.pressed != true) {
      motorSet1.motorRunAClk();
      delay(10);
    }
  }
  switch_1A.pressed = false;
  motorSet1.motorClose();
  Serial.println("valve 1 opened");
  
  SerialPort.print("B");
  Serial.println("sending B");
}


// valve 2 ------------------------------------------
void valve2Close() {
  Serial.println("closing valve 2");

  if ( digitalRead(switch_2A.PIN) == LOW ) {
    while (switch_2A.pressed != true) {
      motorSet2.motorRunClk();
      delay(10);
    }
  }
  switch_2B.pressed = false;
  motorSet2.motorClose();
  Serial.println("valve 2 closed");
  
  SerialPort.print("C");
  Serial.println("sending C");
}

void valve2Open() {
  Serial.println("opening valve 2");

  if ( digitalRead(switch_2B.PIN) == LOW ) {
    while (switch_2B.pressed != true) {
      motorSet2.motorRunAClk();
      delay(10);
    }
  }
  switch_2A.pressed = false;
  motorSet2.motorClose();
  Serial.println("valve 2 opened");
  
  SerialPort.print("D");
  Serial.println("sending D");
}


// valve 3 ------------------------------------------
void valve3Close() {
  Serial.println("closing valve 3");

  if ( digitalRead(switch_3A.PIN) == LOW ) {
    while (switch_3A.pressed != true) {
      motorSet3.motorRunClk();
      delay(10);
    }
  }
  switch_3B.pressed = false;
  motorSet3.motorClose();
  Serial.println("valve 3 closed");

  SerialPort.print("E");
  Serial.println("sending E");
}

void valve3Open() {
  Serial.println("opening valve 3");

  if ( digitalRead(switch_3B.PIN) == LOW ) {
    while (switch_3B.pressed != true) {
      motorSet3.motorRunAClk();
      delay(10);
    }
  }
  switch_3A.pressed = false;
  motorSet3.motorClose();
  Serial.println("valve 3 opened");

  SerialPort.print("F");
  Serial.println("sending F");
}



// valve 4 ------------------------------------------
void valve4Close() {
  Serial.println("closing valve 4");

  if ( digitalRead(switch_4A.PIN) == LOW ) {
    while (switch_4A.pressed != true) {
      motorSet4.motorRunClk();
      delay(10);
    }
  }
  switch_4B.pressed = false;
  motorSet4.motorClose();
  Serial.println("valve 4 closed");

  SerialPort.print("G");
  Serial.println("sending G");
}

void valve4Open() {
  Serial.println("opening valve 4");

  if ( digitalRead(switch_4B.PIN) == LOW ) {
    while (switch_4B.pressed != true) {
      motorSet4.motorRunAClk();
      delay(10);
    }
  }
  switch_4A.pressed = false;
  motorSet4.motorClose();
  Serial.println("valve 4 opened");

  SerialPort.print("H");
  Serial.println("sending H");
}



// valve 5 ------------------------------------------
void valve5Close() {
  Serial.println("closing valve 5");

  if ( digitalRead(switch_5A.PIN) == LOW ) {
    while (switch_5A.pressed != true) {
      motorSet5.motorRunClk();
      delay(10);
    }
  }
  switch_5B.pressed = false;
  motorSet5.motorClose();
  Serial.println("valve 5 closed");

  SerialPort.print("I");
  Serial.println("sending I");
}

void valve5Open() {
  Serial.println("opening valve 5");

  if ( digitalRead(switch_5B.PIN) == LOW ) {
    while (switch_5B.pressed != true) {
      motorSet5.motorRunAClk();
      delay(10);
    }
  }
  switch_5A.pressed = false;
  motorSet5.motorClose();
  Serial.println("valve 5 opened");

  SerialPort.print("J");
  Serial.println("sending J");
}
