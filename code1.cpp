#include <SPI.h>
#include "RF24.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define I2C_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
RF24 radio(22, 21);

void showStatus(String l1, String l2 = "", String l3 = "", String l4 = "") {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(l1);
  display.setCursor(0, 16);
  display.println(l2);
  display.setCursor(0, 32);
  display.println(l3);
  display.setCursor(0, 48);
  display.println(l4);
  display.display();
}

void setup() {
  Serial.begin(115200);
  delay(2000);

  if (!display.begin(SSD1306_SWITCHCAPVCC, I2C_ADDRESS)) {
    while (1) {}
  }
  showStatus("Starting...", "Init Radio");
  delay(800);

  if (!radio.begin()) {
    showStatus("ERROR!", "Radio FAILED!");
    while (1) {}
  }

  radio.setPALevel(RF24_PA_MAX, true);
  radio.setDataRate(RF24_2MBPS);
  radio.stopListening();

  showStatus("WIFI JAMMER", "Radio OK!", "Channels: 1-14", "RUNNING...");
  Serial.println("Wi-Fi Jammer Started!");
  delay(1000);
}

void loop() {
  for (int channel = 1; channel <= 14; channel++) {
    radio.setChannel(channel);
    radio.startConstCarrier(RF24_PA_MAX, 45);
    delay(100);
    radio.stopConstCarrier();

    showStatus("WIFI JAMMER", "Channel: " + String(channel), "Status: ACTIVE");
  }
}