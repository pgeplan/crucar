
int yellowMotorSpeedPin = 2;
int whiteMotorSpeedPin = 3;

int yellowMotorInput1 = 52;
int yellowMotorInput2 = 51;
int whiteMotorInput1 = 22;
int whiteMotorInput2 = 23;

int irSensorPin1 = 4;


void setup() {
  Serial.begin(9600);
  
  // motors
  pinMode(yellowMotorSpeedPin, OUTPUT);
  pinMode(whiteMotorSpeedPin, OUTPUT);
  pinMode(yellowMotorInput1, OUTPUT);
  pinMode(yellowMotorInput2, OUTPUT);
  pinMode(whiteMotorInput1, OUTPUT);
  pinMode(whiteMotorInput2, OUTPUT);
  
  // sensors
  pinMode(irSensorPin1, INPUT);
  
}

void loop() {  
  // add your code here
  int irSensor1 = digitalRead(irSensorPin1);
  if (irSensor1 == 0) {
    goForward(127);
  }
  else {
    stopMoving();
  }

}

void goForward(long velocity) {
  analogWrite(yellowMotorSpeedPin, velocity);
  analogWrite(whiteMotorSpeedPin, velocity);
  digitalWrite(yellowMotorInput1, HIGH);
  digitalWrite(yellowMotorInput2, LOW);
  digitalWrite(whiteMotorInput1, HIGH);
  digitalWrite(whiteMotorInput2, LOW);
}

void turnLeft() {
  digitalWrite(yellowMotorInput1, HIGH);
  digitalWrite(yellowMotorInput2, LOW);
  digitalWrite(whiteMotorInput1, LOW);
  digitalWrite(whiteMotorInput2, LOW);
}

void turnRight() {
  digitalWrite(yellowMotorInput1, LOW);
  digitalWrite(yellowMotorInput2, LOW);
  digitalWrite(whiteMotorInput1, HIGH);
  digitalWrite(whiteMotorInput2, LOW);
}

void stopMoving() {
  digitalWrite(yellowMotorInput1, LOW);
  digitalWrite(yellowMotorInput2, LOW);
  digitalWrite(whiteMotorInput1, LOW);
  digitalWrite(whiteMotorInput2, LOW);
}

void goBackwards(long velocity) {
  analogWrite(yellowMotorSpeedPin, velocity);
  analogWrite(whiteMotorSpeedPin, velocity);
  digitalWrite(yellowMotorInput1, LOW);
  digitalWrite(yellowMotorInput2, HIGH);
  digitalWrite(whiteMotorInput1, LOW);
  digitalWrite(whiteMotorInput2, HIGH);
}
