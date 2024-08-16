// Lesson #2 Intro to Coding Class
// traditional code to blink internal LED
// inventr.io Cogsworth City Kit 
// Lori Pfahler
// August 2024


void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
}
