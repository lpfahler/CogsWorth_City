// Day 5 Code for Cogsworth City Adventure Kit
// Inventr.io
// Pushbutton Switch Control of LED
// Turn the LED on with one press then off with the next press
// Just one LED (blueLED) and one button switch (buttonPin)
// This approach will not change the ledState until the 
// button is let go of
//
// Lori Pfahler
// September 2024

int blueLED = 12;
int buttonPin = 2;

// variables to track button presses and LED state (on/off)
int buttonState = LOW;
int lastButtonState = LOW;
int ledState = LOW;

void setup() {
  // setup LEDs
  pinMode(blueLED, OUTPUT);
  // setup button switch with external pull-down resistor
  // NOT PRESSED = LOW, PRESSED = HIGH
  pinMode(buttonPin, INPUT);
  // start serial monitor
  Serial.begin(9600);
  // Print to the serial monitor to check status of LED
  Serial.print("LED is: ");
  Serial.println(ledState);
}

void loop() {
  // blue button and LED code:
  buttonState = digitalRead(buttonPin);
  // change ledState if the button was pressed i.e. lastButtonState==HIGH
  // and the current value of the button is now i.e. buttonState==LOW
  // the button was pushed and let go of
  if (buttonState == LOW && lastButtonState == HIGH){
  // use the if statement below if you want it to change 
  // ledState on "down" press
  // if (buttonState == HIGH && lastButtonState == LOW){
    // switch LED state using "!" NOT operater
    ledState = !ledState;
    // change LED to appropriate state
    digitalWrite(blueLED, ledState); 
    // Print to the serial monitor to check status of the LED
    Serial.print("LED is: ");
    Serial.println(ledState);
  }
  // reset the last button state variable
  lastButtonState = buttonState;
  delay(50);
}
