/*#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GP9002.h>

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
*/

#include <Adafruit_GFX.h>    // Core graphics library
#include "WROVER_KIT_LCD.h" // Hardware-specific library
#include <SD_MMC.h>

WROVER_KIT_LCD tft;

void setup(void) {
  Serial.begin(115200);

  tft.begin();
  tft.setRotation(1);
  tft.fillScreen(WROVER_BLUE);
  
  Serial.print("Initializing SD card...");
  if (!SD_MMC.begin()) {
    Serial.println("failed!");
    return;
  }
  Serial.println("OK!");

  tft.drawBmpFile(SD_MMC, "/purple.bmp", 0, 0);
}
