// Lesson #8 Intro to Coding Class
// LED Dice
// 
// inventr.io Cogsworth City Kit 
// Lori Pfahler
// August 2024

// pins for LEDs and button switch
int first = 8;
int second = 9;
int third = 10;
int fourth = 11;
int fifth = 12;
int sixth = 13;
int button = 2;
// variable to check if button is pressed
int pressed = 0;
int result;

void setup() {
// setup LEDs are outputs
  for (int i = first; i <= sixth; i++) {
    pinMode(i, OUTPUT);
  }
  // setup pushbutton with internal pullup resistor
  pinMode(button, INPUT_PULLUP);

  // initalize random seed using noise on analog pin A0 (not connected
  randomSeed(analogRead(A0));
  // turn on serial monitor
  Serial.begin(9600);
}


void buildUpTension() {
  // have LED lights chase back and forth one time

  // up the LEDs Pins 8-13
  for (int i = first; i <= sixth; i++) {
    if (i != first){
      digitalWrite(i - 1, LOW);
    }
    digitalWrite(i, HIGH);
    delay(100);
  }
  // down the LEDS Pin 13 - 8
  for (int i = sixth; i  >= first; i--) {
    if (i != sixth) {
      digitalWrite(i + 1, LOW);
    }
    digitalWrite(i, HIGH);
    delay(100);
  }

}

void showNumber(int number) {
  // light the LEDs for the provided 'number'
  // One LED will always be needed
  digitalWrite(first, HIGH);
  // proceed through the 2-6 to see how many to turn on
  if (number >= 2) {
    digitalWrite(second, HIGH); 
  }
  if (number >= 3) {
    digitalWrite(third, HIGH);
  }
  if (number >= 4) {
    digitalWrite(fourth, HIGH);
  }
  if (number >= 5) {
    digitalWrite(fifth, HIGH);
  }
  if (number == 6) {
    digitalWrite(sixth, HIGH); 
  }
}

int throwDice() {
  int randNumber = random(1, 7);
  return randNumber;
}

void setAllLEDs(int value) {
  // value can be 0/LOW for all off and 1/HIGH for all on
  for (int i = first; i <= sixth; i++) {
    digitalWrite(i, value);
  }
}


void loop() {
  // if button is pressed - throw the dice
  pressed = digitalRead(button);
  if (pressed == LOW) {
    buildUpTension();
    result = throwDice();
    Serial.println(result);
    showNumber(result);
    delay(2000);
    setAllLEDs(LOW);
  }
}
