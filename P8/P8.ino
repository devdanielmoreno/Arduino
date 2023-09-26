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
    case STATE_FAST_FORWARD: vMotion(255, 255);
      break;
    case STATE_FORWARD: vMotion(70, 70);
      break;
    case STATE_FAST_BACKWARDS: vMotion(-255, -255);
      break;
    case STATE_BACKWARDS: vMotion(-110, -110);
      break;
    case STATE_RIGHT: vMotion(127, -127);
      break;
    case STATE_LEFT: vMotion(-127, 127);
      break;
  }
}

void setup() {
  Serial.begin(115200);
  RobotBegin();
  while (!digitalRead(BUTTON_START));
  Serial.println("Waiting for 2 seconds.");
  delay(2000);
}

void loop() {
  byte byStates[N_STEPS] = {STATE_STOP, STATE_FORWARD, STATE_FAST_FORWARD, STATE_STOP, STATE_BACKWARDS, STATE_FAST_BACKWARDS, STATE_STOP, STATE_RIGHT, STATE_STOP, STATE_LEFT};
  static unsigned long int ulLastMillis = millis();
  unsigned long int ulNow = millis();
  unsigned long int ulDif = ulNow - ulLastMillis;
  int nUsDist = nUltrasonicCm();
  static byte byCurrentStep = 0;
  static unsigned long int ulLastMillisView = millis(), ulLastMillisSteps = millis();
  unsigned long int ulDifView = ulNow - ulLastMillisView, ulDifSteps = ulNow - ulLastMillisSteps;
  byte byCurrentState = byStates[byCurrentStep];
  bool bBR, bBL, bFSL, bFL, bFC, bFR, bFSR;
  vIR(&bBR, &bBL, &bFSL, &bFL, &bFC, &bFR, &bFSR);

     if (bFL == 0){
    vMotion(-150, 200);
    }
     if (bFR == 0){
    vMotion(200, -150);
    }
    if (bFC == 0){
    vMotion(250, 250);
     }
    else if (bFL == 0 and bFC == 0 and bFL == 0 and (bFSL == 0 or bFSR == 0)){
    vMotion(0, 0);
      }

}