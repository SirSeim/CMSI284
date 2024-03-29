        global _gcd
        default rel

        section .text
_gcd:
        mov     rax, rdi        ; move first param to be returned
        cmp     rsi, 0          ; check if we're done
        jne     _algorithm       ; if we're not done, execute Euclidean algorithm
        ret

_algorithm:
        xor     rdx, rdx        ; must clear since we'll do 64 bit div
        div     rsi             ; divide first param(rax) by second param
        mov     rdi, rsi        ; x, y = y, x
        mov     rsi, rdx        ; remainder is stored in rdx so make it 2nd param
        jmp     _gcd