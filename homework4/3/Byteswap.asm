 global  byteswap
        section .text

;byteswap:

;        mov     rsi, rdi
;        xor     rax, rax

;leep:
;        mov     rcx, rsi
;        and     rcx, 0xFF000000
;        or      rax, rcx
;        shr     rax, 8
;        shl     rsi, 8
;        cmp     rcx, 0
;        jz      done
;        jmp     leep

;done:
;        ret

;Trixie wrote this part
byteswap:
        mov     dl, [rdi]
        mov     al, [rdi+1]
        mov     cl, [rdi+2]
        mov     bl, [rdi+3]

        mov     [rdi], bl
        mov     [rdi+1], cl
        mov     [rdi+2], al
        mov     [rdi+3], dl

        ret