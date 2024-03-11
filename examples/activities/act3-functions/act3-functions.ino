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
  rainbow(20);
  rainbowStep(2, 10);
  blinkingPatterns(2, 10);
  fadeInAndOut(1.5, 1.5);
}

///////////////////////////////////////////////////////////////////////////////
// Functions

/*
 * Parameters:
 *   - "seconds": a number that describes how long you want the rainbow to be
 * ---
 * Function Description: This function rotates your LED through the all the colors for "seconds" seconds.
 * ---
 * Example Function Call: `rainbow(20)` --> this creates a rainbow that lasts 20 seconds
 */
void rainbow(int seconds) {
  int i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<pixels.numPixels(); i++) {
      pixels.setPixelColor(i, Wheel((i+j) & 255));
    }
    pixels.show();
    delay(seconds * 3.92);
  }
}

/**
 * Parameters:
 *   - "seconds": a number that describes how long you want each "iteration" to be
 *   - "numSteps": a number that describes how many times you want the colors to change (choose a number from 0 to 15)
 * ---
 * Function Description: This function rotates your LED through the RGB colors by decreasing by a value of 50
 * "numSteps" amount of times. It will decrease the value every "seconds" seconds.
 * ---
 * Example Function Call: `rainbowStep(2, 10)` --> this decreases the RBG value every 2 seconds, for 10 times
 */
void rainbowStep(float seconds, int numSteps) {
  int Red = 250;
  int Green = 0;
  int Blue = 0;

  for (int step = 0; step < numSteps; step++) {
    if (Red > 0) {
      Red -= 50;
      Green += 50;
    }
    else if (Green > 0) {
      Green -= 50;
      Blue += 50;
    }
    else if (Blue > 0) {
      Blue -= 50;
      Red += 50;
    }
    pixels.setPixelColor(0, pixels.Color(Red, Green, Blue));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL * 2 * seconds); // Pause before next pass through loop
  }
}

/*
 * This is a helper function for our `rainbow()` method. It reuses steps to calculate which colors of the wheel
 * to display. It is only called inside our rainbow function so don't worry about its contents!
 */
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return pixels.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return pixels.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return pixels.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
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
