// Lesson #2 Intro to Coding Class
// traditional code to blink external LED
// inventr.io Cogsworth City Kit 
// Lori Pfahler
// August 2024

int LEDPin = 8;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LEDPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(LEDPin, HIGH);
  delay(500);
  // digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(LEDPin, LOW);
  delay(500);
}
