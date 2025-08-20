#include <stdint.h>

#include <stdint.h>
#include "startup_STM32F4.h"

void Reset_handler(void){

    /* COPY .data from FLASH to SRAM */
    uint32_t *pSRC = (uint32_t *)&_sidata;

    for(uint32_t *ptr = &_sdata; ptr < &_edata;){
        *ptr++ = *pSRC++;
    }

    /* Write .bss with 0 */
    for(uint32_t *ptr = &_sbss; ptr < &_ebss;){

        *ptr++ = 0;
    }

    // Call main()
    main();
}

void Default_handler(){
    for(;;);
}


