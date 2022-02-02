

int motorEnablePinA = 11;
int motorEnablePinB = 3;

int motorPinA1 = 10;
int motorPinA2 = 7;
int motorPinB1 = 12;
int motorPinB2 = 4;

int echoPin = 5;
int trigPin = 6;


void setup() {

  // motors
  pinMode(motorEnablePinA, OUTPUT);
  pinMode(motorEnablePinB, OUTPUT);
  pinMode(motorPinA1, OUTPUT);
  pinMode(motorPinA2, OUTPUT);

  // sensors
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);

  digitalWrite(trigPin, LOW);




  Serial.begin(9600);
}

void loop() {  
  // add your code here
    

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
