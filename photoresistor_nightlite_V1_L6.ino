// Lesson #6 Intro to Coding Class
// Photoresistor Nightlight Version 1
// Brightness of LED is the inverse of the amount of light
// read in with the photoresistor.
// LBP Note: Come back to this code - seems like an odd way to do things
// at some point I would think you would want to stop calibrating?
// inventr.io Cogsworth City Kit 
// Lori Pfahler
// August 2024

int sensorPin = A0;
int ledPin = 9;
int maxLight = 255;

int lightLevel = 0;
int maxThreshold = 0; //max light level
int minThreshold = 1023; //min light level

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

}

/******************************************************************
 * void calibrateToRoom()
 *
 * This function sets a minThreshold and maxThreshold value for the
 * light levels in your setting. Move your hand / light source / etc
 * so that your light sensor sees a full range of values. This will
 * "autoCalibrate" to your range of input values.
******************************************************************/
void calibrateToRoom(){
  // function must run a few times to get a good range of bright and dark
  // value for the sketch to work properly
  if (lightLevel < minThreshold)
    minThreshold = lightLevel;
  if (lightLevel > maxThreshold)
    maxThreshold = lightLevel;

  lightLevel = map(lightLevel, minThreshold, maxThreshold, 0, maxLight);
  lightLevel = constrain(lightLevel, 0, maxLight);
}

void loop() {
  lightLevel = analogRead(sensorPin);
  // I would consider doing calibration in the void setup loop 
  // repeat calibration until the max and min Thresholds change very little
  calibrateToRoom();
  //Serial.print("\t");
  Serial.println(maxLight - lightLevel);
  analogWrite(ledPin, maxLight - lightLevel);

}
