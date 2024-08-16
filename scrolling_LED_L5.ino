// Lesson #5 Intro to Coding Class
// Scrolling LED
// inventr.io Cogsworth City Kit 
// Lori Pfahler
// August 2024

int timer = 100;

void setup() {
  for (int thisPin = 3; thisPin < 8; thisPin++) {
    pinMode(thisPin, OUTPUT);
  }
}

void loop() {
  for (int thisPin = 3; thisPin < 8; thisPin++) {
    digitalWrite(thisPin, HIGH);
    delay(timer);
    digitalWrite(thisPin, LOW);
  }
  for (int thisPin = 7; thisPin >= 3; thisPin--) {
    digitalWrite(thisPin, HIGH);
    delay(timer);
    digitalWrite(thisPin, LOW);
  }

}
