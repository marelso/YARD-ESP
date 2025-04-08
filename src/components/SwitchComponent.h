#ifndef SWITCH_COMPONENT_H
#define SWITCH_COMPONENT_H

#include <Arduino.h>

class SwitchComponent {
    private:
        int pin;

        void turnOn() {
            Serial.printf("turning on pin %d \n", this->pin);

            digitalWrite(this->pin, HIGH);
        }

        void turnOff() {
            Serial.printf("Turning off pin %d \n", this->pin);
            
            digitalWrite(this->pin, LOW);
        }

    public:
        SwitchComponent(int pin) {
            this->pin = pin;
            Serial.printf("Using pin %d \n", this->pin);

            pinMode(this->pin, OUTPUT);
            digitalWrite(this->pin, LOW);
        }

        void toggle() {
            if(digitalRead(this->pin)) {
                turnOff();
            } else {
                turnOn();
            }
        }
};

#endif