#ifndef MOTORLOGIC_H
#define MOTORLOGIC_H
#include "Variables.h"

void moveMotor1() {
  // angle=90;
  if (angle == 400) {
    vx = 0;
    vy = 0;
  } else {

    angle = (angle + 180) % 360;

    rad = (angle * (pi / 180));
    vx = 2 * cos(rad) * strength / 100;
    vy = 2 * sin(rad) * strength / 100;
  }
  // yaw=0;
  w1 = (cos((0 + yaw) * (pi / 180)) * vx + sin((0 + yaw) * (pi / 180)) * vy + d * w) / r;
  w2 = (cos((120 + yaw) * (pi / 180)) * vx + sin((120 + yaw) * (pi / 180)) * vy + d * w) / r;
  w3 = (cos((240 + yaw) * (pi / 180)) * vx + sin((240 + yaw) * (pi / 180)) * vy + d * w) / r;
  if (dir == 'L' || dir == 'R') {
    digitalWrite(dirpin1, w1 < 0 ? 1 : 0);
  }
  digitalWrite(dirpin1, w1 > 0 ? 1 : 0);
  digitalWrite(dirpin2, w2 < 0 ? 1 : 0);
  digitalWrite(dirpin3, w3 > 0 ? 1 : 0);
  pwm1 = (w1)*4;
  pwm1 = abs(pwm1);
  pwm2 = (w2)*5;
  pwm2 = abs(pwm2);
  pwm3 = (w3)*5;
  pwm3 = abs(pwm3);
  pwm1 = constrain(pwm1, 0, 150);
  pwm2 = constrain(pwm2, 0, 150);
  pwm3 = constrain(pwm3, 0, 150);

  analogWrite(pwmpin1, pwm1);
  analogWrite(pwmpin2, pwm2);
  analogWrite(pwmpin3, pwm3);
}


#endif