#include <stdio.h>
#include "pico/stdlib.h"

#define BUZZER_PIN 15

void buzzer_init() {
    gpio_init(BUZZER_PIN);
    gpio_set_dir(BUZZER_PIN, GPIO_OUT);
}

void buzzer_beep(uint duration_ms) {
    gpio_put(BUZZER_PIN, 1);
    sleep_ms(duration_ms);
    gpio_put(BUZZER_PIN, 0);
}

int main() {
    stdio_init_all();
    buzzer_init();
    buzzer_beep(2000);
    return 0;
}
