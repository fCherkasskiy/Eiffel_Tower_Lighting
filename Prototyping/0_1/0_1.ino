#include <FastLED.h>
#define LED_PIN 5
#define NUM_LEDS 300

CRGB leds[NUM_LEDS];

byte del = 20;

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  Serial.begin(9600);
}

void loop() {
  tracer(0);
}

void tracer(bool bounce){ // One LED on at a time, going down the whole strip
  if(bounce == 0){ // one time and then restarts
    for(int i = 0; i < NUM_LEDS; i++){
      byte r = byte(random(256));
      byte g = byte(random(256));
      byte b = byte(random(256));
      Serial.print(r);      Serial.print("   ");      Serial.print(g);      Serial.print("   ");      Serial.print(b);    Serial.println("");
      leds[i] = CRGB(r, g, b);
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
