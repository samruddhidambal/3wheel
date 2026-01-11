#ifndef PNEUMATICPID_H
#define PNEUMATICPID_H

#include "Variables.h"

void MotorControl1(int motorpin1, int dirpin1, int potpin1, int solenoidpin1) {
  if (!motorRunning1) {
    cumError1 = 0;
    lastError1 = 0;
    return;
  }

  int input1 = analogRead(potpin1) >> 2;
  unsigned long now1 = millis();
  long timeChange1 = (now1 - prevTime1);
  if (timeChange1 <= 10) return;

  error1 = targetSetpoint1 - input1;
  if (abs(error1) <= tolerence) {
    pwm_right = 0;
    analogWrite(motorpin1, pwm_right);
    digitalWrite(solenoidpin1, LOW);
    return;
  }


  dt1 = timeChange1 / 1000.0;
  // float dinput = (input - lastInput)/dt;
  float rateError = (error1 - lastError1) / dt1;
  cumError1 += error1 * dt1;
  cumError1 = constrain(cumError1, -100, 100);

  if (error1 > 0) {
    output1 = 140 + kp * error1 + kd * rateError + ki * cumError1;

  } else {
    output1 = -20 + kp * error1 + kd * rateError + ki * cumError1;
  }


  if (abs(error1) <= 6) {
    digitalWrite(solenoidpin1, LOW);
    return;
  }

  pwm_right = constrain(abs(output1), 0, 255);
  digitalWrite(directionpin1, (output1 >= 0) ? LOW : HIGH);
  // Serial.print("OUTPUT : ");
  // Serial.print(output);
  // Serial.print(" ERROR : ");
  // Serial.print(error);
  // Serial.print(" RATEERROR : ");
  // Serial.print(rateError);
  // Serial.print(" PWM : ");
  // Serial.println(pwm);
  analogWrite(motorpin1, pwm_right);

  // lastInput = input;
  lastError1 = error1;
  prevTime1 = now1;
}

#endif