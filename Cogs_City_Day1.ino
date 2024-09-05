// Day 1 Code for Cogsworth City Adventure Kit
// Inventr.io
// Blink an LED - both the built-in LED and an external LED connected to Pin 13
//
// Lori Pfahler
// August 2024



void setup() {
  // setup the LED
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // blink the LED by turning it on (HIGH) and off (LOW)
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
}
