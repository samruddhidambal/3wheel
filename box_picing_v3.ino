 const int pwmPin = 5;
const int dirPin = 8;
const int encA = 2;
const int encB = 3;
const int Grip = 7;
const int Ungrip = 6;
const int Grip1 = 9;
const int Ungrip1 = 10;


volatile long encoderCount = 0;


float output = 0;
long derivative = 0;
int setpoint = 0;
int currentPoint = 0;
char input;
int pwm = 0;
int error = 0;
int tolerance = 15;
bool en = 0;

float Kp_up = 0.360;
float Kd_up = 0.0064;

float Kp_down = 0.05;
float Kd_down = 0.2;

int lastError = 0;
unsigned long lastTime = 0;


void encoderISR() {
  if (digitalRead(encB)) {
    encoderCount++;
  }

  else {
    encoderCount--;
  }
}

void setup() {

  Serial.begin(9600);

  pinMode(pwmPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(encA, INPUT_PULLUP);
  pinMode(encB, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(encA), encoderISR, RISING);
  
  pinMode(Grip, OUTPUT);
  pinMode(Ungrip, OUTPUT);
  pinMode(Grip1, OUTPUT);
  pinMode(Ungrip1, OUTPUT);

  digitalWrite(Grip, LOW);
  digitalWrite(Ungrip, LOW);
  digitalWrite(Grip1, LOW);
  digitalWrite(Ungrip1, LOW);

  Serial.println("Enter 1,2,3,4 to move motor.");
  Serial.println("Commands: g = Grip, u = Ungrip, N = Neutral");
  Serial.println("enter commands: x=Grip1,y=Ungrip2");
  lastTime = micros();
}

void loop() {
  currentPoint = encoderCount;
  moveToSetpoint();

  if (Serial.available()) {
    input = Serial.read();
    switch (input) {
      case '1':
        
        setpoint = 1400;  
        en = 1;
        break;
      case '2':
        
        setpoint = 2856;  
        en = 1;
        break;
      case '3':
        setpoint = 0;
        en = 1;
        break;
  
      
      case 'g':
        Serial.print("GRIP");
        digitalWrite(Grip, HIGH);
        delay(500);
        digitalWrite(Grip, LOW);
        break;
      case 'u':
        Serial.print("UNGRIP");
        digitalWrite(Ungrip, HIGH);
        delay(500);
        digitalWrite(Ungrip, LOW);
        break;

      case 'x':
        Serial.print("Grip1");
        digitalWrite(Grip1, HIGH);
        delay(500);
        digitalWrite(Grip1, LOW);
        break;
      case 'y':
        Serial.print("UNGRIP1");
        digitalWrite(Ungrip1, HIGH);
        delay(500);
        digitalWrite(Ungrip1, LOW);
        break;

      default:
        break;
    }
  }
  printStatus();
}

void moveToSetpoint() {
  if (!en) return;

  error = setpoint - currentPoint;

  if (abs(error) <= tolerance) {  // base condition
    analogWrite(pwmPin, 0);
    en = 0;
    return;
  }

  if (error > 0) {5
    error = abs(error);
    output = Kp_up * error + Kd_up * derivative;
    digitalWrite(dirPin, HIGH);
  } else {
    error = abs(error);
    output = Kp_down * error + Kd_down * derivative;
    digitalWrite(dirPin, LOW);
  }
  output = constrain(output, 0, 255);
  pwm = output;
 
  analogWrite(pwmPin, pwm);
  lastError = error;
  derivative = (error - lastError);
}
void printStatus() {
  int display_error = setpoint - encoderCount;
  Serial.print("SP:");
  Serial.print(setpoint);

  Serial.print("  ERR:");
  Serial.print(display_error);

  Serial.print("  PWM:");
  Serial.print(pwm);
  Serial.print("  ENC:");
  Serial.println(encoderCount);
}
