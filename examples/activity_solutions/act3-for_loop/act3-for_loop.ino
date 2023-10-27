/**
 * Activity 3: Get those lights on!
 */

///////////////////////////// DON'T TOUCH /////////////////////////////////////
#include <Adafruit_NeoPixel.h>
#define PIN         6     // where the LED is connected on the board
#define NUMPIXELS   1     // number of lights
#define DELAYVAL    500   // 500 milliseconds = 0.5 seconds
#define BRIGHTNESS  50    // set BRIGHTNESS to about 1/5 (max = 255)
#define MAX_PIXEL   255   // max pixel brightness / color
#define STEPS       25    // max amount of steps
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
///////////////////////////////////////////////////////////////////////////////

void setup() {
  pixels.setBrightness(BRIGHTNESS); 
  pixels.begin();
}

void loop() {
  // TODO: add comments
  changeColors();
  blinkingPatterns();
  fadeInAndOut();
}

void changeColors() {
  int Red = 255;
  int Green = 255;
  int Blue = 255;
  
  for (int step = 0; step < STEPS; step++) {
    Red -= 10;
    pixels.setPixelColor(0, pixels.Color(Red, Green, Blue));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
}

void blinkingPatterns() {
  int Red = 255;
  int Green = 255;
  int Blue = 255;
  int num_blinks = 10;
  int on_time = DELAYVAL;
  int off_time = DELAYVAL;

  for (int i = 0; i < num_blinks; i++) {
    // Turn the LED on
    pixels.setPixelColor(0, pixels.Color(Red, Green, Blue));
    pixels.show();
    delay(on_time);
    
    // Turn the LED off
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));
    pixels.show();
    delay(off_time);
  }
}

void fadeInAndOut() {
  fadeIn();
  fadeOut();
}

void fadeIn() {
  int Red = 150;
  int Green = 0;
  int Blue = 0;
  for (int brightness = BRIGHTNESS/2; brightness <= BRIGHTNESS; brightness+=2) {
    pixels.setBrightness(brightness);
    pixels.setPixelColor(0, pixels.Color(Red, Green, Blue));
    pixels.show();
    delay(DELAYVAL);
  }
}

void fadeOut() {
  int Red = 150;
  int Green = 0;
  int Blue = 0;
  
  // Fade Out
  for (int brightness = BRIGHTNESS; brightness >= BRIGHTNESS/2; brightness-=2) {
    pixels.setBrightness(brightness);
    pixels.setPixelColor(0, pixels.Color(Red, Green, Blue));
    pixels.show();
    delay(DELAYVAL);
  }
}

void pulsatingEffect() {
  int Red = 150;
  int Green = 0;
  int Blue = 0;
  int NUM_PULSATIONS = 10;
  int PULSATE_DELAY = DELAYVAL;

  for (int i = 0; i < NUM_PULSATIONS; i++) {
    for (int brightness = 0; brightness <= BRIGHTNESS; brightness++) {
      pixels.setBrightness(brightness);
      pixels.show();
      delay(PULSATE_DELAY);
    }
    
    for (int brightness = BRIGHTNESS; brightness >= 0; brightness--) {
      pixels.setBrightness(brightness);
      pixels.show();
      delay(PULSATE_DELAY);
    }
  }
}
