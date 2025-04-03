#include <Arduino.h>

#define LED_PIN 2

// put function declarations here:
int myFunction(int, int);

void setup() {
  pinMode(LED_PIN, OUTPUT);
  int result = myFunction(2, 3);
}

void loop() {
  
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
  delay(1000);

}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}