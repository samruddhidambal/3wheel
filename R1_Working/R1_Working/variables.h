#ifndef VARIABLES_H
#define VARIABLES_H


////////////////////////////////////3 wheel motor pins////////////////////////////



#define pwmpin0 5
#define pwmpin120 12
#define pwmpin240 45
#define dirpin0 48
#define dirpin120 36
#define dirpin240 50

unsigned long previousMillis = 0;
unsigned long currentMillis = millis();
const long interval = 100;
float r = 0.072;
float d = 0.426;
const float pi = 3.14159;
float w = 0;
float vx = 0, vy = 0;
float yawerror = 0;
float yawsetpoint = 0;

bool piden = 0;
bool rotating = 0;

int w1 = 0, w2 = 0, w3 = 0;
int pwm1 = 0, pwm2 = 0, pwm3 = 0;
int angle = 0;
int strength = 0;
char dir = 0;
int ROT = 0;
bool yawLocked = false;

float lastyawerror = 0;
float yawintegral = 0;
float Kp_yaw = 0.02;  //0.06 //0.04
float Kd_yaw = 0.1;   //0.04
float Ki_yaw = 0.04;  //0.02
int yaw = 0;
float rad = 0;
float yawderivative;






//////////pneumatics//////////////

#define potpin1 A8
#define potpin2 A10

bool motorRunning1 = false;
bool motorRunning2 = false;


int motorDirection1 = 0;
int motorDirection2 = 0;
int tolerence = 4;
//SIMPLE P CONTROL
float kp = 0.3;
float kd = 0.1500;
float ki = 0.0;
int setpointR1 = 84;
int setpointR2 = 147;
int setpointR3 = 172;

int setpointL1 = 85;
int setpointL2 = 24;
int setpointL3 = 0;



int grip_pin1 = 27;
int grip_pin2 = 29;
int grip_pin3 =10;
int grip_pin4 =30;

int ungrip_pin1= 35;
int ungrip_pin2 = 31;
int ungrip_pin3 = 9;
int ungrip_pin4 = 4;

int extendpin1=37 ;
int retractpin1= 23;
int extendpin2=8;
int retractpin2= 32;

int solenoidpin1= 39;
int solenoidpin2= 3;

int motorpin1=46;
int directionpin1= 52;
int motorpin2=44 ;
int directionpin2= 42;
float targetSetpoint1 = 0.0, output1 = 0.0, error1 = 0.0, lastError1 = 0.0, dt1 = 0.0, lastInput1 = 0.0, cumError1 = 0.0;
float targetSetpoint2 = 0.0, output2 = 0.0, error2 = 0.0, lastError2 = 0.0, dt2 = 0.0, lastInput2 = 0.0, cumError2 = 0.0;
unsigned long prevTime1 = 0;
unsigned long prevTime2 = 0;
bool trigger = false ;
// int motorPins = NULL,dirpins = NULL, potPins = NULL, switchpins = NULL, solenoidpin = NULL;
int switchpin1 = A9, switchpin2 = A14;
int pin = 0;
int pwm_left = 0;
int pwm_right = 0;


#endif