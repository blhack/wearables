#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip = Adafruit_NeoPixel(5, 12, NEO_GRB + NEO_KHZ800);

volatile int progChoice = 0;
volatile bool stopSeq = false;
int numProgs = 8;                 //how many lighting programs are there?
unsigned long lastNext = 0;

uint32_t colors[6] = {strip.Color(0,0,0),
                      strip.Color(255, 0, 0),
                      strip.Color(0, 255, 0),
                      strip.Color(0, 0, 255),
                      strip.Color(255,0,255),
                      strip.Color(255,255,0)};


void next() {
  if (millis() - lastNext > 1000) {
    stopSeq = true;
    lastNext = millis();
    progChoice++;
    if (progChoice > numProgs-1) {
      progChoice = 0;
    }
  }
}

void blackOut() {
  for (int i=0; i<4; i++) {
    strip.setPixelColor(i, 0, 0, 0);
  }
  strip.show();
}


uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

void floodStrip(int r, int g, int b) {
  for (int i=0; i<4; i++) {
    strip.setPixelColor(i, r, g, b);
  }
  strip.show();
}

void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    if (stopSeq == true) {
      //Serial.println("Stopped");
      break;
    }
    delay(wait);
  }
  stopSeq = false;
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    if (stopSeq == true) {
      //Serial.println("Stopped");
      break;
    }
    delay(wait);
  }
  stopSeq = false;
}

void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
      }
      strip.show();
      if (stopSeq == true) {
        //Serial.println("Stopped");
        break;
      }
      delay(wait);
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off 
      }
    }
  }
  stopSeq = false;
}

void setup() {
  Serial.begin(9600);
  pinMode(3, INPUT_PULLUP);
  strip.begin();
  strip.show();
  attachInterrupt(digitalPinToInterrupt(3), next, FALLING);
}

void loop() {
  Serial.println(progChoice);
  switch (progChoice) {
    case 0:
      Serial.println("Colorwipe");
      colorWipe(colors[0], 50);
      break;
    case 1:
      Serial.println("Colorwipe");
      colorWipe(colors[1], 50);
      break;
    case 2:
      Serial.println("Colorwipe");
      colorWipe(colors[2], 50);
      break;
    case 3:
      Serial.println("Colorwipe");
      colorWipe(colors[3], 50);
      break;
    case 4:
      Serial.println("Colorwipe");
      colorWipe(colors[4], 50);
      break;
    case 5:
      Serial.println("Colorwipe");
      colorWipe(colors[5], 50);
      break;
    case 6:
      Serial.println("Rainbow");
      rainbow(50);
      break;
    case 7:
      Serial.println("theater chase rainbow");
      theaterChaseRainbow(50);
      break;
  }
  delay(100);
}

