#include <Servo.h>

// PINS 
const int echoPin = 39;
const int triggerPin = 41;
const int servoPinRight = 6;
const int servoPinLeft = 7;


Servo leftServo; 
Servo rightServo;

void setup() {
  Serial.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(triggerPin, OUTPUT);
  leftServo.attach(servoPinLeft);
  rightServo.attach(servoPinRight);
}

void loop() {

  // check ultrasonic sensor
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(triggerPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  long inches = duration/74 /2;

  Serial.println(inches);
  
  // if inches < 5, turn around
  if (inches < 5) {
    goBackwards();
    delay(500);
    turnRight();
    delay(2000);
  }
  else {
    goForwards();
  }
 
}




// TODO: edit numbers below in write functions
void goForwards() {
  leftServo.write(180);
  rightServo.write(0);
}

void goBackwards() {
  leftServo.write(0);
  rightServo.write(180);
}

void turnRight() {
  leftServo.write(180); 
  rightServo.write(180); 
}

void stop() {
  leftServo.write(90);
  rightServo.write(90);
}
