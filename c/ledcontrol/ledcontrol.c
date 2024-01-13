#include <stdio.h>
#include <unistd.h>

#include <wiringx.h>

#define LED_PIN 25
#define TOUCH_SENSOR_PIN 16

int main() {
    if(wiringXSetup("duo", NULL) == -1) {
        wiringXGC();
        return -1;
    }

    if(wiringXValidGPIO(LED_PIN) != 0) {
        printf("Invalid GPIO %d\n", LED_PIN);
    }
    if(wiringXValidGPIO(TOUCH_SENSOR_PIN) != 0) {
        printf("Invalid GPIO %d\n", LED_PIN);
    }

    pinMode(LED_PIN, PINMODE_OUTPUT);
    pinMode(TOUCH_SENSOR_PIN, PINMODE_INPUT);

    while(1) {
        digitalWrite(LED_PIN, digitalRead(TOUCH_SENSOR_PIN));
    }

    return 0;
}
