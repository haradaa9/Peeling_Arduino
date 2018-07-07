#include <VarSpeedServo.h>

//rotation servo
VarSpeedServo rotateServo;

//seasow servo
VarSpeedServo seasowServo;


int rotatePos = 0;

void seasowCtl(int rotatePos) {
  //control seasow with seasowServo
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

void setup() {
  // put your setup code here, to run once:
  //servo init
  rotateServo.attach(9, 530, 2330);
  rotateServo.write(90);
  seasowServo.attach(8, 570, 2370);
  seasowServo.write(90);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(rotatePos = 180; rotatePos >= 50; rotatePos = rotatePos -10){
    rotateServo.write(rotatePos, 15, true);
    seasowCtl(rotatePos);
  }
  while(1);
}

