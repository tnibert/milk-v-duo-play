#include <stdio.h>
#include <unistd.h>

#include <wiringx.h>

int main() {
    int LED_PIN = 0;

    if(wiringXSetup("duo", NULL) == -1) {
        wiringXGC();
        return -1;
    }

    if(wiringXValidGPIO(LED_PIN) != 0) {
        printf("Invalid GPIO %d\n", LED_PIN);
    }

    pinMode(LED_PIN, PINMODE_OUTPUT);

    while(1) {
        printf("Duo LED GPIO (wiringX) %d: Low\n", LED_PIN);
        digitalWrite(LED_PIN, LOW);
        sleep(5);
        printf("Duo LED GPIO (wiringX) %d: High\n", LED_PIN);
        digitalWrite(LED_PIN, HIGH);
        sleep(5);
    }

    return 0;
}
