/*
 * Project IoTents
 * Description: Particle Argon goes glamping
 * Author: ishotjr
 * Date: 201908xx
 */

#include <oled-wing-adafruit.h>
#include <Adafruit_DotStarMatrixRK.h>

// for Adafruit_DotStarMatrix
#define DATAPIN    D6
#define CLOCKPIN   D8
#define BRIGHTNESS 20
#define MAX_BRIGHTNESS 100

Adafruit_DotStarMatrix matrix = Adafruit_DotStarMatrix(
                                  12, 6, DATAPIN, CLOCKPIN,
                                  DS_MATRIX_BOTTOM     + DS_MATRIX_LEFT +
                                  DS_MATRIX_ROWS + DS_MATRIX_PROGRESSIVE,
                                  DOTSTAR_BGR);

const uint16_t primaryColors[] = {
  matrix.Color(255, 0, 0), matrix.Color(0, 255, 0), matrix.Color(0, 0, 255)
};


//SYSTEM_THREAD(ENABLED);
OledWingAdafruit display;


#define DAMP 3300
#define WET 3000
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

	display.loop();

  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);

	if (moistureValue < WET) {
    display.println("WET");
    matrix.setBrightness(MAX_BRIGHTNESS);
    matrix.fillScreen(primaryColors[0]);
  } else if (moistureValue < DAMP) {
    display.println("DAMP");
    matrix.setBrightness(BRIGHTNESS);
    matrix.fillScreen(primaryColors[2]);
  } else {
		display.println("OK");
    matrix.setBrightness(BRIGHTNESS);
    matrix.fillScreen(primaryColors[1]);
  }

  display.println(moistureValue);
  display.display();

  matrix.show();
  //delay(500);
  
}