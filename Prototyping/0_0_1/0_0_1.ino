#include <FastLED.h>

#define LED_PIN 5
#define NUM_LEDS 300

CRGB leds[NUM_LEDS];

byte del = 20;



void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  tracer(1);
}

void tracer(bool bounce){ // One LED on at a time, going down the whole strip
  if(bounce == 0){ // one time and then restarts
    for(int i = 0; i < NUM_LEDS; i++){
      leds[i] = CRGB(255, 255, 255);
      FastLED.show();
      delay(del);
      leds[i] = CRGB(0, 0, 0);
      FastLED.show();
    }
  }
  else{ // goes back and forth
    for(int i = 0; i < NUM_LEDS; i++){
      leds[i] = CRGB(255, 255, 255);
      FastLED.show();
      delay(del);
      FastLED.show();
    }
    for(int i = 299; i >= 0; i--){
      leds[i] = CRGB(0, 0, 0);
      FastLED.show();
      delay(del);
      FastLED.show();
    }
  }
}
