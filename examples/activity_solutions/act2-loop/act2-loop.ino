/**
 * Activity 2: Why repeat when you can loop?
 */

///////////////////////////// DON'T TOUCH /////////////////////////////////////
#include <Adafruit_NeoPixel.h>
#define PIN         6
#define NUMPIXELS   1     // number of lights
#define DELAYVAL    500   // 500 milliseconds = 0.5 seconds
#define BRIGHTNESS  50    // Set BRIGHTNESS to about 1/5 (max = 255)
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
///////////////////////////////////////////////////////////////////////////////

void setup() {
  pixels.setBrightness(BRIGHTNESS); 
  pixels.begin();
}

void loop() {
  redlight();
  yellowlight();
  greenlight();
}

void redlight() {
  int Red = 150;
  int Green = 0;
  int Blue = 0;
  
  pixels.setPixelColor(0, pixels.Color(Red, Green, Blue));
  pixels.show();   // Send the updated pixel colors to the hardware.
  delay(DELAYVAL); // Pause before next pass through loop
}

void yellowlight() {
  int Red = 150;
  int Green = 150;
  int Blue = 0;
  
  pixels.setPixelColor(0, pixels.Color(Red, Green, Blue));
  pixels.show();   // Send the updated pixel colors to the hardware.
  delay(DELAYVAL); // Pause before next pass through loop
}

void greenlight() {
  int Red = 0;
  int Green = 150;
  int Blue = 0;
  
  pixels.setPixelColor(0, pixels.Color(Red, Green, Blue));
  pixels.show();   // Send the updated pixel colors to the hardware.
  delay(DELAYVAL); // Pause before next pass through loop
}