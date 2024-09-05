// Day 7 Code for Cogsworth City Adventure Kit
// Inventr.io
//
// Used internal pull-up resistors via arduino code 
// rather than using external pull-down resistors as 
// shown in circuit diagram in Lesson.
// This version uses a potentiometer to adjust led brightness
//
// Lori Pfahler
// September 2024

// pins for buttons, LEDS, and photoresistor
int greenButton = 2;
int blueButton = 3;
int redButton = 4;
// the pins for LEDs must be PWM pins, pins with ~ next to the number
// to use analogWrite() to control brightness of LED
int greenLED = 9;
int blueLED = 10;
int redLED = 11;
int potPin = A0;  // must be connected analog pin (A0-A5)

// variables
// used to track if buttons have been pressed
int greenState; 
int blueState;
int redState;
// current value from potentiometer
int potVal;
int ledBrightness = 0;

void setup() {
  // setup LEDs as outputs
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(redButton, OUTPUT);
  // setup button switches with internal pull-up resistors
  // NOT PRESSED = HIGH, PRESSED = LOW
  // So original code has to be reversed on HIGH/LOWS for buttons
  pinMode(greenButton, INPUT_PULLUP);
  pinMode(blueButton, INPUT_PULLUP);
  pinMode(redButton, INPUT_PULLUP);
  // start serial monitor so we can print info to it
  Serial.begin(9600);
}

void loop() {
  // read button states
  greenState = digitalRead(greenButton);
  blueState = digitalRead(blueButton);
  redState = digitalRead(redButton);
  // read light level from photoresistor
  potVal = analogRead(potPin);

  // map potentiometer value to brightness scale
  ledBrightness = map(potVal, 0, 1023, 0, 255);

  // green LED code:
  if (greenState == LOW) {
    // turn of green LED to appropriate brightness level if green button pressed
    analogWrite(greenLED, ledBrightness);
  }
  else {
    // otherwise turn green LED off
    analogWrite(greenLED, 0);
  }

  // blue LED Code:
  if (blueState == LOW) {
    // turn of blue LED to appropriate brightness level if blue button pressed
    analogWrite(blueLED, ledBrightness);
  }
  else {
    // otherwise turn blue LED off
    analogWrite(blueLED, 0);
  }

  // red LED Code:
  if (redState == LOW) {
    // turn of red LED to appropriate brightness level if red button pressed
    analogWrite(redLED, ledBrightness);
  }
  else {
    // otherwise turn red LED off
    analogWrite(redLED, 0);
  }
  // print results to serial monitor
  Serial.print("Potentiometer Value: ");
  Serial.print(potVal);
  Serial.print(", LED Brightness: ");
  Serial.println(ledBrightness);

  // short delay 
  delay(100);
}
