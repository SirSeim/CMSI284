        global  byteswap
        section .text

byteswap:

        mov     rsi, rdi
        xor     rdi, rdi

leep:
        mov     rcx, rsi
        and     rcx, 0xFF000000
        or      rdi, rcx
        shr     rdi, 8
        shl     rsi, 8
        cmp     rcx, 0
        jz      done
        jmp     leep

done:
        ret