#define LED_W 10
#define LED_R 11
#define LED_Y 12
#define LED_G 13
#define BOTO_2 2
#define BOTO_3 3
#define BOTO_A5 A5
#define BOTO_A4 A4

bool bBotoPremut(int nQuin){
  delay(50);
  return !digitalRead(nQuin);
}

void setup() {
  pinMode(LED_W, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_Y, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(BOTO_2, INPUT); 
  pinMode(BOTO_3, INPUT); 
  pinMode(BOTO_A5, INPUT); 
  pinMode(BOTO_A4, INPUT); 
}

void loop() {
  static bool bFlag1 = false,bFlag2 = false;
  static long slQuanComenca = 0;
  long lInterval = 3000;
  static bool sbEstatLed = LOW;

  if(bBotoPremut(BOTO_2)){
    bFlag2 = false;
    if(!bFlag1){
      bFlag1 = true;
      slQuanComenca = millis();
    }
    if(millis() - slQuanComenca  >= lInterval){
      sbEstatLed = HIGH;
    }
  }else{
    bFlag1 = false;
    if(!bFlag2){
      bFlag2 = true;
      slQuanComenca = millis();
    }
    if(millis() - slQuanComenca  >= lInterval){
      sbEstatLed = LOW;
    }    
  }
  digitalWrite(LED_W,sbEstatLed);
  delay(5);
}
