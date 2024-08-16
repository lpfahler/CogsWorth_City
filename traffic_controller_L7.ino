// Lesson #7 Intro to Coding Class
// Traffic Controller (very basic)
// 
// inventr.io Cogsworth City Kit 
// Lori Pfahler
// August 2024

int redPin  = 10;
int yellowPin = 9;
int greenPin = 8;


void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);

}

void loop() {

  // turn off red and turn on green
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, HIGH);
  delay(3000);

  // turn off green and turn on yellow
  digitalWrite(greenPin, LOW);
  digitalWrite(yellowPin, HIGH);
  delay(3000);

  // turn off yellow and turn on red
  digitalWrite(redPin, HIGH);
  digitalWrite(yellowPin, LOW);
  delay(5000);


}
