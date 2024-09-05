// Day 5 Code for Cogsworth City Adventure Kit
// Inventr.io
// Control two LEDs each with a separate button switch
// Turn the LEDs on with one press then off with the next press
// Make each button toggle the state of the LED with a press
//
// Lori Pfahler
// August 2024

// pins for LEDs and pushbutton switches
int blueLED = 8;
int redLED = 9;
int blueButton = 2;
int redButton = 3;

// variables to track button presses and LED states (on/off)
int curBlueState = HIGH;
int prevBlueState = HIGH;
int curRedState = HIGH;
int prevRedState = HIGH;
int blueLEDState = LOW;
int redLEDState = LOW;


void setup() {
  // setup LEDs
  pinMode(blueLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  // Using external pull-down resistors (10k ohm)
  // NOT PRESSED = LOW, PRESSED = HIGH
  pinMode(blueButton);
  pinMode(redButton);
  // start serial monitor
  Serial.begin(9600);
  // Print to the serial monitor to check status of LEDs
  Serial.print("Blue LED is: ");
  Serial.println(blueLEDState);
  Serial.print("Red LED is: ");
  Serial.println(redLEDState);
}

void loop() {
  // blue button and LED code:
  curBlueState = digitalRead(blueButton);
  // check if button has been pressed
  if (curBlueState != prevBlueState) {
    if (curBlueState == LOW) {
      // button was pressed if state equals LOW
      // switch LED state using "!" NOT operater
      blueLEDState = !blueLEDState;
      // Print to the serial monitor to check status of blue LED
      Serial.print("Blue LED is: ");
      Serial.println(blueLEDState);
      // change LED to appropriate state
      digitalWrite(blueLED, blueLEDState); 
    }
    delay(50);
  }
  // reset the previous variable
  prevBlueState = curBlueState;


  // Red button and LED code:
  curRedState = digitalRead(redButton);
  if (curRedState != prevRedState) {
    if (curRedState == LOW) {
      redLEDState = !redLEDState;
      Serial.print("Red LED is: :");
      Serial.println(redLEDState);
      digitalWrite(redLED, redLEDState); 
    }
    delay(50);
  }
prevRedState = curRedState;

}
