/* Advanced Wearable Electronics
By Jessica Patel

This code was written for the project VolleyGlove, which consists of 5 analog pressure sensors and a neopixel strip.
Each pressure sensor has a corresponding pixel on the neopixel light strip.
As a pressure sensor is pressed from the force of a volleyball while volleying, the corresponding light pixel lights up red.

The following code was written with help from ChatGPT.
*/

// Library to create neopixel object
#include <Adafruit_NeoPixel.h>

int numberOfPixels = 4; // number of neopixels being used on the strip
int numberOfSensors = 4; // number of analog pressure sensors being used
int pixelPin = 1; // input pin for neopixel strip - TX#1
int sensorPins[4] = {A10, A9, A7, A11}; // input pins for analog pressure sensors (limit of 4)

// Creating neopixel object
Adafruit_NeoPixel strip = Adafruit_NeoPixel(numberOfPixels, pixelPin, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  // beginning neopixel strip and starting to "show", but remains off
  strip.begin();
  strip.show();
}

void loop() {
  int threshold = 100;

  // for loop that checks the analog reading from each pressure sensor
  for (int i = 0; i < numberOfSensors; i++) {
    if (analogRead(sensorPins[i]) > threshold) {
      strip.setPixelColor(i, 255, 0, 0, 255); // turns corresponding pixels red 
    } else {
      strip.setPixelColor(i, 0, 0, 0); // otherwise, keep them off
    }
  }

  strip.show();
  delay(3000); // delay of three seconds

  // turns all lights off after one second has passed
  for (int i = 0; i < numberOfSensors; i++) {
    strip.setPixelColor(i, 0, 0, 0);
  }
}
