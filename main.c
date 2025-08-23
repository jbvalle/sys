#include "gpio.h"
#include "systick.h"
#include "cortex_m4.h"

void wait_ms(int time){
    for(int i = 0; i < time; i++){
        for(int j = 0; j < 1600; j++);
    }
}


int main(void){

    gpio_init(GpioConfig, GpioConfigCount);
    systick_init(&SysTickConfig);

    for(;;){
        if(SYSTICK->STK_CTRL & (1 << 16)){
            gpio_toggle(GPIO_PORT_A, 5);
        }

    }
    return 0;
}

