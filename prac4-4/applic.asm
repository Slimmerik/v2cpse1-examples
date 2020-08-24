        .cpu    cortex-m0
        .text
        .align  1
        .global application




application:
        push { r0 - r7, lr }
        ldr r5, =lorem
        ldr r4, =arr
        b loop


decode:
        ldrb r2, [r5, #1]
        ldrb r3, [r5, #2]
        mov  r7 , #0x00
        sub  r2, r2, #47    @offset
        sub  r3, r3, #48    @lenght
        sub  r1, r4, r2     @r1 = buffer - offset
        b    decodeloop



decodeloop:

        ldrb r0, [r1]
        strb r0, [r4]

        add r4,r4,#0x01
        add r7,r7,#0x01
        add  r1, r1, #1 @-offset op buffer + counter

        cmp  r3, r7
        bgt  decodeloop

        add  r5,r5, #0x3
        b    loop


loop:
        ldrb r0,[r5]

        add  r0,r0,#0x00
        beq  print

        cmp  r0, #'@'
        beq  decode

        strb r0, [r4]

        add  r4,r4,#0x1
        add  r5,r5,#0x1

        b    loop



ploop:
        ldrb r0,[r2]
        add  r0,r0,#0x00
        beq  done
        push {r0,r1,r2,r3}
        bl   uart_put_char
        pop  {r0,r1,r2,r3}
        add  r2,r2,#0x1
        b    ploop

print:
        ldr r2, =arr
        b ploop


done:


        pop  { r0 - r7 , pc}



        .data
arr: .skip 4000
