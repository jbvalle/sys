target extended-remote localhost:3333
monitor reset init
monitor flash write_image erase gen/main.elf
monitor reset
