#ifndef PNEUMATICLEFT_H
#define PNEUMATICLEFT_H

#include "Variables.h"

void MotorControl2(int motorpin2, int directionpin2, int potpin2, int solenoidpin2) {
  if (!motorRunning2) {
    cumError2 = 0;
    lastError2 = 0;
    return;
  }

  int input2 = analogRead(potpin2) >> 2;
  unsigned long now2 = millis();
  long timeChange2 = (now2 - prevTime2);
  if (timeChange2 <= 10) return;

  error2 = targetSetpoint2 - input2;
  if (abs(error2) <= tolerence) {
    pwm_left = 0;
    digitalWrite(solenoidpin2, LOW);
    analogWrite(motorpin2, pwm_left);
    return;
  }


  dt2 = timeChange2 / 1000.0;
  // float dinput = (input - lastInput)/dt;
  float rateError = (error2 - lastError2) / dt2;
  cumError2 += error2 * dt2;
  cumError2 = constrain(cumError2, -100, 100);


  if (error2 > 0) {
    output2 =   kp * error2 + kd * rateError + ki * cumError2;
  } else {
    output2 = -200 +kp * error2 + kd * rateError + ki * cumError2;
  }


  if (abs(error2) <= 6) {
    digitalWrite(solenoidpin2, LOW);
    return;
  }



  // output = kp*error + kd*dinput;


  pwm_left = constrain(abs(output2), 0, 255);
  digitalWrite(directionpin2, (output2 >= 0) ? HIGH : LOW);
  // Serial.print("OUTPUT : ");
  // Serial.print(output);
  // Serial.print(" ERROR : ");
  // Serial.print(error);
  // Serial.print(" RATEERROR : ");
  // Serial.print(rateError);
  // Serial.print(" PWM : ");
  // Serial.println(pwm);
  analogWrite(motorpin2, pwm_left);

  // lastInput = input;
  lastError2 = error2;
  prevTime2 = now2;
}


#endif