   .cpu cortex-m0
   .text
   .align 1
   .global print_asciz

print_asciz:
   mov  r5, r0

loop:
   ldrb r0,[r5]
   add  r0,r0,#0
   beq  done
   bl   conv_char
   bl   uart_put_char
   add  r5,r5,#1
   b    loop

done:
   mov pc, lr
