#ifndef LED_H
#define LED_H

// Macros

#define LED_RED_PIN 13
#define LED_GREEN_PIN 11
#define LED_BLUE_PIN 12

// Cabeçalhos
void led_init();
void led_turn_off();
void led_green_on();
void led_blue_on();
void led_red_on();
void led_all_on();

#endif