        global gcd
        extern asserts
        section .text

gcd:
        mov     rax, rdi        ; move first param to be returned
        cmp     rsi, 0          ; check if we're done
        jne     algorithm       ; if we're not done, execute Euclidean algorithm
        ret

algorithm:
        xor     rdx, rdx        ; must clear since we'll do 64 bit div
        div     rsi             ; divide first param(rax) by second param
        mov     rdi, rsi        ; x, y = y, x
        mov     rsi, rdx        ; remainder is stored in rdx so make it 2nd param
        jmp     gcd
        ret