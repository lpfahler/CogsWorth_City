// Lesson #3 Intro to Coding Class
// Pushbutton Control of LED
// inventr.io Cogsworth City Kit 
// Lori Pfahler
// August 2024

int buttonPin = 2;
int ledPin = 8;
int buttonState = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH){
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }

}