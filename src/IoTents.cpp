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
#line 12 "/home/ishotjr/dev/IoTents/src/IoTents.ino"
#define DATAPIN    D6
#define CLOCKPIN   D8
#define BRIGHTNESS 20

Adafruit_DotStarMatrix matrix = Adafruit_DotStarMatrix(
                                  12, 6, DATAPIN, CLOCKPIN,
                                  DS_MATRIX_BOTTOM     + DS_MATRIX_LEFT +
                                  DS_MATRIX_ROWS + DS_MATRIX_PROGRESSIVE,
                                  DOTSTAR_BGR);

const uint16_t primaryColors[] = {
  matrix.Color(255, 0, 0), matrix.Color(0, 255, 0), matrix.Color(0, 0, 255)
};


OledWingAdafruit display;


int moisturePin = A0;
int moistureValue = 0;


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

  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println(moistureValue);
  display.display();

	display.loop();

  
  for (byte i = 0; i < 3; i++) {
    matrix.fillScreen(primaryColors[i]);
    matrix.show();
    delay(500);
  }

}