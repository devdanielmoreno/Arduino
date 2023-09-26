#define BOTO_2 2
#define BOTO_3 3
#define LED_W 10
#define LED_R 11
#define LED_Y 12
#define LED_G 13
#define UNSEG 1000

bool bBoto(int nQuin) {
  return !digitalRead(nQuin);
}

void vEncenLed(int nQuin, bool bEstat){
  digitalWrite(nQuin, bEstat);
}

void vEncenLedUnic(int nQuin){
  digitalWrite(LED_W, LOW);
  digitalWrite(LED_R, LOW);
  digitalWrite(LED_Y, LOW);
  digitalWrite(LED_G, LOW);
  digitalWrite(nQuin, HIGH);
}

void setup() {
  Serial.begin(115200);
  Serial.println(__FILE__);
  pinMode(BOTO_2, INPUT);
  pinMode(BOTO_3, INPUT);
  pinMode(LED_W, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_Y, OUTPUT);
  pinMode(LED_G, OUTPUT);
}
void loop(){
  static int n=LED_W;
  static long slPrevi = 0;
  long lAra = millis();
  static bool bRun = false;

  if(bBoto(BOTO_2)){
    bRun = true;
  }
  if(bBoto(BOTO_3)){
    bRun = false;
  }
    if(bRun){
      if(lAra-slPrevi > UNSEG){
          slPrevi = lAra;
          Serial.println(n);
          vEncenLedUnic(n);
          n++;
          if(n > LED_G){
            n = LED_W;
          }
      }
    }
}