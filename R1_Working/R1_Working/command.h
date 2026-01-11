#ifndef command_h
#define command_h
#include "motorlogic.h"
#include "staffgripper.h"

static char lastDir = '\0';

bool isMomentaryCommand(char c) {
  return (c == 'O' || c == 'E' || c == 'g' || c == 'd' || c == 'o' || c == 'e' || c == 'A' || c == 'B' || c == 'X' || c == 'Y');
}

void command() {
  if (Serial3.available()) {

    String message = Serial3.readStringUntil('*');
    // String controllerData;
    Serial.print("message");
    Serial.println(message);
    // Serial.println(message);
    StaticJsonDocument<512> doc;
    DeserializationError err = deserializeJson(doc, message);

    if (err) {
      Serial.print("JSON error: ");
      Serial.println(err.c_str());
      return;
    }

    angle = doc["ANG"];
    strength = doc["STRENGTH"] | 0;
    yaw = doc["YAW"] | 0;
    String dirStr = doc["DIR"] | "S";
    dir = dirStr[0];
    ROT = doc["ROT"];
    // Serial.print("ANGLE");
    // Serial.print(angle);
  }
  if (yaw > 180) yaw -= 360;
  if (yaw < -180) yaw += 360;

  if (isMomentaryCommand(dir)) {
    if (dir == lastDir) return;
  }
  lastDir = dir;

  switch (dir) {

    case 'S':
      rotating = 0;
      piden = 1;
      // yawsetpoint = 0;
      // yawsetpoint = yaw;

      // if (!yawLocked) {
      //   yawsetpoint = yaw;
      //   yawLocked = true;
      // }

      break;

    case 'L':
      // pden=false;
      rotating = 1;
      piden = 0;
      w = (-3 * ROT) / 100;
      vx = 0;
      vy = 0;
      yawsetpoint = yaw;
      break;


    case 'R':
      rotating = 1;
      piden = 0;  // rotating
      w = (3 * ROT) / 100;
      vx = 0;
      vy = 0;
      yawsetpoint = yaw;
      break;

    case 'O':
      switch (current_grip1) {

        case ungrip1:
          trigger = true;
          pin = grip_pin1;
          Serial.println("grip1");
          current_grip1 = grip1;

          break;

        case grip1:
          trigger = true;
          pin = ungrip_pin1;
          Serial.println("ungrip1");
          current_grip1 = ungrip1;
          break;
      }

      break;

    case 'E':
      switch (current_grip2) {

        case ungrip2:
          trigger = true;
          pin = grip_pin2;
          Serial.println("grip2");
          current_grip2 = grip2;

          break;

        case grip2:
          trigger = true;
          pin = ungrip_pin2;
          Serial.println("ungrip2");
          current_grip2 = ungrip2;
          break;
      }
      break;
    case 'd':
      switch (current_grip3) {

        case ungrip3:
          trigger = true;
          pin = grip_pin3;
          Serial.println("grip3");
          current_grip3 = grip3;

          break;

        case grip3:
          trigger = true;
          pin = ungrip_pin3;
          Serial.println("ungrip3");
          current_grip3 = ungrip3;
          break;
      }
      break;
    case 'g':
      switch (current_grip4) {

        case ungrip4:
          trigger = true;
          pin = grip_pin4;
          Serial.println("grip4");
          current_grip4 = grip4;

          break;

        case grip4:
          trigger = true;
          pin = ungrip_pin4;
          Serial.println("ungrip4");
          current_grip4 = ungrip4;
          break;
      }
      break;
    case 'o':
      switch (current_piston1) {

        case down1:
          trigger = true;
          pin = extendpin1;
          Serial.println("up1");
          current_piston1 = up1;
          //up=extractpin1
          //down=retractpin1
          break;

        case up1:
          trigger = true;
          pin = retractpin1;
          Serial.println("down1");
          current_piston1 = down1;
          break;
      }
      break;
    case 'e':
      switch (current_piston2) {

        case down2:
          trigger = true;
          pin = extendpin2;
          Serial.println("up2");
          current_piston2 = up2;

          break;

        case up2:
          trigger = true;
          pin = retractpin2;
          Serial.println("down2");
          current_piston2 = down2;
          break;
      }
      break;
    case 'A':

      switch (current_rotation1) {
        case front1:
          motorDirection1 = -1;
          digitalWrite(solenoidpin1, HIGH);
          motorRunning1 = true;
          Serial.println("back1");
          targetSetpoint1 = setpointR1;
          current_rotation1 = back1;
          break;

        case back1:
          motorDirection1 = 1;
          digitalWrite(solenoidpin1, HIGH);
          motorRunning1 = true;
          Serial.println("front1");
          targetSetpoint1 = setpointR2;
          current_rotation1 = front1;
          break;
      }
      break;

    case 'B':

      switch (current_rotation2) {
        case front2:
          motorDirection2 = 1;
          digitalWrite(solenoidpin2, HIGH);
          motorRunning2 = true;
          Serial.println("back2");
          targetSetpoint2 = setpointL1;
          current_rotation2 = back2;
          break;

        case back2:
          motorDirection2 = -1;
          digitalWrite(solenoidpin2, HIGH);
          motorRunning2 = true;
          Serial.println("front2");
          targetSetpoint2 = setpointL2;
          current_rotation2 = front2;
          break;
      }
      break;

    case 'X':

      switch (current_rotation1) {
        case front1:
          motorDirection1 = 1;
          digitalWrite(solenoidpin1, HIGH);
          motorRunning1 = true;
          Serial.println("x");
          targetSetpoint1 = setpointR3;
          current_rotation1 = front1;
          break;
      }
      break;
    case 'Y':
      switch (current_rotation1) {
        case front1:
          motorDirection2 = 1;
          digitalWrite(solenoidpin2, HIGH);
          motorRunning2 = true;
          Serial.println("x");
          targetSetpoint2 = setpointL3;
          current_rotation1 = front1;
          break;
      }
      break;
    default:
      break;
  }
}


#endif