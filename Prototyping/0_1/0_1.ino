#include <FastLED.h>
#define LED_PIN 5
#define NUM_LEDS 300

CRGB leds[NUM_LEDS];
int blacklist[] = {5, 6, 7, 8, 9, 10, 11, 56, 89, 45, 280};

int del = 40;

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  Serial.begin(9600);
}

void loop() {
  tracer(1);
}

void tracer(bool bounce){ // One LED on at a time, going down the whole strip
  if(bounce == 0){ // one time and then restarts
    for(int i = 0; i < NUM_LEDS; i++){
      Serial.println(checkOn(i));
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

byte x = 0;
bool checkOn(int i1){
  for (x = 0; x < 10; x++) {
    Serial.println("FOR LOOP");
    Serial.println(x);
    if (i1 == blacklist[x]){
      Serial.println(i1);
      return 0;
    }
    return 1;
  } 
}
