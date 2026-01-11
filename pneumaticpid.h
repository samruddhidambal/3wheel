#ifndef PNEUMATICPID_H
#define PNEUMATICPID_H

#include "Variables.h"

void MotorControl(int motorPin, int dirpin, int potPin, int solenoidpin) {
  if (!motorRunning) return;

  digitalWrite(solenoidpin, HIGH);

  int input = analogRead(potPin) >> 2;
  unsigned long now = millis();
  long timeChange = (now - prevTime);
  if (timeChange <= 10) return;

  error = targetSetpoint - input;

  if (abs(error) <= tolerence) {
    pwm = 0;
    motorPin = motorpin1;
    analogWrite(motorPin, pwm);
    // digitalWrite(solenoidpin, LOW);
    // return;
  }

  if (error > 0) {
    motorDirection = -1;
  } else {
    motorDirection = 1;
  }


  if (abs(error) <= 6) {
    digitalWrite(solenoidpin, LOW);
    return;
  }

  dt = timeChange / 1000.0;
  // float dinput = (input - lastInput)/dt;
  float rateError = (error - lastError) / dt;
  cumError += error * dt;
  cumError = constrain(cumError, -100, 100);

  // output = kp*error + kd*dinput;
  output = kp * error + kd * rateError + ki * cumError;

  pwm = constrain(abs(output), 0, 255);
  digitalWrite(dirpin, (output >= 0) ? HIGH : LOW);
  // Serial.print("OUTPUT : ");
  // Serial.print(output);
  // Serial.print(" ERROR : ");
  // Serial.print(error);
  // Serial.print(" RATEERROR : ");
  // Serial.print(rateError);
  // Serial.print(" PWM : ");
  // Serial.println(pwm);
  analogWrite(motorPin, pwm);

  // lastInput = input;
  lastError = error;
  prevTime = now;
}

#endif