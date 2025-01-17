#include <stdio.h>
#include "pico/stdlib.h"

#define BUZZER_PIN 15 // Substitua pelo pino correto do buzzer no seu projeto

void buzzer_init() {
    // Configura o pino do buzzer como saída
    gpio_init(BUZZER_PIN);
    gpio_set_dir(BUZZER_PIN, GPIO_OUT);
}

void buzzer_beep(uint duration_ms) {
    // Liga o buzzer
    gpio_put(BUZZER_PIN, 1);
    sleep_ms(duration_ms);
    // Desliga o buzzer
    gpio_put(BUZZER_PIN, 0);
}

int main() {
    stdio_init_all(); // Inicializa a UART (se necessário)
    
    buzzer_init();
    printf("Buzzer inicializado. Emitindo beep de 2 segundos...\n");
    buzzer_beep(2000); // Beep de 2 segundos
    printf("Beep concluído.\n");

    return 0;
}
