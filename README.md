#Wearable tech - 2017

By Ryan McDermott and Alyson Zepeda

##Download the arduino IDE:

###windows:

http://download.arduino.org/IDE/1.8.1/arduino-1.8.1-windows.zip

###mac:

http://download.arduino.org/IDE/1.8.1/arduino-1.8.1-macosx-signed.zip



##Sample Code

###Blink
(copy and paste this into the arduino IDE)

```
void setup() {
	pinMode(13, OUTPUT);
	}

void loop() {
	pinMode(13, HIGH);
	delay(500);
	pinMode(13, LOW);
	delay(500);
	}
```

###Multicolor Blink
```
#include <Adafruit_NeoPixel.h>

#define PIN 2
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

###Lightswitch
```
#include <Adafruit_NeoPixel.h>

#define LEDPIN 2
#define BUTTONPIN 3

bool onState = false;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, LEDPIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pinMode(BUTTONPIN, INPUT_PULLUP);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {

  if (digitalRead(BUTTONPIN) == LOW) {
    delay(100);
    if (onState == false) {
      onState = true;
    } else {
      onState = false;
    }
    Serial.print("Lights on: ");
    Serial.println(onState);
    while (digitalRead(BUTTONPIN) == LOW) {
      delay(1);
    }
  }

  if (onState == true) {
     strip.setPixelColor(0, 255, 255, 255);   
  }

  if (onState == false) {
     strip.setPixelColor(0, 0, 0, 0);
  }
  
  strip.show(); // Initialize all pixels to 'off'
  delay(1);
}
```

###Set Multiple Colors
```
#include <Adafruit_NeoPixel.h>

#define LEDPIN 2
#define BUTTONPIN 3

bool onState = false;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, LEDPIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pinMode(BUTTONPIN, INPUT_PULLUP);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {

  if (digitalRead(BUTTONPIN) == LOW) {
    delay(100);
    if (onState == false) {
      onState = true;
    } else {
      onState = false;
    }
    Serial.print("Lights on: ");
    Serial.println(onState);
    while (digitalRead(BUTTONPIN) == LOW) {
      delay(1);
    }
  }

  if (onState == true) {
     strip.setPixelColor(0, 255, 255, 255);   
  }

  if (onState == false) {
     strip.setPixelColor(0, 0, 0, 0);
  }
  
  strip.show(); // Initialize all pixels to 'off'
  delay(1);
}
```

#Multiple Colors
```
#include <Adafruit_NeoPixel.h>

#define LEDPIN 2

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
