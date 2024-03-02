#include <FastLED.h>

#define NUM_LEDS 50
#define DATA_PIN 6

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  // Set your Valentine's Day color scheme
  CRGB red = CRGB(255, 0, 0);
  CRGB pink = CRGB(255, 105, 180);
  
  // Flashing effect
  for (int i = 0; i < 5; i++) {
    fill_solid(leds, NUM_LEDS, red);
    FastLED.show();
    delay(500);
    fill_solid(leds, NUM_LEDS, CRGB::Black);
    FastLED.show();
    delay(500);
    
    fill_solid(leds, NUM_LEDS, pink);
    FastLED.show();
    delay(500);
    fill_solid(leds, NUM_LEDS, CRGB::Black);
    FastLED.show();
    delay(500);
  }
  
  // Heartbeat effect
  for (int j = 0; j < 3; j++) {
    for (int brightness = 0; brightness < 255; brightness++) {
      fill_solid(leds, NUM_LEDS, pink);
      FastLED.show();
      FastLED.setBrightness(brightness);
      delay(5);
    }
    for (int brightness = 255; brightness >= 0; brightness--) {
      fill_solid(leds, NUM_LEDS, pink);
      FastLED.show();
      FastLED.setBrightness(brightness);
      delay(5);
    }
  }
}
