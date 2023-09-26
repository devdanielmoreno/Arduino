#define BOTO_2 2
#define BOTO_3 3
#define LED_W 10

bool bBoto(int nQuin) {
  return !digitalRead(nQuin);
}

void vEncenLed(int nQuin, bool bEstat){
  digitalWrite(nQuin, bEstat);
}

void vEncenLedUnic(int nQuin){
  digitalWrite(nQuin, HIGH);
}

void setup() {
  pinMode(BOTO_2, INPUT);
  pinMode(BOTO_3, INPUT);
  pinMode(LED_W, OUTPUT);
}
void loop() {
  if(bBoto(2)){
    vEncenLed(10, HIGH);
  }
  if(bBoto(3)){
    vEncenLed(10, LOW);
  }
}