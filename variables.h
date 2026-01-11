#ifndef VARIABLES_H
#define VARIABLES_H


////////////////////////////////////3 wheel motor pins////////////////////////////


#define pwmpin1 5
#define pwmpin2 12
#define pwmpin3 45

#define dirpin1 48
#define dirpin2 36
#define dirpin3 50


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
#define potpin2 A1

bool motorRunning = false;
int motorDirection = 0;
int tolerence = 4;
//SIMPLE P CONTROL
float kp = 0.438;
float kd = 0.100;
float ki = 0.250;

int setpointA = 85;
int setpointB = 20;
int setpointx = 0;

int grip_pin1 = 27;
int grip_pin2 = 29;
int grip_pin3 =10;
int grip_pin4 =33;

int ungrip_pin1= 35;
int ungrip_pin2 = 31;
int ungrip_pin3 = 9;
int ungrip_pin4 = 5;

int extendpin1=37 ;
int retractpin1= 23;
int extendpin2=39;
int retractpin2= 37;

int solenoidpin1= 39;
int solenoidpin2= 32;

int motorpin1=46;
int directionpin1= 52;
int motorpin2=44 ;
int directionpin2= 42;
float targetSetpoint = 0.0, output = 0.0, error = 0.0, lastError = 0.0, dt = 0.0, lastInput = 0.0, cumError = 0.0;
unsigned long prevTime = 0;
bool trigger = false ;
int motorPins = NULL,dirpins = NULL, potPins = NULL, switchpins = NULL, solenoidpin = NULL;
int switchpin1 = A9, switchpin2 = 40;
int pin = 0;
int pwm = 0;


#endif