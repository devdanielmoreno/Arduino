#define LED 10
#define BOTO 2
#define TRES_SEGONS 3000

void setup() {
  pinMode(LED,OUTPUT);
  pinMode(BOTO,2);
}

void loop() {
  bool bBoto = digitalRead(BOTO);
  static bool sbBotoPrevi = HIGH; // A l'inici el botó 2 no és premut
  static bool bComptant = false,bEstatLed = LOW;
  static long slQuanComenco = 0;

  if(sbBotoPrevi != bBoto){ // Canvi
    delay(50); // Temps per a passar els rebots
    sbBotoPrevi = bBoto;
    if(bBoto == LOW){ // Està essent premut
      bComptant = true;
      slQuanComenco = millis();
    }else{
      bComptant = false;
    }
  }
  if(bComptant){
    if(millis()-slQuanComenco > TRES_SEGONS){
      bEstatLed = HIGH;
    }
  }else{
    if(bEstatLed){
      delay(3000);
      bEstatLed = LOW;
    }
  }
  digitalWrite(LED,bEstatLed);
}
