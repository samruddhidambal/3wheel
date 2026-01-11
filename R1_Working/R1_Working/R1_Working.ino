#include <ArduinoJson.h>
#include "pid.h"
#include "command.h"
#include "Variables.h"
#include "staffgripper.h"
#include "motorlogic.h"
#include "PRINT.h"
#include "pneumaticpid.h"
#include"pneumaticleft.h"


enum state { Data_reception,
             pid_cal,
             matrix_cal,
             print_state };

state currentstate = Data_reception;

gripstate1 current_grip1 = ungrip1;
gripstate2 current_grip2 = ungrip2;
gripstate3 current_grip3 = ungrip3;
gripstate4 current_grip4 = ungrip4;

piston1 current_piston1 = down1;
piston2 current_piston2 = down2;

rotation1 current_rotation1 = front1;
rotation2 current_rotation2 = front2;
void setup() {
  Serial.begin(38400);
  Serial3.begin(38400);
  pinMode(pwmpin0, OUTPUT);
  pinMode(pwmpin120, OUTPUT);
  pinMode(pwmpin240, OUTPUT);
  pinMode(dirpin0, OUTPUT);
  pinMode(dirpin120, OUTPUT);
  pinMode(dirpin240, OUTPUT);

  //-------------------------------------Pnematics------------------------------------------//
  pinMode(grip_pin1, OUTPUT);
  pinMode(grip_pin2, OUTPUT);
  pinMode(grip_pin3, OUTPUT);
  pinMode(grip_pin4, OUTPUT);
  pinMode(ungrip_pin1, OUTPUT);
  pinMode(ungrip_pin2, OUTPUT);
  pinMode(ungrip_pin3, OUTPUT);
  pinMode(ungrip_pin4, OUTPUT);
  pinMode(retractpin1, OUTPUT);
  pinMode(retractpin2, OUTPUT);
  pinMode(extendpin1, OUTPUT);
  pinMode(extendpin2, OUTPUT);
  pinMode(solenoidpin1, OUTPUT);
  pinMode(solenoidpin2, OUTPUT);

  pinMode(motorpin1, OUTPUT);
  pinMode(motorpin2, OUTPUT);
  pinMode(directionpin1, OUTPUT);
  pinMode(directionpin2, OUTPUT);

  pinMode(switchpin1, INPUT_PULLUP);
  pinMode(switchpin2, INPUT_PULLUP);

  // pneumatics(pinD);
  // pneumatics(pinA);
}

void loop() {


  switch (currentstate) {
    case Data_reception:

      command();
      if (dir == 'L' || dir == 'R') {
        currentstate = matrix_cal;
      } else {
        currentstate = pid_cal;
      }

      break;

    case pid_cal:
      pid();
      currentstate = matrix_cal;
      break;

    case matrix_cal:
      moveMotor1();
      currentstate = print_state;
      break;

    case print_state:
      print();
      currentstate = Data_reception;
      break;
  }
 
  if(currentMillis-previousMillis>= interval){
      if (trigger) {
    digitalWrite(pin, HIGH);
    // delay(100);
    digitalWrite(pin, LOW);
    trigger = false;
  }
       previousMillis = currentMillis;
  }

  switchPress1(switchpin1, motorpin1);
  switchPress2(switchpin2, motorpin2);
  // if(motorPins != NULL && dirpins != NULL && potPins != NULL && trigger == false && solenoidpin != NULL){
  MotorControl1(motorpin1, directionpin1, potpin1, solenoidpin1);
  // }
  MotorControl2(motorpin2, directionpin2, potpin2, solenoidpin2);
    
}