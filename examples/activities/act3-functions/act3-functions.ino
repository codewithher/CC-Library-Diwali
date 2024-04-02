/**
 * Activity 3: Make your own patterns!
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
  // try hovering over these functions!
  rainbow(30);
  blinkingPatterns(2, 10);
  fadeInAndOut(1.5, 1.5);
}

///////////////////////////////////Functions//////////////////////////////////////////////

/**
 * Parameters:
 *   - "seconds": a number that describes how long you want the rainbow gradient to be
 * ---
 * Function Description: This function rotates your LED through the RGB colors (from red to green to blue) by 
 *     decreasing each pixel by a value of 1. It will go through the entire rainbow of colors is "seconds" seconds.
 * ---
 * Example Function Call: `rainbowStep(30)` --> creates a rainbow that lasts 30 seconds. 
 */
void rainbow(float seconds) {
  int Red = 0; 
  int Green = 0; 
  int Blue = 0;
  
  // Adjust the Red pixel
  for (Red = 255; Red > 0; Red --) {
    Green += 1; 
    pixels.setPixelColor(0, pixels.Color(Red, Green, Blue));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL * 2 * seconds / 765); // Pause before next pass through loop (milliseconds)
  }

  // Adjust the Green pixel
  for (Green = 255; Green > 0; Green --) {
    Blue += 1; 
    pixels.setPixelColor(0, pixels.Color(Red, Green, Blue));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL * 2 * seconds / 765); // Pause before next pass through loop (milliseconds)
  }

  // Adjust the Blue pixel
  for (Blue = 255; Blue > 0; Blue --) {
    Red += 1; 
    pixels.setPixelColor(0, pixels.Color(Red, Green, Blue));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL * 2 * seconds / 765); // Pause before next pass through loop (milliseconds)
  }
}

/*
 * Parameters:
 *   - "seconds": a number that describes how long you want the LED to stay on and off each blink
 *   - "num_blinks": a number that describes how many times you want the LED to blink
 * ---
 * Function Description: This function makes your LED blink "num_blinks" amount of times with the LED on and
 *   off for "seconds" amount of seconds.
 * ---
 * Example Function Call: `blinkingPatterns(1,10)` --> this makes the LED blink on and off for 1 second each, 10 times
 */
void blinkingPatterns(float seconds, int num_blinks) {
  int Red = 255;
  int Green = 255;
  int Blue = 255;
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

/*
 * Parameters:
 *   - "fadeInSeconds": a number that describes how long it takes for the LED to increase in brightness a little more
 *   - "fadeOutSeconds": a number that describes how long it takes for the LED to decrease in brightness a little more
 * ---
 * Function Description: This function makes your LED fade in with the brightness changing every "fadeInSeconds"
 *   seconds and then fade out with the brightness changing every "fadeOutSeconds" seconds
 * ---
 * Example Function Call: `fadeInAndOut(1,2)` --> this makes the LED fade in with the brightness chaning every 1 second
 *   and then fade out with the brighness changing every 2 seconds
 */
void fadeInAndOut(float fadeInSeconds, float fadeOutSeconds) {
  fadeIn(fadeInSeconds);
  fadeOut(fadeOutSeconds);
}

/*
 * Parameters:
 *   - "seconds": a number that describes how long it takes for the LED to fade brightness a little more
 * ---
 * Function Description: This function makes your LED slowly get brighter each "seconds" number of seconds
 * ---
 * Example Function Call: `fadeIn(1)` --> this increases the brightness a little every second
 */
void fadeIn(float seconds) {
  int Red = 150;
  int Green = 0;
  int Blue = 0;
  int brightnessStep = 5;    // how much we decrease brightness by
  int brightnessMaxStep = BRIGHTNESS / brightnessStep;  // how many steps it takes

  // Fade Out
  for (int step = 0; step < brightnessMaxStep; step++) {
    pixels.setBrightness(BRIGHTNESS - (step * brightnessStep));
    pixels.setPixelColor(0, pixels.Color(Red, Green, Blue));
    pixels.show();
    delay(DELAYVAL * 2 * seconds);
  }
}

/*
 * Parameters:
 *   - "seconds": a number that describes how long it takes for the LED to fade brightness a little more
 * ---
 * Function Description: This function makes your LED slowly get darker each "seconds" number of seconds
 * ---
 * Example Function Call: `fadeOut(1)` --> this decreases the brightness a little every second
 */
void fadeOut(float seconds) {
  int Red = 255;
  int Green = 120;
  int Blue = 0;
  int brightnessStep = 5;    // how much we decrease brightness by
  int brightnessMaxStep = BRIGHTNESS / brightnessStep;  // how many steps it takes

  // Fade Out
  for (int step = 0; step < brightnessMaxStep; step++) {
    pixels.setBrightness(BRIGHTNESS + (step * brightnessStep));
    pixels.setPixelColor(0, pixels.Color(Red, Green, Blue));
    pixels.show();
    delay(DELAYVAL * 2 * seconds);
  }
}

/*
 * Parameters:
 *   - "seconds": a number that describes how long it takes for the LED to fade brightness a little more
 *   - "numPulses": how many times you want the LED to fade in and out
 * --- 
 * Function Description: This function makes your LED slowly turn all the way on and all the way off a "numPulses"
 *   amount of times, with the brightness changing every "seconds" amount of seconds
 * ---
 * Example Function Call: `pulsatingEffect(1,2)` --> this makes the LED turn on and off 2 times with the brightness
 *   changing every 1 second
 */
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