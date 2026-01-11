#include "Arduino.h"
#ifndef staffgripper_h
#define staffgripper_h
enum gripstate1 {
  grip1,
  ungrip1
};

enum gripstate2 {
  grip2,
  ungrip2
};

enum gripstate3 {
  grip3,
  ungrip3
};

enum gripstate4 {
  grip4,
  ungrip4
};

enum piston1 {
  up1,
  down1
};

enum piston2 {
  up2,
  down2
};


enum rotation1 {
  front1,
  back1
};

enum rotation2 {
  front2,
  back2
};

extern gripstate1 current_grip1;
extern gripstate2 current_grip2;

extern gripstate3 current_grip3;
extern gripstate4 current_grip4;

extern piston1 current_piston1;
extern piston2 current_piston2;

extern rotation1 current_rotation1;
extern rotation2 current_rotation2;



void switchPress1(int switchpin1, int motorpin1) {
  if (digitalRead(switchpin1) == LOW && motorDirection1 == -1) {
    analogWrite(motorpin1, 0);
    motorRunning1 = false;
  }
}
void switchPress2(int switchpin2, int motorpin2) {
  if (digitalRead(switchpin2) == LOW && motorDirection2 == 1) {
    analogWrite(motorpin2, 0);
    motorRunning2 = false;
  }
}



#endif