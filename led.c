#include <stdio.h>
#include "pico/stdlib.h"

// Definição dos GPIOs para LEDs
#define LED_RED 13   // LED vermelho no GP13
#define LED_GREEN 11 // LED verde no GP11
#define LED_BLUE 12  // LED azul no GP12

// Definição dos GPIOs do teclado matricial
#define ROWS 4
#define COLS 4
const uint8_t row_pins[ROWS] = {8, 7, 6, 5};
const uint8_t col_pins[COLS] = {4, 3, 2, 1};
const char key_map[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

// Função para inicializar um LED
void init_led(uint gpio) {
    gpio_init(gpio);
    gpio_set_dir(gpio, GPIO_OUT);
    gpio_put(gpio, 0); // Inicialmente desligado
}

// Função para ligar um LED
void turn_on_led(uint gpio) {
    gpio_put(gpio, 1);
}

// Função para desligar um LED
void turn_off_led(uint gpio) {
    gpio_put(gpio, 0);
}

// Função para desligar todos os LEDs
void turn_off_all_leds() {
    turn_off_led(LED_RED);
    turn_off_led(LED_GREEN);
    turn_off_led(LED_BLUE);
}

// Inicializa o teclado matricial
void init_keypad() {
    for (int i = 0; i < ROWS; i++) {
        gpio_init(row_pins[i]);
        gpio_set_dir(row_pins[i], GPIO_OUT);
        gpio_put(row_pins[i], 1); // Linha em HIGH
    }

    for (int i = 0; i < COLS; i++) {
        gpio_init(col_pins[i]);
        gpio_set_dir(col_pins[i], GPIO_IN);
        gpio_pull_up(col_pins[i]); // Ativa pull-up nas colunas
    }
}

// Verifica qual tecla está pressionada
char scan_keypad() {
    for (int row = 0; row < ROWS; row++) {
        gpio_put(row_pins[row], 0); // Ativa a linha

        for (int col = 0; col < COLS; col++) {
            if (gpio_get(col_pins[col]) == 0) {
                gpio_put(row_pins[row], 1); // Desativa a linha
                return key_map[row][col];
            }
        }

        gpio_put(row_pins[row], 1); // Desativa a linha
    }
    return '\0'; // Nenhuma tecla pressionada
}

// Processa as teclas pressionadas para controlar os LEDs
void process_key(char key) {
    switch (key) {
        case '1':
            gpio_get(LED_RED) ? turn_off_led(LED_RED) : turn_on_led(LED_RED);
            break;
        case '2':
            gpio_get(LED_GREEN) ? turn_off_led(LED_GREEN) : turn_on_led(LED_GREEN);
            break;
        case '3':
            gpio_get(LED_BLUE) ? turn_off_led(LED_BLUE) : turn_on_led(LED_BLUE);
            break;
        case '4':
            if (gpio_get(LED_RED) || gpio_get(LED_GREEN) || gpio_get(LED_BLUE)) {
                turn_off_all_leds();
            } else {
                turn_on_led(LED_RED);
                turn_on_led(LED_GREEN);
                turn_on_led(LED_BLUE);
            }
            break;
    }
}

int main() {
    stdio_init_all();

    // Inicializa os LEDs
    init_led(LED_RED);
    init_led(LED_GREEN);
    init_led(LED_BLUE);

    // Inicializa o teclado matricial
    init_keypad();

    char last_key = '\0';
    printf("Pressione a tecla 1, 2 e 3 para acender os LEDs, e 4 para apagar");

    while (1) {
        char key = scan_keypad();

        if (key != '\0' && key != last_key) {
            last_key = key;
            printf("Tecla pressionada: %c\n", key);
            process_key(key);
        } else if (key == '\0') {
            last_key = '\0'; // Reseta quando nenhuma tecla é pressionada
        }

        sleep_ms(100); // Aguarda para estabilizar a leitura
    }

    return 0;
}
