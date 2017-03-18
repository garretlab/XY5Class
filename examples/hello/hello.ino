#include "XY5Class.h"

XY5Class xy5(&Serial);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  xy5.begin(28, 56, 0x01);
  xy5.clear();
  xy5.home();
  xy5.print("HELLO WORLD");
  xy5.flush();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);
  xy5.scrollDisplayLeft();
}

