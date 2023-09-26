#define LED 10
#define BOTO 2

void setup() {
  Serial.begin(115200);
  Serial.println(__FILE__);
  pinMode(LED, OUTPUT);
  pinMode(BOTO, INPUT);
}

void loop() {
  bool bEstat2 = !digitalRead(BOTO);

  digitalWrite(LED,bEstat2);
  
}
