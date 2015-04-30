        global  powersub
        section .text

powersub:
    mov     rax, 0
    subpd       xmm0,xmm1

power:
    addpd       xmm0, xmm0
    inc     rax
    cmp     rax, rdi
    je      end
    call    power

end:
    ret