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

void setup();
void loop();
#line 10 "/home/ishotjr/dev/IoTents/src/IoTents.ino"
OledWingAdafruit display;

void setup() {

  display.setup();
  display.clearDisplay();
  display.display();

}

void loop() {

  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Hello, world!");
  display.display();

	display.loop();

}