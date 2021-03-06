#include <avr/pgmspace.h>

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

Adafruit_NeoPixel strip = Adafruit_NeoPixel (30, 2, NEO_GRB + NEO_KHZ800);

byte left [15] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
byte right [15] = {15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29};
const uint32_t left_pixels [][15] PROGMEM = {

};

const uint32_t right_pixels [][15] PROGMEM = {

};

void setup () {
  strip.begin ();
  strip.show ();
}

void loop () {
  for (byte degree = 0; degree < 360; ++degree) {
    for (byte led = 0; led < strip.numPixels () / 2; ++led) {
      strip.setPixelColor (left [led], pgm_read_dword_near (left_pixels [degree] + led));
      strip.setPixelColor (right [led], pgm_read_dword_near (right_pixels [degree] + led));
    }
    strip.show ();
  }
}
