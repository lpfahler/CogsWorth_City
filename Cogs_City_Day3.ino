// Day 3 Code for Cogsworth City Adventure Kit
// Inventr.io
// Flash three LEDs in a sequence
//
// Lori Pfahler
// August 2024

// pins for LEDs
int redLED = 8;
int greenLED = 9;
int blueLED = 10;

void setup() {
  // setup LEDs
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
}

void loop() {
  // blink red LED
  digitalWrite(redLED, HIGH);
  delay(500);
  digitalWrite(redLED, LOW);

  // blink green LED
  digitalWrite(greenLED, HIGH);
  delay(500);
  digitalWrite(greenLED, LOW);

  // blink blue LED
  digitalWrite(blueLED, HIGH);
  delay(500);
  digitalWrite(blueLED, LOW);
}
