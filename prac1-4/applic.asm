        .cpu cortex-m0
        .text
        .align 1
        .global application

str:    .asciz "Hello world, the ANSWER is 42! @[]`{}~\n"


application:
        push { r0 - r7, lr }
        ldr r0 , =str
        bl print_asciz
        pop { r0 - r7 , pc}