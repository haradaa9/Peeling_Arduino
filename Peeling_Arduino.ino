#include <VarSpeedServo.h>

// rotation servo instance
VarSpeedServo rotateServo;
// seasow servo instance
VarSpeedServo seasowServo;

// const arduino pin
const int redPin = 10, greenPin = 11, bluePin = 12;
const int seasowPin = 8, rotatePin = 9;
const int drillPin = 7;

// difinite variable

/*------------color------------*/
void RGB(int red, int green, int blue){
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

void LEDCtl(char color){
  switch(color){
    case 'b':
      RGB(0, 255, 255);
      break;
    case 'r':
      RGB(255, 0, 255);
      break;
    case 'g':
      RGB(255, 255, 0);
      break;
  }
}


/*------------servo------------*/
void seasowCtl(int rotatePos){
  // control seasow with seasowServo
  switch(rotatePos){
    case 50:
      seasowServo.write(68, 15, true);
      break;
    case 60:
      seasowServo.write(69, 15, true);
      break;
    case 70:
      seasowServo.write(69, 15, true);
      break;
    case 80:
      seasowServo.write(69, 15, true);
      break;
    case 90:
      seasowServo.write(69, 15, true);
      break;
    case 100:
      seasowServo.write(69, 15, true);
      break;
    default:
      seasowServo.write(67, 15, true);
  }
  delay(1000);
  seasowServo.write(90, 15, true);
}

/*------------main------------*/
void setup() {
  // put your setup code here, to run once:
  // servo init
  rotateServo.attach(rotatePin, 530, 2330);
  rotateServo.write(90);
  seasowServo.attach(seasowPin, 570, 2370);
  seasowServo.write(90);
  // LED init
  LEDCtl('r');
}

void loop() {
  // put your main code here, to run repeatedly:
  // start func
  digitalWrite(drillPin, HIGH);
  LEDCtl('g');

  // Servo func
  for(int rotatePos = 180; rotatePos >= 60; rotatePos = rotatePos - 10){
    LEDCtl('g');
    rotateServo.write(rotatePos, 15, true);
    LEDCtl('b');
    seasowCtl(rotatePos);
    LEDCtl('g');
  }

  // finish func
  rotateServo.write(90, 15, true);
  digitalWrite(drillPin, LOW);
  LEDCtl('r');
  while(1);
}




