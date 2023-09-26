#include <RobotController.h>

#define STATE_STOP  0
#define STATE_FAST_FORWARD 1
#define STATE_FORWARD 2
#define STATE_FAST_BACKWARDS 3
#define STATE_BACKWARDS  4
#define STATE_RIGHT 5
#define STATE_LEFT 6

#define N_STEPS 10

void vRunState(byte byCS) {
  switch (byCS) {
    case STATE_STOP: vMotion(0, 0);
      break;
    case STATE_FAST_FORWARD: vMotion(120, 120);
      break;
    case STATE_FORWARD: vMotion(127, 127);
      break;
    case STATE_FAST_BACKWARDS: vMotion(-150, -150);
      break;
    case STATE_BACKWARDS: vMotion(-127, -127);
      break;
    case STATE_RIGHT: vMotion(127, -127);
    delay(1400);
      break;
    case STATE_LEFT: vMotion(-127, 127);
      break;
  }
}

void setup() {
  Serial.begin(115200);
  RobotBegin();
}

void loop() {
   byte byStates[N_STEPS] = {STATE_STOP, STATE_FORWARD, STATE_FAST_FORWARD, STATE_STOP, STATE_BACKWARDS, STATE_FAST_BACKWARDS, STATE_STOP, STATE_RIGHT, STATE_STOP, STATE_LEFT};
  static unsigned long int ulLastMillisView = millis(), ulLastMillisSteps = millis();
  unsigned long int ulNow = millis();
  unsigned long int ulDifView = ulNow - ulLastMillisView, ulDifSteps = ulNow - ulLastMillisSteps;
  static byte byCurrentStep = 0;
  byte byCurrentState = byStates[byCurrentStep];
  bool bBR, bBL, bFSL, bFL, bFC, bFR, bFSR;
  int nUsDist = nUltrasonicCm();

  vIR(&bBR, &bBL, &bFSL, &bFL, &bFC, &bFR, &bFSR);
  Serial.print((bFL)? "W" : "B");
  Serial.print((bFC)? "W" : "B");
  Serial.println((bFR)? "W" : "B");

if(!bFC){
  byCurrentState = STATE_RIGHT;
}else{
  byCurrentState = STATE_FORWARD;
}
vRunState(byCurrentState);
}