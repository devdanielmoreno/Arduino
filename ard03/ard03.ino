void setup() {
  Serial.begin(115200);
  Serial.println(__FILE__);
  pinMode(10, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  bool bEstat2 = !digitalRead(2);

  digitalWrite(10,bEstat2);
  
}
