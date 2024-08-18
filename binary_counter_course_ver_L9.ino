 /*
* Binary Counter
*
* This example uses 6 LEDs to count in binary from 0 to 63.
*
* There are two buttons. One button will add 1 to the count
* each time it is pressed, while the other button will
* subtract 1 from the count.
*
* The 6 LEDs are connected to digital pins 2 through 7.
* The "add" button is connected to digital pin 12.
* The "subtract" button is connected to digital pin 13.
*
*/
 
// Here we set some global constants
// In other words, variables whose values do not change
 
const int add_button=12,
          subtract_button=13,
          NumberOfBits=6;
 
         
 
// Here we set some global non-constant variables.
// In other words, variables whose values can change throughout execution.
 
int OurSixBitNumber[]={0,0,0,0,0,0}, LED_Selector, ButtonIsPressed;
 
void setup() {
 
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  // NOTE: use interal pullup resistor so pressed = 0 and not pressed = 1
  pinMode(add_button, INPUT_PULLUP);
  pinMode(subtract_button, INPUT_PULLUP);
 
}
 
void loop() {
 
  ButtonIsPressed = digitalRead(add_button); // Equals 0 if button being pressed, 1 if not.  
  if(ButtonIsPressed == 0) { addButtonPressed(); }
 
  delay(100); // To prevent spamming
 
  ButtonIsPressed = digitalRead(subtract_button);
  if(ButtonIsPressed == 0) { subButtonPressed(); }
 
  resetSelector();
  writeLEDs();
 
}
 
/**************************/
 
/*
 
/*  ADDITIONAL FUNCTIONS:
 
/*     addButtonPressed()
/*     subButtonPressed()
/*     writeLEDs()
/*     resetSelector()
/*
/**************************/
 
void addButtonPressed() {
 
  while(digitalRead(add_button) == 0) { /* do nothing until let go of button */ } //AKA: Add Button being held down still
 
  delay(100); //Delay for 100 milliseconds to prevent spamming of buttons
  resetSelector();
 
  while(LED_Selector >= 0 && ButtonIsPressed != 1)
  {
    if(OurSixBitNumber[LED_Selector] == 1)
    {
      OurSixBitNumber[LED_Selector] = 0;
      LED_Selector--;
    }
    else
    {
      OurSixBitNumber[LED_Selector] = 1;
      ButtonIsPressed = 1;
    }
  }
}
 
void subButtonPressed() {
 
  while(digitalRead(subtract_button) == 0) { /* do nothing until let go of button */ } //AKA: Subtract Button being held down still
 
  delay(100); //Delay for 100 milliseconds to prevent spamming of buttons
 
  resetSelector();
 
  while(LED_Selector >= 0 && ButtonIsPressed != 1) // While the LED Selector is greater than zero and the subtract button is 1, then starting from the last LED to the first, do the following:
 
  {
    if(OurSixBitNumber[LED_Selector] == 0) // IF that LED is OFF, turn it on, and continue to the next LED (aka the one before because backwards)
    {
      OurSixBitNumber[LED_Selector] = 1; // Turning LED on
      LED_Selector--; // Continuing to the next (aka the one before because going backwards) LED
    }
    else // ELSE (the LED is ON) turn off the LED and set the button state to NOT pressed.
    {
      OurSixBitNumber[LED_Selector] = 0; // Turn it off
      ButtonIsPressed = 1; // Reset Button State
    }
  }
}
 
void writeLEDs() {
 
  for(int temp = 0; temp < NumberOfBits; temp++)
  {
    if(OurSixBitNumber[temp] == 1)
    {
      digitalWrite(NumberOfBits - temp + 1, HIGH);
    }
    else
    {
      digitalWrite(NumberOfBits - temp + 1, LOW);
    }
    LED_Selector--;
  }
}
 
void resetSelector() {
 LED_Selector = NumberOfBits - 1; // because arrays start at 0;
}
