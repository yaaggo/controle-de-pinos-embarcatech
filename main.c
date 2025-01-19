#include "pico/stdlib.h"
#include "inc/buzzer.h"
#include "inc/led.h"
#include "pico/bootrom.h"
#include <stdio.h>

int main() {
    stdio_init_all();

    led_init(LED_RED_PIN);
    led_init(LED_GREEN_PIN);
    led_init(LED_BLUE_PIN);

    buzzer_init(BUZZER_A_PIN);

    while(true) {
        int option;
        scanf("%d", &option);

        switch(option) {
            case 1: led_red_on(); break;
            case 2: led_blue_on(); break;
            case 3: led_green_on(); break;
            case 4: led_all_on(); break;
            case 5: 
                led_turn_off();
                buzzer_beep(BUZZER_A_PIN, 1000, 1000); 
                break;
            default: reset_usb_boot(0, 0); break;
        }

        sleep_ms(50);
    }
}
