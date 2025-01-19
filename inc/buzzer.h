#ifndef BUZZER_H
#define BUZZER_H

// Macros

#define BUZZER_A_PIN 21

// Cabeçalhos

// Funçao para inicializa o Buzzer
void buzzer_init(uint gpio);

// Funçao para liga o Buzzer em uma determinada frequência
void buzzer_turn_on(uint gpio, uint freq);

// Funçao para desliga o Buzzer
void buzzer_turn_off(uint gpio);

// Funçao para ativa o Buzzer por um tempo determinado (em milissegundos)
void buzzer_beep(uint gpio, uint freq, uint duration_ms);

#endif