#Wearable tech - 2017

By Ryan McDermott and Alyson Zepeda

##Download the arduino IDE:

###windows:

https://downloads.arduino.cc/arduino-1.8.1-windows.exe

###mac:

https://downloads.arduino.cc/arduino-1.8.1-macosx.zip


##Sample Code

###Blink
(copy and paste this into the arduino IDE)

```

int LEDPIN = 7;

void setup() {
	pinMode(LEDPIN, OUTPUT);
	}

void loop() {
	digitalWrite(LEDPIN, HIGH);
	delay(500);
	digitalWrite(LEDPIN, LOW);
	delay(500);
	}
```

###Multicolor Blink
```
#include <Adafruit_NeoPixel.h>

#define PIN 8
int color = 0;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  strip.setPixelColor(0, 255, 255, 255);
  strip.show(); // Initialize all pixels to 'off'
  delay(500);
  
  strip.setPixelColor(0, 255, 0, 255);
  strip.show(); // Initialize all pixels to 'off'
  delay(500);
  
  Serial.println(color);
}
```

#Multiple Colors
```
#include <Adafruit_NeoPixel.h>

#define LEDPIN 8

Adafruit_NeoPixel strip = Adafruit_NeoPixel(3, LEDPIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {

  strip.setPixelColor(0, 255, 255, 255);   
  strip.setPixelColor(1, 255, 0, 0);
  strip.setPixelColor(2, 0, 255, 0);
  strip.show(); // Initialize all pixels to 'off'
  delay(1);
}
```

#betterButton

```
#include <Adafruit_NeoPixel.h>

#define LEDPIN 8
#define BUTTONPIN 3

Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, LEDPIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pinMode(BUTTONPIN, INPUT_PULLUP);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {

  if (digitalRead(BUTTONPIN) == LOW) {
    strip.setPixelColor(0, 0, 255, 0);
  }

  if (digitalRead(BUTTONPIN) == HIGH) {
    strip.setPixelColor(0, 255, 0, 255);
  }
  strip.show(); // Initialize all pixels to 'off'
  delay(1);
}
```

#Color Cycle
```
#include <Adafruit_NeoPixel.h>

#define LEDPIN 8
#define BUTTONPIN 3
#define CHANGEDELAY 750

Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, LEDPIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pinMode(BUTTONPIN, INPUT_PULLUP);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {

  if (digitalRead(BUTTONPIN) == LOW) {
    strip.setPixelColor(0, 255, 255, 0);
    strip.show();
    delay(CHANGEDELAY);
  }
  
  if (digitalRead(BUTTONPIN) == LOW) {
    strip.setPixelColor(0, 255, 0, 255);
    strip.show();
    delay(CHANGEDELAY);
  }

  if (digitalRead(BUTTONPIN) == LOW) {
    strip.setPixelColor(0, 0, 255, 0);
    strip.show();
    delay(CHANGEDELAY);
  }

  if (digitalRead(BUTTONPIN) == LOW) {
    strip.setPixelColor(0, 0, 0, 0);
    strip.show();
    delay(CHANGEDELAY);
  }
  delay(1);
}
```
