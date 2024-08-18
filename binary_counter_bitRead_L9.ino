// Lesson #9 Intro to Coding Class
// inventr.io Cogsworth City Kit 
// Binary Counter - Add and Subtract with two button switches
// Six LEDs used to represent 0 - 63 in binary
// Lori Pfahler
// August 2024
//
// This version uses bitRead() function to work with the binary numbers
// Code does the adding or subracting in decimal and then use bitRead() function
// to determine the appropriate state of each LED (0 or 1).
// See bitRead_function_test.ino to understand how bitRead() works
//
// In this version, you can also continue to hold the button and add/sub
// quickly - this differs from the orginal version which does not 
// add or subtract until the button is release.
//
// Uses internal pullup resistors with the button switches


// variables:
// pins 12 and 13 for button switches
int addButton = 12;
int subtractButton = 13;

int curNum = 0; // track current number in decimal form
int addState; // state of Add button: pressed = 0; not pressed = 1 (pullup resistor)
int subState; // state of Subtract button 


void setup() {
  // setup LEDs on pins 2-7, pin 7 represents 1's place (least significant bit), 
  // pin 6 represent 2's place ... pin 2 represents 32's place (most significant bit)
  for (int i = 2; i <= 7; i++) {
    pinMode(i, OUTPUT);
  }
  // setup button switches with internal pull-up resistors
  // one side of button is connected to gnd and other side connected to pin
  // original project uses external pull-down resistor
  pinMode(addButton, INPUT_PULLUP);
  pinMode(subtractButton, INPUT_PULLUP);
  // use serial monitor to check on program operation
  Serial.begin(9600);
  // print starting value of curNum
  Serial.println(curNum);
}

void loop() {
  // read add button status
  addState = digitalRead(addButton);
  if (addState == 0) {
    // delay for debouncing to avoid registering more than one button press per press
    delay(200);
    // go back to zero if curNum is at 63 - change this value if you change the number of LEDs
    if (curNum == 63) {
      curNum = 0;
    }
    else {
      curNum = curNum + 1;
    }
    Serial.println(curNum);
    writeLEDs(curNum);
  }

  // read subtract button status
  subState = digitalRead(subtractButton);
  if (subState == 0) {
    // delay for debouncing and spamming
    delay(200);
    // go back to 63 if curNum is 0 - change this value if you change the number of LEDs
    if (curNum == 0) {
      curNum = 63;
    }
    else {
      curNum = curNum - 1;
    }
    Serial.println(curNum);
    writeLEDs(curNum);
  }

}

void writeLEDs(int number) {
  // loop through LEDs to determine which ones should be ON bit = 1, OFF bit = 0
  // start at LED on Pin 7 (1's place) and move across to Pin 2 (32's place)
  for (int i = 6; i > 0; i--) {
    digitalWrite(i + 1, bitRead(number, abs(i - 6)));
  }
}

