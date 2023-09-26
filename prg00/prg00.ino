void setup() {
  Serial.begin(115200);
  Serial.println(__FILE__);
  pinMode(10, OUTPUT);
}

void loop() {
  static int n=0;

  digitalWrite(10,HIGH);
  Serial.print("ALT ");
  Serial.println(n);
  delay(1000);
  n++;
  digitalWrite(10,LOW);
  Serial.print("BAIX ");
  Serial.println(n);
  delay(1000);
  n++;
  if(n>3){
    n=0;    
  }
}
