#define LED_1 10
#define LED_2 12
#define LED_3 11
#define LED_4 13
#define BOTO_2 2
#define BOTO_3 3

void setup() {
  Serial.begin(115200);
  Serial.println(__FILE__);
  pinMode(LED_1,OUTPUT);
  pinMode(BOTO_2,INPUT);
  pinMode(LED_2,OUTPUT);
  pinMode(LED_3,OUTPUT);
  pinMode(LED_4,OUTPUT);


}

void loop() {
  bool bA = digitalRead(BOTO_2);
  bool bB = digitalRead(BOTO_3);
  bool bF = (!bA && bB) || (bA && !bB);

  digitalWrite(LED_4,bF);
}
