#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 1   // number of lights

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// Time (in milliseconds) to pause between pixels
// 500 milliseconds = 0.5s
#define DELAYVAL 500 

void setup() {
  // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)
  pixels.begin();
}

void loop() {
  // Set all pixel colors to 'off'
  pixels.clear();

  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    // Set color values here! Colors range from 0 to 255
    int Red = 0;
    int Green = 150;
    int Blue = 0;
    
    pixels.setPixelColor(i, pixels.Color(Red, Green, Blue));

    pixels.show();   // Send the updated pixel colors to the hardware.

    delay(DELAYVAL); // Pause before next pass through loop
  }
}
