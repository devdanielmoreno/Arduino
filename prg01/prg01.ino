void setup() {
  Serial.begin(115200);
  Serial.println(__FILE__);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  }

void loop() {
  static int n=0;
/*
  digitalWrite(10,HIGH);
  Serial.print("ALT ");
  Serial.println(n);
  delay(1000);
  n++;
  digitalWrite(10,LOW);
  Serial.print("BAIX ");
  Serial.println(n);
  delay(1000);*/
  switch(n){
    case 0: 
      digitalWrite(13,HIGH);
      digitalWrite(12,LOW);
      digitalWrite(11,LOW);
      digitalWrite(10,LOW);
      break;
    case 1: 
      digitalWrite(13,LOW);
      digitalWrite(12,HIGH);
      digitalWrite(11,LOW);
      digitalWrite(10,LOW);
      break;
    case 2: 
      digitalWrite(13,LOW);
      digitalWrite(12,LOW);
      digitalWrite(11,HIGH);
      digitalWrite(10,LOW);
      break;
    case 3: 
      digitalWrite(13,LOW);
      digitalWrite(12,LOW);
      digitalWrite(11,LOW);
      digitalWrite(10,HIGH);
      break;
  }
  Serial.println(n);
  delay(500);
  n++;
  if(n>3){
    n=0;    
  }
}
