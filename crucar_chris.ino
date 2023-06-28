
const int yellowMotorSpeedPin = 2;
const int whiteMotorSpeedPin = 3;
const int yellowMotorInput1 = 52;
const int yellowMotorInput2 = 51;
const int whiteMotorInput1 = 22;
const int whiteMotorInput2 = 23;

const int irSensorPin1 = 4;

const int trigPin = 7;
const int echoPin = 8;

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
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
}

void loop() {  
  // add your code here
//  int irSensor1 = digitalRead(irSensorPin1);
//  if (irSensor1 == 0) {
//    goForward(127);
//  }
//  else {
//    stopMoving();
//  }
Serial.println(analogRead(A0));
goForward(255);

}

void goForward(long velocity) {
  analogWrite(yellowMotorSpeedPin, velocity);
  analogWrite(whiteMotorSpeedPin, velocity);
  digitalWrite(yellowMotorInput1, LOW);
  digitalWrite(yellowMotorInput2, HIGH);
  digitalWrite(whiteMotorInput1, LOW);
  digitalWrite(whiteMotorInput2, HIGH);
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

long getUltrasonicTime() {
  // returns time it takes for sonic wave. in microseconds
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin,LOW);
  return pulseIn(echoPin, HIGH);
  
}
