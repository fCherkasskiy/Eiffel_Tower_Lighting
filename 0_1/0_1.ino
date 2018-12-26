#include <FastLED.h>

#define LED_PIN 5
#define NUM_LEDS 300

CRGB leds[NUM_LEDS];
bool power[NUM_LEDS];

byte del = 20;



void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  for(int i = 0; i <= NUM_LEDS; i ++){
  power[i] = 1;
}
for(int i = 50; i <= 100; i ++){
  power[i] = 0;
}
}

void loop() {
  tracer(0);
}

void tracer(bool bounce){ // One LED on at a time, going down the whole strip
  if(bounce == 0){ // one time and then restarts
    for(int i = 0; i < NUM_LEDS; i++){
      i = checkOn(power[i], i);
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
      leds[i] = CRGB(0, 0, 0);
      FastLED.show();
    }
    for(int i = 299; i >= 0; i--){
      leds[i] = CRGB(255, 255, 255);
      FastLED.show();
      delay(del);
      leds[i] = CRGB(0, 0, 0);
      FastLED.show();
    }
  }
}

int checkOn(bool state, int led){
  if(state == 0){
    leds[led] = CRGB(0, 0, 0);
  }
  led ++;
  return led;
}
