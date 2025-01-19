#ifndef BUZZER_BEEP_2SEC_H
#define BUZZER_BEEP_2SEC_H

#include <stdint.h>

#define BUZZER_PIN 15 // Pino usado para o buzzer
#define BUZZER_FREQ 1000 // Frequência do beep em Hz

void buzzer_init(uint gpio);
void buzzer_beep(uint gpio, uint duration_ms);

#endif // BUZZER_BEEP_2SEC_H
