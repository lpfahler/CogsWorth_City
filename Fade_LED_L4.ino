// Lesson #4 Intro to Coding Class
// Fade an LED
// inventr.io Cogsworth City Kit 
// Lori Pfahler
// August 2024

int ledPin = 9;
int brightness = 0;
int fadeAmount = 5;
int delayTime = 10;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  analogWrite(ledPin, brightness);
  brightness = brightness + fadeAmount;
  if (brightness <= 0 or brightness >= 255)
  {
    fadeAmount = -fadeAmount;
  }
  delay(delayTime);
}
