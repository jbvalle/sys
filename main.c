#include "gpio.h"

void wait_ms(int time){
    for(int i = 0; i < time; i++){
        for(int j = 0; j < 1600; j++);
    }
}


int main(void){

    gpio_init(GpioConfig, GpioConfigCount);

    for(;;){
        gpio_write(GPIO_PORT_A, 5, GPIO_LEVEL_HIGH);
        wait_ms(100);
        gpio_write(GPIO_PORT_A, 5, GPIO_LEVEL_LOW);
        wait_ms(100);
    }
    return 0;
}

