#include <Adafruit_NeoPixel.h>

#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, PIN, NEO_GRB + NEO_KHZ800);

bool flashed;
long flash_time;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    
  }
  strip.begin();
  strip.setBrightness(255);
  strip.setPixelColor(0, 0, 0, 0);
  strip.show();

  flashed = false;

  randomSeed(analogRead(2));
  flash_time = random((48 * 60 * 60))*1000;

  Serial.print("Flashing at: ");
  Serial.println(flash_time);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (flashed) {
    delay(1000);
  } else if (millis() > flash_time) {
    strip.setPixelColor(0, 255,255,255);
    strip.show();
    delay(1000);
    strip.setPixelColor(0, 0, 0, 0);
    strip.show();
    flashed = true;
  } else {
    Serial.print("Currently at ");
    Serial.print(millis());
    Serial.print(" and flashing at ");
    Serial.println(flash_time);
    delay(500);
  }
}
