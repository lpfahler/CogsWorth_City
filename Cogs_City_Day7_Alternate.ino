// Day 7 Code for Cogsworth City Adventure Kit
// Inventr.io
//
// Used internal pull-up resistors via arduino code 
// rather than using external pull-down resistors as 
// shown in circuit diagram in Lesson.
// This version used the min and max value read by the photoresistor to 
// setup a more clear difference in dimming
//
// Lori Pfahler
// August 2024

// pins for buttons, LEDS, and photoresistor
int greenButton = 2;
int blueButton = 3;
int redButton = 4;
// the pins for LEDs must be PWM pins, pins with ~ next to the number
// to use analogWrite() to control brightness of LED
int greenLED = 9;
int blueLED = 10;
int redLED = 11;
int photoPin = A0;  // must be connected analog pin (A0-A5)

// variables
// used to track if buttons have been pressed
int greenState; 
int blueState;
int redState;
// current light level from photoresistor
int lightLevel;
int ledBrightness = 0;

// approx min level for your room - change this as needed
// get this by covering the photoresistor with your finger
int minLightLevel = 760; 
// approx max level for your room - change this as needed
// get this by observing the light level from your photoresitor
// without anything blocking the light in the room 
int maxLightLevel = 950;  

// divide the range of light levels by 3 to create three ranges for the ledBrightness
// variable
float lightLevelThird = (maxLightLevel - minLightLevel)/3;

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
  lightLevel = analogRead(photoPin);

  // Use only three levels of brightness since only large changes are  
  // perceptible to the human eye and LED brightness perception is nonlinear
  if (lightLevel < (minLightLevel + lightLevelThird)) {
    // low level of LED brightness
    ledBrightness = 5;
  }
  else if (lightLevel > (maxLightLevel - lightLevelThird)) {
    // high level of LED brightness
    ledBrightness = 255;
  }
  else {
    // mediom level of LED brightness
    ledBrightness = 50;
  }

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
  Serial.print("Light Level: ");
  Serial.print(lightLevel);
  Serial.print(", LED Brightness: ");
  Serial.println(ledBrightness);

  // short delay 
  delay(1000);
}
