#include <stdlib.h>
#include "pico/stdlib.h"
#include "led.h"

uint8_t leds_rgb[3] = {11, 12, 13};

// Funções

// função que inicializa os leds RGB com valor 0
void led_init() {
    // LED vermelho
    gpio_init(LED_RED_PIN);
    gpio_set_dir(LED_RED_PIN, GPIO_OUT);
    gpio_put(LED_RED_PIN, 0);

     // LED verde
    gpio_init(LED_GREEN_PIN);
    gpio_set_dir(LED_GREEN_PIN, GPIO_OUT);
    gpio_put(LED_GREEN_PIN, 0);

     // LED azul
    gpio_init(LED_BLUE_PIN);
    gpio_set_dir(LED_BLUE_PIN, GPIO_OUT);
    gpio_put(LED_BLUE_PIN, 0);
}