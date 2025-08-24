#include "gpio.h"
#include "systick.h"

void wait_ms(int time){
    for(int i = 0; i < time; i++){
        for(int j = 0; j < 1600; j++);
    }
}


void task_1ms_handler(void){
    for(;;);
}

void task_50ms_handler(void){
    for(;;);
}

void task_100ms_handler(void){
    for(;;);
}

int main(void){

    gpio_init(GpioConfig, GpioConfigCount);
    systick_init(&SysTickConfig);
    SysTick_SetCallback(0, SysTick_Callback_Channel0);

    for(;;){
    }
    return 0;
}

