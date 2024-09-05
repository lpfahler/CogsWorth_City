// Day 2 Code for Cogsworth City Adventure Kit
// Inventr.io
// Toggle an LED with a pushbutton switch
// I used an external pull-down resistor as shown in lessons circuit diagram
//
// Lori Pfahler
// August 2024

// pins for LED and button
int greenLED = 13;
int button = 2;
// variable to track if the button is pressed or not
int buttonState = LOW;

void setup() {
  pinMode(greenLED, OUTPUT);
  // used external pulldown resistor (10k ohm)
  // Pressed = HIGH, Not Pressed = LOW
  pinMode(button, INPUT);  
}

void loop() {
  // read button state
  buttonState = digitalRead(button);
  // if button pressed - turn LED on
  if (buttonState == HIGH) {
    digitalWrite(greenLED, HIGH);
  }
  // if button is not pressed - turn LED off
  else {
    digitalWrite(greenLED, LOW);
  }

}
