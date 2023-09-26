#define LED 10

void setup() {
  // set the digital pin as output:
  pinMode(LED, OUTPUT);
}
void loop() {
  static unsigned long previousMillis = 0; // will store last time LED was updated
  static int ledState = LOW; // ledState used to set the LED
  long interval = 1000; // interval at which to blink (milliseconds)
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // set the LED with the ledstate of the variable:
    digitalWrite(LED, ledState);
  }
}