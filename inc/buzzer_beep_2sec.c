// Arquivo buzzer_beep_2sec.c
#include "buzzer_beep_2sec.h"
#include "hardware/pwm.h"
#include "pico/stdlib.h"
#include "hardware/clocks.h"

void buzzer_init(uint gpio) {
    gpio_set_function(gpio, GPIO_FUNC_PWM); // Configura o GPIO para PWM
    uint slice_num = pwm_gpio_to_slice_num(gpio);
    pwm_set_enabled(slice_num, false); // Desabilita o PWM inicialmente
}

void buzzer_beep(uint gpio, uint duration_ms) {
    uint slice_num = pwm_gpio_to_slice_num(gpio);
    uint clock_div = 4; // Divisor do clock
    uint sys_clock = clock_get_hz(clk_sys); // Frequência do sistema
    uint wrap = sys_clock / (clock_div * BUZZER_FREQ) - 1; // Calcula o valor de "wrap"

    pwm_set_clkdiv(slice_num, clock_div); // Define o divisor do clock
    pwm_set_wrap(slice_num, wrap); // Define o valor de "wrap"
    pwm_set_gpio_level(gpio, wrap / 2); // Ciclo de trabalho de 50%
    pwm_set_enabled(slice_num, true); // Habilita o PWM

    sleep_ms(duration_ms); // Aguarda pelo tempo do beep

    pwm_set_enabled(slice_num, false); // Desabilita o PWM
}
