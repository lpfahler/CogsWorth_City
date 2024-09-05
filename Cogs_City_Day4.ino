// Day 4 Code for Cogsworth City Adventure Kit
// Inventr.io
// Photoresistor control of an LED
//
// Made some changes to observe initial light level in room; a simple calibration.
// Code now looks for changes from the initial light level beyond the 
// threshold value (adjust as needed for your situation).
//
// Lori Pfahler
// August 2024

// pins for photoresistor and LED
int photoPin = A0;
int ledPin = 12;

// variables
int lightLevel = 0;  // current light level in room
int initLightLevel;  // light level at start of program/device
int threshold = 100;  // threshold setting for light change detection

void setup() {
  // setup LED
  pinMode(ledPin, OUTPUT);
  // start serial monitor to print status to monitor
  Serial.begin(9600);
  // get initial light level in room
  initLightLevel = analogRead(photoPin);
}

void loop() {
  // read light level from photoresistor (0-1023 scale)
  lightLevel = analogRead(photoPin);
  // print current light level to serial monitor
  Serial.println(lightLevel);

  // check if light level has been reduced from initial by the threshold setting
  if (lightLevel < initLightLevel - threshold) {
    // if current light level is < (initLightLevel - threshold), turn LED on
    digitalWrite(ledPin, HIGH);
  }
  else {
    // otherwise turn LED off
    digitalWrite(ledPin, LOW);
  }
  // short delay
  delay(100);
}
