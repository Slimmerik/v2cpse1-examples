        .cpu cortex-m0
        .text
        .align 1
        .global application

str:    .asciz "Hello world, the ANSWER is 42! @[]`{}~\n"


application:
        ldr r0 , =str
        bl print_asciz
        mov pc, lr