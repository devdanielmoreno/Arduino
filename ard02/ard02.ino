void setup() {
  Serial.begin(115200);
  Serial.println(__FILE__);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {

  digitalWrite(10,HIGH);
  delay(200);
  digitalWrite(10,LOW);
  digitalWrite(11,HIGH);
  delay(200);
  digitalWrite(11,LOW);
  digitalWrite(12,HIGH);
  delay(200);
  digitalWrite(12,LOW);
  digitalWrite(13,HIGH);
  delay(200);
  digitalWrite(13,LOW);
}
