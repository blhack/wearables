#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip = Adafruit_NeoPixel(5, 12, NEO_GRB + NEO_KHZ800);


int sensorPin = 10; 

void setup()  {
  pinMode(10, INPUT_PULLUP);
  Serial.begin(9600);
  strip.begin();
  strip.show();
  delay(500);
}

void blackOut() {
  for (int i=0; i<5; i++) {
    strip.setPixelColor(i, 0,0,0);
  }
  strip.show();
}

 
void loop()  {
  int sensVal = analogRead(A10);
  int brightness = map(sensVal, 0, 1023, 0, 500);
  for (int i=0; i<5 ;i++) {
    blackOut();
    strip.setPixelColor(i, 255, 255, 255);
    strip.show();
    delay(brightness);
  }
  Serial.println(brightness);
  delay(100);
}

