#include <stdlib.h>
#include "pico/stdlib.h"
#include "led.h"

uint8_t leds_rgb[3] = {11, 12, 13};

// Funções

// função que inicializa os leds RGB
void led_init() {
    // LED vermelho
    gpio_init(LED_RED_PIN);
    gpio_set_dir(LED_RED_PIN, GPIO_OUT);

    // LED verde
    gpio_init(LED_GREEN_PIN);
    gpio_set_dir(LED_GREEN_PIN, GPIO_OUT);

    // LED azul
    gpio_init(LED_BLUE_PIN);
    gpio_set_dir(LED_BLUE_PIN, GPIO_OUT);
}

// função que desliga todos os leds ao mesmo tempo
void led_turn_off() {
    // LED vermelho
    gpio_put(LED_RED_PIN, 0);

    // LED verde
    gpio_put(LED_GREEN_PIN, 0);

    // LED azul
    gpio_put(LED_BLUE_PIN, 0);
}