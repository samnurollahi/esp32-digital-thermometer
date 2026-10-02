#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// lm35
#define tempSensorPin 34

Adafruit_SSD1306 display(128, 64, &Wire, -1);

void setup() {
  Serial.begin(9600);
  Wire.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  
  pinMode(tempSensorPin, INPUT);

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.display();
}
void loop() {
  int sensorValue = analogRead(tempSensorPin);

  float voltage = sensorValue * 3.3 / 4095.0;
  float temperature = (voltage - 0.5) * 100;

  display.clearDisplay();
  display.setCursor(30, 30);
  display.setTextColor(SSD1306_WHITE);
  display.print("Temp: ");
  display.print(temperature, 1);
  display.print(" C");
  display.display();

  delay(1000);
}