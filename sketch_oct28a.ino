int motorEnablePinA = 11;
int motorEnablePinB = 3;

int motorPinA1 = 10;
int motorPinA2 = 7;
int motorPinB1 = 12;
int motorPinB2 = 4;

int echoPin = 5;
int trigPin = 6;

bool shouldTurnLeft = false;
bool objInWay = false;

long lecture_echo; 
long cm;
long standardSpeed = 127;

long barrierCm = 100;

void setup() {
  // put your setup code here, to run once:
  pinMode(motorEnablePinA, OUTPUT);
  pinMode(motorEnablePinB, OUTPUT);
  pinMode(motorPinA1, OUTPUT);
  pinMode(motorPinA2, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);

  // why?
  digitalWrite(trigPin, LOW);

  Serial.begin(9600);
  
}

void loop() {  
  // get distance 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW); 
  lecture_echo = pulseIn(echoPin, HIGH); 
  cm = lecture_echo / 58; 

  if (cm < barrierCm) {
   // stop
   objInWay = true;
   stopMoving();
   delay(1000);
   // back up 
   goBackwards(standardSpeed);
   delay(500);
   if (shouldTurnLeft) {
     turnLeft();
   }
   else {
    turnRight();
   }
   delay(500);
  }
  
  else {
    objInWay = false;
    shouldTurnLeft = !shouldTurnLeft;
    goForward(standardSpeed);
    delay(1000);
  }
}


void goForward(long vel) {
  analogWrite(motorEnablePinA, vel);
  analogWrite(motorEnablePinB, vel);
  digitalWrite(motorPinA1, HIGH);
  digitalWrite(motorPinA2, LOW);
  digitalWrite(motorPinB1, HIGH);
  digitalWrite(motorPinB2, LOW);
}

void turnLeft() {
  digitalWrite(motorPinA1, HIGH);
  digitalWrite(motorPinA2, LOW);
  digitalWrite(motorPinB1, LOW);
  digitalWrite(motorPinB2, LOW);
}

void turnRight() {
  digitalWrite(motorPinA1, LOW);
  digitalWrite(motorPinA2, LOW);
  digitalWrite(motorPinB1, HIGH);
  digitalWrite(motorPinB2, LOW);
}

void stopMoving() {
  digitalWrite(motorPinA1, LOW);
  digitalWrite(motorPinA2, LOW);
  digitalWrite(motorPinB1, LOW);
  digitalWrite(motorPinB2, LOW);
}

void goBackwards(long vel) {
  analogWrite(motorEnablePinA, vel);
  analogWrite(motorEnablePinB, vel);
  digitalWrite(motorPinA1, LOW);
  digitalWrite(motorPinA2, HIGH);
  digitalWrite(motorPinB1, LOW);
  digitalWrite(motorPinB2, HIGH);
}
