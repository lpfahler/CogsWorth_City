// Day 7 Code for Cogsworth City Adventure Kit
// Inventr.io
//
// Included "commented out" code internal pull-up resistors via arduino code
// If you use internal pull-ups, then you  have to switch HIGH to LOW for button states
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


void setup() {
  // setup LEDs as outputs
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(redButton, OUTPUT);
  // setup button switches with external pull-down resistors 
  // as shown in lesson circuit diagram
  // PRESSED = HIGH, NOT PRESSED = LOW
  pinMode(greenButton, INPUT);
  pinMode(blueButton, INPUT);
  pinMode(redButton, INPUT);

  // setup button switches with internal pull-up resistors
  // PRESSED = LOW, NOT PRESSED = HIGH, 
  // The original code has to be reversed on HIGH/LOWS for buttons
  // pinMode(greenButton, INPUT_PULLUP);
  // pinMode(blueButton, INPUT_PULLUP);
  // pinMode(redButton, INPUT_PULLUP);

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
  // use map() function to convert 0-1023 result from photoresistor to 0-255 scale 
  // for LED brightness
  ledBrightness = map(lightLevel, 0, 1023, 0, 255);


  // green LED code:
  if (greenState == HIGH) {
    // turn of green LED to appropriate brightness level if green button pressed
    analogWrite(greenLED, ledBrightness);
  }
  else {
    // otherwise turn green LED off
    analogWrite(greenLED, 0);
  }

  // blue LED Code:
  if (blueState == HIGH) {
    // turn of blue LED to appropriate brightness level if blue button pressed
    analogWrite(blueLED, ledBrightness);
  }
  else {
    // otherwise turn blue LED off
    analogWrite(blueLED, 0);
  }

  // red LED Code:
  if (redState == HIGH) {
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
