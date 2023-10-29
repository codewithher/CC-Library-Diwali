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
  changeRed(5, 10);
  blinkingPatterns(2);
  fadeInAndOut(4,5);
}

///////////////////////////////////////////////////////////////////////////////
// Functions

// TODO: paramterize functions
// TODO: comment how to use the functions defined below
void changeRed(int seconds, int numSteps) {
  int Red = 255;
  int Green = 255;
  int Blue = 255;

  for (int step = 0; step < numSteps; step++) {
    Red -= 10;
    pixels.setPixelColor(0, pixels.Color(Red, Green, Blue));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL * 2 * seconds); // Pause before next pass through loop
  }
}

void changeGreen(int seconds, int numSteps) {
  int Red = 255;
  int Green = 255;
  int Blue = 255;

  for (int step = 0; step < numSteps; step++) {
    Green -= 10;
    pixels.setPixelColor(0, pixels.Color(Red, Green, Blue));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL * 2 * seconds); // Pause before next pass through loop
  }
}

void changeBlue(int seconds, int numSteps) {
  int Red = 255;
  int Green = 255;
  int Blue = 255;

  for (int step = 0; step < numSteps; step++) {
    Blue -= 10;
    pixels.setPixelColor(0, pixels.Color(Red, Green, Blue));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL * 2 * seconds); // Pause before next pass through loop
  }
}

void blinkingPatterns(int seconds) {
  int Red = 255;
  int Green = 255;
  int Blue = 255;
  int num_blinks = 10;
  int on_time = DELAYVAL * 2 * seconds;
  int off_time = DELAYVAL * 2 * seconds;

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

void fadeInAndOut(int fadeInSeconds, int fadeOutSeconds) {
  fadeIn(fadeInSeconds);
  fadeOut(fadeOutSeconds);
}

void fadeIn(int seconds) {
  int Red = 150;
  int Green = 0;
  int Blue = 0;
  for (int brightness = BRIGHTNESS/2; brightness <= BRIGHTNESS; brightness+=2) {
    pixels.setBrightness(brightness);
    pixels.setPixelColor(0, pixels.Color(Red, Green, Blue));
    pixels.show();
    delay(DELAYVAL * 2 * seconds);
  }
}

void fadeOut(int seconds) {
  int Red = 150;
  int Green = 0;
  int Blue = 0;
  
  // Fade Out
  for (int brightness = BRIGHTNESS; brightness >= BRIGHTNESS/2; brightness-=2) {
    pixels.setBrightness(brightness);
    pixels.setPixelColor(0, pixels.Color(Red, Green, Blue));
    pixels.show();
    delay(DELAYVAL * 2 * seconds);
  }
}

void pulsatingEffect(int seconds, int numPulses) {
  int Red = 150;
  int Green = 0;
  int Blue = 0;
  int NUM_PULSATIONS = numPulses;
  int PULSATE_DELAY = DELAYVAL * 2 * seconds;

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
