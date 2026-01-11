#ifndef PRINT_h
#define PRINT_h

void print() {
  // Serial.print(" angle");
  // Serial.print(angle);
  // Serial.print(" yaw");
  // Serial.print(yaw);
  // Serial.print("\t");
  // // // Serial.println(yawsetpoint);
  // Serial.print(" dir  ");
  // Serial.print(dir);
  // Serial.print("\t");
  // Serial.print("strength  ");
  // Serial.print(strength);
  // Serial.print(" ROT");
  // Serial.print(ROT);

  
  // // // // Serial.println(yawsetpoint);

  // Serial.print(" vy");
  // Serial.print(vy);
  // Serial.print("    ");

  // Serial.print("vx");
  // Serial.print(vx);
  // Serial.print("    ");

  // Serial.print("w1: ");
  // Serial.print(w1);
  // Serial.print("    ");
  // Serial.print("w2: ");
  // Serial.print(w2);
  // Serial.print("    ");
  // Serial.print("w3: ");
  // Serial.print(w3);
  // Serial.print("    ");

  // Serial.print("yaw error:");
  // Serial.print(yawerror);
  // // Serial.print(" yaw integral");
  // // Serial.print(yawintegral);
  // // Serial.print("\t");
  // Serial.print("pwm1 : ");

  // Serial.print(pwm1);
  // Serial.print("\t");
  // Serial.print("pwm2: ");

  // Serial.print(pwm2);
  // Serial.print("\t");
  // Serial.print("pwm3 :");
  // Serial.print(pwm3);
  // Serial.print("\t");
  // Serial.print(" yawsetpoint  ");
  // Serial.print(yawsetpoint);
  // Serial.println(" yawerror ");
  // Serial.print(yawerror);
  // Serial.print("w  ");
  // Serial.print(w);


  //PNEUMATICS ////
  Serial.print(" dir  ");
  Serial.print(dir);
  Serial.print("  OUTPUT : ");
  Serial.print(output);
  Serial.print(" ERROR : ");
  Serial.print(error);
  Serial.print(" PWM : ");
  Serial.print(pwm);

  Serial.print("  Potentiometer1 Value: ");
  Serial.print(analogRead(potpin1)>>2);
  // Serial.print("Potentiometer2 Value: ");
  // Serial.print(analogRead(potpin2)>>2);

  Serial.print("  Motor Direction :");
  Serial.print(motorDirection);
  Serial.print("  Switchpin:  ");
  Serial.println(switchpin1);
}

#endif