#define BOTO3 3
#define LED12 12
#define BOTO2 2
#define LED13 13
#define LED11 11
#define BOTOA4 18
#define LED10 10
#define BOTOA5 19

void setup() {
  pinMode(LED13, OUTPUT);
  pinMode(BOTO2, INPUT);
  pinMode(LED12, OUTPUT);
  pinMode(BOTO3, INPUT);
  pinMode(LED11, OUTPUT);
  pinMode(BOTOA5, INPUT);
  pinMode(LED10, OUTPUT);
  pinMode(BOTOA4, INPUT);
}

void loop() {
  if(!digitalRead(BOTO2))
    digitalWrite(LED13,HIGH);
  if(!digitalRead(BOTO3))
    digitalWrite(LED12,HIGH);
  if(!digitalRead(BOTOA5))
    digitalWrite(LED11,HIGH);
  if(!digitalRead(BOTOA4))
    digitalWrite(LED10,HIGH); 
}
