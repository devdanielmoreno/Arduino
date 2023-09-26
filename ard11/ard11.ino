#define LED_W 10
#define LED_R 11
#define LED_Y 12
#define LED_G 13
#define BOTO_2 2

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

}

void loop() {
  static long slQuanComenca = 0;
  static bool bEnMarxa = false;
  
  if(bBotoPremut(BOTO_2)){
    slQuanComenca = millis();
    bEnMarxa = true;
    digitalWrite(LED_W,HIGH);
  }
  if (bEnMarxa && (millis() - slQuanComenca > 1000)){
    digitalWrite(LED_W,LOW);
    digitalWrite(LED_R,HIGH);
  }
  if (bEnMarxa && (millis() - slQuanComenca > 2000)){
    digitalWrite(LED_R,LOW);
    digitalWrite(LED_Y,HIGH);
  }
  if (bEnMarxa && (millis() - slQuanComenca > 3000)){
    digitalWrite(LED_Y,LOW);
    digitalWrite(LED_G,HIGH);
  }
  if (bEnMarxa && (millis() - slQuanComenca > 4000)){
    digitalWrite(LED_G,LOW);
    digitalWrite(LED_W,HIGH);
    slQuanComenca = millis();
  }
  
}