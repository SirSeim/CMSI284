        global gcd
        section .text

gcd:
        mov     rax, rdi        
        cmp     rsi, 0          
        jne     algorithm       
        ret

algorithm:
        xor     rdx, rdx        
        div     rsi             
        mov     rdi, rsi        
        mov     rsi, rdx        
        jmp     gcd