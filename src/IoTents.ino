/*
 * Project IoTents
 * Description: Particle Argon goes glamping
 * Author: ishotjr
 * Date: 201908xx
 */

#include <oled-wing-adafruit.h>

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