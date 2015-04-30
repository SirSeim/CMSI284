        global  byteswap
        section .text

byteswap:
        mov     eax, [rdi]
        bswap   eax
        mov     [rdi], eax