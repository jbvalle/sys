#include "stm32f401re_regs.h"

#define MODER_WIDTH 2


void wait_ms(int time){
    for(int i = 0; i < time; i++){
        for(int j = 0; j < 1600; j++);
    }
}


int main(void){

    RCC->AHB1ENR |= 1;

    GPIOA->MODER &= ~(3 << (5 * MODER_WIDTH));
    GPIOA->MODER |=  (1 << (5 * MODER_WIDTH));

    for(;;){
        GPIOA->ODR ^= (1 << 5);
        wait_ms(100);
    }
    return 0;
}

