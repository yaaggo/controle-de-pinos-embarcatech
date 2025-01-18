#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"

// Definição da porta GPIO do BUZZER
#define BUZZER_PIN 21

// Define os GPIOs para as linhas e colunas do teclado matricial 4x4
#define ROWS 4
#define COLS 4

// Mapear GPIOs para linhas e colunas
const uint8_t row_pins[ROWS] = {8, 7, 6, 5};
const uint8_t col_pins[COLS] = {4, 3, 2, 1};

// Matriz de teclas
const char key_map[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

// Frequências das notas musicais (em Hz)
enum NotasMusicais {
    a1 = 1500, 
    a2 = 2000, 
    a3 = 2500, 
    b1 = 3000, 
    b2 = 3500, 
    b3 = 3800, 
    c1 = 4300, 
    c2 = 4600,
    c3 = 5000
};

// Inicializa as linhas como saída e colunas como entrada
void init_gpio() {
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

// Configura o PWM no pino do buzzer com uma frequência especificada
void set_buzzer_frequency(uint pin, uint frequency) {
    uint slice_num = pwm_gpio_to_slice_num(pin);
    gpio_set_function(pin, GPIO_FUNC_PWM);
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, clock_get_hz(clk_sys) / (frequency * 4096));
    pwm_init(slice_num, &config, true);
    pwm_set_gpio_level(pin, 0);
}

// Função para tocar o buzzer por um tempo especificado (em milissegundos)
void play_buzzer(uint pin, uint frequency, uint duration_ms) {
    set_buzzer_frequency(pin, frequency);
    pwm_set_gpio_level(pin, 32768);
    sleep_ms(duration_ms);
    pwm_set_gpio_level(pin, 0);
}

// Verifica qual tecla foi pressionada
char scan_keypad() {
    for (int row = 0; row < ROWS; row++) {
        gpio_put(row_pins[row], 0);
        for (int col = 0; col < COLS; col++) {
            if (gpio_get(col_pins[col]) == 0) {
                while (gpio_get(col_pins[col]) == 0);
                gpio_put(row_pins[row], 1);
                return key_map[row][col];
            }
        }
        gpio_put(row_pins[row], 1);
    }
    return '\0';
}

// Associa números do teclado as frequencias, indo do mais grave ao mais agudo
void play_note_for_key(char key) {
    switch (key) {
        case '1':
            play_buzzer(BUZZER_PIN, a1, 500);
            break;
        case '2':
            play_buzzer(BUZZER_PIN, a2, 500);
            break;
        case '3':
            play_buzzer(BUZZER_PIN, a3, 500);
            break;
        case '4':
            play_buzzer(BUZZER_PIN, b1, 500);
            break;
        case '5':
            play_buzzer(BUZZER_PIN, b2, 500);
            break;
        case '6':
            play_buzzer(BUZZER_PIN, b3, 500);
            break;
        case '7':
            play_buzzer(BUZZER_PIN, c1, 500);
            break;
        case '8':
            play_buzzer(BUZZER_PIN, c2, 500); 
            break;
        case '9':
            play_buzzer(BUZZER_PIN, c3, 500); 
            break;
        default:
            break;
    }
}

int main() {
    init_gpio();

    printf("Teclado Matricial 4x4, pressione de 1 a 9 para escutar o buzzer em diferentes frequências.\n");

    while (1) {
        char key = scan_keypad();
        play_note_for_key(key);
        sleep_ms(100);
    }

    return 0;
}
