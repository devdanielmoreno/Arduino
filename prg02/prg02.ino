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

  digitalWrite(13,n==0);
  digitalWrite(12,n==1);
  digitalWrite(11,n==2);
  digitalWrite(10,n==3);
  Serial.println(n);
  delay(500);
  n++;
  if(n>3){
    n=0;    
  }
}
