#include <Adafruit_NeoPixel.h>

#define PIXEL_PIN 9
#define NUM_PIXELS 3
Adafruit_NeoPixel npStrip(NUM_PIXELS, PIXEL_PIN);


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

long barrierCm = 90;

unsigned long timeSinceDance = millis();

void setup() {

  // motors
  pinMode(motorEnablePinA, OUTPUT);
  pinMode(motorEnablePinB, OUTPUT);
  pinMode(motorPinA1, OUTPUT);
  pinMode(motorPinA2, OUTPUT);

  // sensors
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);

  // why?
  digitalWrite(trigPin, LOW);


  /// neopixel
  npStrip.begin(); 

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
   setStopPixels();
   // stop
   objInWay = true;
   stopMoving();
   delay(100);
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
    setForwardPixels();
    objInWay = false;
    shouldTurnLeft = !shouldTurnLeft;
    goForward(standardSpeed);
    delay(1000);
  }
}


void setForwardPixels() {
  //npStrip.clear();
  //npStrip.show();
  for (int i=0; i<NUM_PIXELS; i++) {
    npStrip.setPixelColor(i, random(0, 255), random(0, 255), random(0, 255));
    delay(100);
    npStrip.show();
  }
  for (int i=NUM_PIXELS-1; i>=0; i--) {
    npStrip.setPixelColor(i, random(0, 255), random(0, 255), random(0, 255));
    delay(100);
    npStrip.show();
  }
}

void setStopPixels() {
  npStrip.clear();
  for (int i=0; i<NUM_PIXELS; i++) {
    npStrip.setPixelColor(i, 255, 0, 0);
  }
  npStrip.show();
}


//void rainbow(uint8_t wait) {
//  uint16_t i, j;
//
//  for(j=0; j<256; j++) {
//    for(i=0; i<NUM_PIXELS; i++) {
//      npStrip.setPixelColor(i, Wheel((i*1+j) & 255));
//    }
//    npStrip.show();
//    delay(wait);
//  }
//}
//
//
//// Input a value 0 to 255 to get a color value.
//// The colours are a transition r - g - b - back to r.
//uint32_t Wheel(byte WheelPos) {
//  if(WheelPos < 85) {
//    return npStrip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
//  } 
//  else if(WheelPos < 170) {
//    WheelPos -= 85;
//    return npStrip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
//  } 
//  else {
//    WheelPos -= 170;
//    return npStrip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
//  }
//}

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
