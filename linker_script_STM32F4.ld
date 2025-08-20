ENTRY(Reset_handler)

MEMORY
{
    SRAM(rwx) : ORIGIN = 0x20000000, LENGTH = 96K
    FLASH(rx) : ORIGIN = 0x08000000, LENGTH = 512K
}

_estack = ORIGIN(SRAM) + LENGTH(SRAM);

SECTIONS
{
    .vector_table :
    {
        . = ALIGN(4);
        KEEP(*(.vector_table))
        . = ALIGN(4);
    }> FLASH

    .text :
    {
        . = ALIGN(4);
        *(.text)
        *(.text.*)
        *(.rodata)
        *(.rodata.*)
        . = ALIGN(4);
    }> FLASH

    _sidata = LOADADDR(.data);

    .data :
    {
        . = ALIGN(4);
        _sdata = .;
        *(.data)
        *(.data.*)
        _edata = .;
        . = ALIGN(4);
    }> SRAM AT > FLASH

    .bss :
    {
        . = ALIGN(4);
        _sbss = .;
        *(.bss)
        *(.bss.*)
        . = ALIGN(4);
        _ebss = .;
    }> SRAM
}
