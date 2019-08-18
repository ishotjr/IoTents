/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "application.h"
#line 1 "/home/ishotjr/dev/IoTents/src/IoTents.ino"
/*
 * Project IoTents
 * Description: Particle Argon goes glamping
 * Author: ishotjr
 * Date: 201908xx
 */

#include <oled-wing-adafruit.h>
#include <Adafruit_DotStarMatrixRK.h>

// for Adafruit_DotStarMatrix
void setup();
void loop();
void probe();
void monitor(bool notify);
void local();
void remote();
#line 12 "/home/ishotjr/dev/IoTents/src/IoTents.ino"
#define DATAPIN    D6
#define CLOCKPIN   D8
#define BRIGHTNESS 20
#define MAX_BRIGHTNESS 100

Adafruit_DotStarMatrix matrix = Adafruit_DotStarMatrix(
                                  12, 6, DATAPIN, CLOCKPIN,
                                  DS_MATRIX_BOTTOM     + DS_MATRIX_LEFT +
                                  DS_MATRIX_ROWS + DS_MATRIX_PROGRESSIVE,
                                  DOTSTAR_BGR);

const uint16_t colors[] = {
  matrix.Color(255, 0, 0), // red
  matrix.Color(0, 255, 0), // green
  matrix.Color(0, 0, 255), // blue
  matrix.Color(0, 0, 0)    // black
};


//SYSTEM_THREAD(ENABLED);
OledWingAdafruit display;


#define DAMP 3300
#define WET 3000
#define NOTIFY_INTERVAL 5 * 1000 //TODO: 60 * 1000
int moisturePin = A0;
int moistureValue = 0;
unsigned long lastNotify = 0;


enum modes {
  NONE,  // none selected
  PROBE, // realtime soil analysis
  LOCAL, // visual alert
  REMOTE // visual alert + IFTTT
};
enum modes mode = NONE;

void setup() {

  display.setup();
  display.clearDisplay();
  display.display();

  matrix.begin();
  matrix.setBrightness(BRIGHTNESS);

  pinMode(moisturePin, INPUT);
  
}

void loop() {

  moistureValue = analogRead(moisturePin);

	display.loop();
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);

	if (display.pressedA()) {
    mode = PROBE;
  }
	if (display.pressedB()) {
    mode = LOCAL;
  }
	if (display.pressedC()) {
    mode = REMOTE;
  }

  switch(mode) {

    case PROBE:
      probe();
      break;

    case LOCAL:
      local();
      break;

    case REMOTE:
      remote();
      break;

    default:
      display.println("A: probe");
      display.println("B: here");
      display.println("C: away");

      matrix.fillScreen(colors[3]);
  }

  display.display();

  matrix.show();

}


void probe() {

  display.println("probe (TODO)");

  matrix.fillScreen(colors[3]);

}

void monitor(bool notify) {

  unsigned long now = millis();

	if (moistureValue < WET) {
    display.println("WET");
    matrix.setBrightness(MAX_BRIGHTNESS);
    matrix.fillScreen(colors[0]);

    if (notify) {
      
      if ((now - lastNotify) >= NOTIFY_INTERVAL) {
        lastNotify = now;
        display.println("!!!NOTIFY!!!");
      }

    }
  } else if (moistureValue < DAMP) {
    display.println("DAMP");
    matrix.setBrightness(BRIGHTNESS);
    matrix.fillScreen(colors[2]);
  } else {
		display.println("OK");
    matrix.setBrightness(BRIGHTNESS);
    matrix.fillScreen(colors[1]);
  }

  display.println(moistureValue);
  
}

void local() {

  display.println("LOCAL");
  monitor(false);

}

void remote() {

  display.println("REMOTE");
  monitor(true);

}