#define BOTO 2
#define LED 10
void setup() {
  pinMode(BOTO, INPUT);
  pinMode(LED, OUTPUT);


}

void loop() {
  static bool sbEstatLed = LOW;
  bool bBoto = digitalRead (BOTO);
  static bool sbBotoPrevi = HIGH;

  if (sbBotoPrevi != bBoto){ //canvi
    delay (20);
    sbBotoPrevi = bBoto; //acualizo al passat
    if (bBoto==LOW){
      sbEstatLed = !sbEstatLed;
    }
  }
  digitalWrite(LED,sbEstatLed);
}