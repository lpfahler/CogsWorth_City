// Learning about bitRead() function in Arduino
// To use for binary counter in Cogsworth City Kit
// Want to make the code much simplier than the code provided
// Lori Pfahler
// August 2024

// bitRead(x, n)
// Reads a bit of a variable, e.g. bool, int. Note that float & double
// are not supported. You can read the bit of variables up to an 
// unsigned long long (64 bits / 8 bytes).
// Parameters
// x: the number from which to read.
// n: which bit to read, starting at 0 for the least-significant (rightmost) bit.

int x, y;

void setup() {
  Serial.begin(9600);
  // access digits for binary version of a decimal number
  // x = 11 (decimal) is "1011" in binary
  x = 11;
  Serial.println(x);
  Serial.println(bitRead(x, 0));
  Serial.println(bitRead(x, 1));
  Serial.println(bitRead(x, 2));
  Serial.println(bitRead(x, 3));
  Serial.println(bitRead(x, 4));
  Serial.println(bitRead(x, 5));
  // add one to x so now y = 12 (decimal) which is "1100" in binary
  y = x + 1;
  Serial.println(y);
  Serial.println(bitRead(y, 0));
  Serial.println(bitRead(y, 1));
  Serial.println(bitRead(y, 2));
  Serial.println(bitRead(y, 3));
  Serial.println(bitRead(y, 4));
  Serial.println(bitRead(y, 5));

}

void loop() {
  // put your main code here, to run repeatedly:

}
