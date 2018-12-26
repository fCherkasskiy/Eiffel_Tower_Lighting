# Eiffel Tower Lighting
### This is a project to add interesting and fun lighting to an Eiffel Tower model about 4ft (1.2m) tall using a WS2812B LED strip and controlling it with an Arduino.

- Materials used for prototyping
  - WS2812B LED Strip
    - [The strip we used](https://www.amazon.com/ALITOVE-Individually-Addressable-Flexible-Waterproof/dp/B00VQ0D2TY/ref=sr_1_2_sspa?ie=UTF8&qid=1545852250&sr=8-2-spons&keywords=WS2812B%2Bwaterproof&refinements=p_89%3AALITOVE&th=1)
    - Any individually addressable LED strip will work when using the [FastLED](https://github.com/FastLED/FastLED/blob/master/FastLED.h) library for Arduino
  - Arduino/Genuino Mega 2560
  - 330Ω resistor from PWM pin on the Arduino to the signal input to the strip

#### To do list
  - Prebuild
    - [x] Make the lights bounce back and forth or one way
    - [ ] Be able to skip certain lights
    - [ ] Allow user to change while the code is running
    - [ ] More animations
  - Actual Build
    - [ ] Organize which LEDS will be turned on and off
    - [ ] Mount
    - [ ] Android Bluetooth application to change the Lighting (will be expanded upon in the future)
