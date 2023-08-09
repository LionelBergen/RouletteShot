#include <Wire.h>
#include <Servo.h>

#define LOOP_DELAY_MS 15

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define SERVO_PIN 9

Servo servo;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting");
  
  servo.attach(SERVO_PIN);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);

  displayMessage("Started!");
}

void loop() {
  for(int pos = 0; pos <= 180; pos += 20) {
    servo.write(pos);
    delay(1000);
  }
}

void displayMessage(String message) {
  display.clearDisplay();
  display.println(message);
  display.display();
}
