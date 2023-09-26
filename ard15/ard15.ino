#define BOTO2 2
#define LED_13 13

void setup() {
  pinMode(LED_13, OUTPUT);
  pinMode(BOTO2, INPUT);
}

void loop() {
  bool bA = digitalRead(BOTO2);
  bool bF = !bA;

  digitalWrite(LED_13,bF);
}
