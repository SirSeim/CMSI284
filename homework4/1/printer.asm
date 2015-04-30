        global  main 
        extern  printf
        section .text
; This app writes '0' through '9' to stdout

main:                           ; c in rsi
        mov     rsi, 0x20       ; store first character in rsi
        mov     r12, 0          ; create a counter
top:
        cmp     rsi, 0x7E       ; while not finished
        jg      bottom          ; (once bigger get out of loop)

        mov     rdi, format     ; first param of printf 
        xor     rax, rax        ; No floating point args 
        push    rsi             ; must save it because printf might trash it 
        call    printf          ; printf("%c", c) 
        pop     rsi             ; restore it 
        inc     rsi             ; move to next character 
 
        inc     r12             ; increment counter 
        and     r12, 0xF        ; see if 16 characters reached 
        jz      newline         ; create a newline       
         
        jmp     top             ; next iteration of the loop 
 
newline: 
        xor     r12, r12        ; clear counter 
        mov     rdi, nl         ; move newline to first param 
        push    rsi             ; save before printing 
        call    printf 
        pop     rsi             ; restore 
        jmp     top             ; continue printing 
 
bottom:                         ; now we are out of the loop, so finish up 
        mov     rdi, nl         ; going to printf a newline 
        xor     rax, rax        ; no doubles 
        call    printf          ; printf("\n") 
        xor     rax, rax        ; going to return 0 from main, rax holds retval 
        ret                     ; return from main 
format:  
        db      '%c', 0 
nl:      
        db      10, 0 