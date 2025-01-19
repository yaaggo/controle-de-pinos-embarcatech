#include <stdio.h>
#include "pico/stdlib.h"

// Definição dos GPIOs para LEDs
#define LED_RED 13   // LED vermelho no GP13
#define LED_GREEN 11 // LED verde no GP11
#define LED_BLUE 12  // LED azul no GP12

// Define os GPIOs para as linhas e colunas do teclado matricial 4x4
#define ROWS 4
#define COLS 4

// Mapear GPIOs para linhas e colunas
const uint8_t row_pins[ROWS] = {8, 7, 6, 5};
const uint8_t col_pins[COLS] = {1, 2, 3, 4};

// Matriz de teclas
const char key_map[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

// Inicializa as linhas como saída e colunas como entrada
void init_gpio() {
    // Configura LEDs como saída
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_put(LED_RED, 0);

    gpio_init(LED_BLUE);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
    gpio_put(LED_BLUE, 0);

    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_put(LED_GREEN, 0);

    // Configura teclado matricial
    for (int i = 0; i < ROWS; i++) {
        gpio_init(row_pins[i]);
        gpio_set_dir(row_pins[i], GPIO_OUT);
        gpio_put(row_pins[i], 1); // Linha inicialmente em HIGH
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
        gpio_put(row_pins[row], 0);
        for (int col = 0; col < COLS; col++) {
            if (gpio_get(col_pins[col]) == 0) {
                return key_map[row][col];
            }
        }
    }
    return '\0'; // Nenhuma tecla pressionada
}

// Controla os LEDs com base na tecla pressionada
void control_leds(char key) {
    // Desliga todos os LEDs inicialmente
    gpio_put(LED_RED, 0);
    gpio_put(LED_BLUE, 0);
    gpio_put(LED_GREEN, 0);

    // Ativa os LEDs de acordo com a tecla pressionada
    if (key == 'A') {
        gpio_put(LED_RED, 1); // Tecla A acende o LED vermelho
    } else if (key == 'B') {
        gpio_put(LED_GREEN, 1); // Tecla B acende o LED verde
    } else if (key == 'C') {
        gpio_put(LED_BLUE, 1); // Tecla C acende o LED azul
    } else if (key == 'D') {
        gpio_put(LED_RED, 1);   // Tecla D acende todos os LEDs
        gpio_put(LED_GREEN, 1);
        gpio_put(LED_BLUE, 1);
    }
}

int main() {
    stdio_init_all();
    init_gpio();

    char current_key = '\0'; // Variável para armazenar a tecla atual

    while (1) {
        char key = scan_keypad(); // Verifica se há tecla pressionada

        if (key != '\0') {
            if (key != current_key) {
                current_key = key; // Atualiza a tecla pressionada
            }
            printf("Tecla pressionada: %c\n", key);
        } else {
            current_key = '\0'; // Nenhuma tecla pressionada
        }

        control_leds(current_key); // Controla os LEDs conforme a tecla pressionada

        sleep_ms(100); // Tempo para estabilizar as leituras
    }

    return 0;
}
