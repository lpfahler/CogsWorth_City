// Day 6 Code for Cogsworth City Adventure Kit
// Inventr.io
//
// I decided to use a DHT11 as my temperature sensor
// I also installed the Adafruit DHT sensor library and 
// this also includes the Adafruit Unified Sensor library
// Use the library manager in the Arduino IDE to install the DHT library
// and the Unified Sensor library will also install if 
// you select the button that will install dependencies.
//
// Note:  At the end of August, the lesson was changed to two
// photoresistors instead of a photoresistor and a temperature sensor
// I left my code as is - since it is fun to use a temp sensor
// but there is no temp sensor in the kit
//
// Lori Pfahler
// August 2024

// Code for using DHT11 with Adafruit Library DHT sensor library
#include "DHT.h"
#define DHTTYPE DHT11  
#define  DHTPIN 8
DHT dht(DHTPIN, DHTTYPE);

// pins for other components
int photoPin = A0;     // photoresistor
int ledTempPin = 12;   // red LED
int ledLightPin = 11;  // blue LED

// needed variables
float tempC;         // temperature in deg C from DHT11
int initLightVal;    // intial value of light at start of arduino
int threshold = 50; // threshold by which to turn on light LED, "100" seems to work in most cases
int lightVal;        // current light value from photoresistor

void setup() {
  // start the DHT11 sensor
  dht.begin();
  pinMode(ledTempPin, OUTPUT);
  pinMode(ledLightPin, OUTPUT);
  Serial.begin(9600);
  // get initial value of light level
  initLightVal = analogRead(photoPin);
}

void loop() {
  // Read from DHT11 - Make sure NOT to read the sensor more than 
  // every 1-2 seconds
  // Read temperature as Celsius (the default)
  tempC = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true) - should be a float
  // tempF = dht.readTemperature(true);
  // Read humidity - should be a float
  // humid = dht.readHumidity();
  
  // read light value
  lightVal = analogRead(photoPin);
  Serial.print("Temp in C: ");
  Serial.print(tempC);
  Serial.print(", Light Level: ");
  Serial.println(lightVal);

  // determine if temperature LED should be turned on
  if (tempC > 25.0) {
    digitalWrite(ledTempPin, HIGH);
  }
  else {
    digitalWrite(ledTempPin, LOW);
  }

  // determine if light level LED should be turned on 
  // turn on if the current light value is lower than the (initial value - threshold)
  if (lightVal < (initLightVal - threshold)) {
    digitalWrite(ledLightPin, HIGH);
  }
  else {
    digitalWrite(ledLightPin, LOW);
  }

  // only read the DHT11 every 2 seconds
  delay(2000);
}
