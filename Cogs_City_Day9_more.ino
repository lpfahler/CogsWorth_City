// Day 9 Code for Cogsworth City Adventure Kit
// Inventr.io
// Festival of Lights
// Some fancy sequences of LED lights
//
// Used internal pull-up resistor via arduino code for the button switch
// rather than using external pull-down resistor
// I added a disco mode and an off mode to the available patterns
//
// Lori Pfahler
// August 2024


// pins for LEDs and button switch
// LEDs must be connected to PWM (~) pins
int buttonPin = 2;
int greenLED = 9;
int blueLED = 10;
int redLED = 11;

// variables
int buttonState = HIGH;
int prevButtonState = HIGH;
int mode = 0;
unsigned long currentMillis;
unsigned long previousMillis = 0;
long interval = 100;

void setup() {
  // setup button switch with internal pull-up resistor
  // NOT PRESSED = HIGH, PRESSED = LOW
  // So original code has to be reversed on HIGH/LOWS for button
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  // setup built-in LED connected to Pin 13
  pinMode(LED_BUILTIN, OUTPUT);
  // setup serial monitor; not used
  // Serial.begin(9600);
}

void loop() {
  // millis() function: Returns the number of milliseconds passed since the 
  // Arduino board began running the current program. 
  // This number will overflow (go back to zero), after approximately 50 days.

  // get current milliseconds since start
  currentMillis = millis();
  // read the state of the button
  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW && prevButtonState == HIGH) {
  // button has been pressed
  // use the statement below if you hooked up external pull-down 
  // resistor as shown in the circuit diagram for the lesson
  // if (buttonState == HIGH && prevButtonState == LOW) {


    // move to next mode - module math used to cycle through 0, 1, 2, 3, 4
    mode = (mode + 1) % 5;
    // blink built-in LED to signal that button has been pressed
    digitalWrite(LED_BUILTIN, HIGH);
    delay(200);
    digitalWrite(LED_BUILTIN, LOW);
  }
  // debounce
  delay(50); 
  // reset previous button state
  prevButtonState = buttonState;

  // use switch to call the appropriate LED blinking pattern
  switch(mode) {
    case 0:
      offMode();
      break;
    case 1:
      fireMode(currentMillis);
      break;
    case 2:
      fairyMode(currentMillis);
      break;
    case 3:
      discoMode(currentMillis);
      break;
    case 4:
      steadyMode();
      break;
  }
}


void fireMode(unsigned long currentMillis) {
  // this statement is not needed; previousMillis is define in 
  // the main program and the function keeps setting it back to zero?
  // static unsigned long previousMillis = 0;
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    int brightness1 = random(150, 255);
    int brightness2 = random(100, 200);
    int brightness3 = random(50, 150);
    analogWrite(greenLED, brightness1);
    analogWrite(blueLED, brightness2);
    analogWrite(redLED, brightness3);   
  }
}

void fairyMode(unsigned long currentMillis) {
  int brightness1 = (sin(currentMillis / 200.0) * 127) + 128;
  int brightness2 = (cos(currentMillis / 200.0) * 127) + 128;
  int brightness3 = (sin((currentMillis + 1000) / 200.0) * 127) + 128;
  analogWrite(greenLED, brightness1);
  analogWrite(blueLED, brightness2);
  analogWrite(redLED, brightness3);
}

void steadyMode() {
  analogWrite(greenLED, 255);
  analogWrite(blueLED, 255);
  analogWrite(redLED, 255);
}

// disco mode
void discoMode(unsigned long currentMillis) {
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    analogWrite(greenLED, random(1, 255));
    analogWrite(blueLED, random(1, 255));
    analogWrite(redLED, random(1, 255));
  }
}

// turn LEDs off
void offMode() {
  analogWrite(greenLED, 0);
  analogWrite(blueLED, 0);
  analogWrite(redLED, 0);
}
