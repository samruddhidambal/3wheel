#ifndef pid_h
#define pid_h
#include "Variables.h"
#define imax 20
#define imin -20

void pid() {
  if (piden) {

    yawerror = yawsetpoint - yaw;
    if (abs(yawerror) < 6) {
      w = 0;
      yawintegral = 0;
      lastyawerror = 0;
      return;
    }
    // Serial.print(" yaw  ");
    // Serial.print(yaw);

    // if (abs(yawerror) < 5 && abs(yawerror)>0) {
    //   yawintegral += yawerror;
    // }
    // else{
    //   yawintegral=0;
    // }
    yawintegral += yawerror;
    yawintegral = constrain(yawintegral, imin, imax);

    yawderivative = yawerror - lastyawerror;

    w =  (Kp_yaw * yawerror) + (Ki_yaw * yawintegral) + (Kd_yaw * yawderivative);
    lastyawerror = yawerror;
    w = constrain(w, -3, 3);
  }else{
    return;
  }
}
#endif