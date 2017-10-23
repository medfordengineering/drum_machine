#include <Wire.h>
#include "Adafruit_MPR121.h"

int touch;
unsigned long duration[6];
int count = 0;

Adafruit_MPR121 cap = Adafruit_MPR121();

void setup() {
  Serial.begin(9600);
  cap.begin(0x5A);
}

void loop() {
  touch = cap.touched();
  if (touch != 0) {
    //Serial.print(touch);
    duration[count++] = millis();
    tone(8, 440, 100);
  }
  if (count == 5) {
    duration[5] = duration[4];
    delay(1000);
    for (int x = 0; x < 5; x++) {
      tone(8, 440, 100);
      delay (duration[x + 1] - duration[x]);
    }
    count = 0;
  }
  delay(100);
}
