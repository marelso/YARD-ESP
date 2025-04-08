#include <Arduino.h>
#include "components/SwitchComponent.h"

SwitchComponent led(2);

void setup() {
  
}

void loop() {
  led.toggle();
  delay(1000);

}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}