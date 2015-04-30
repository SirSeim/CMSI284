        global  main 
        extern  printf
        section .text

main:                           
        mov     rsi, 0x20       
        mov     r12, 0          
top:
        cmp     rsi, 0x7E       
        jg      bottom          

        mov     rdi, format
        xor     rax, rax        
        push    rsi             
        call    printf          
        pop     rsi             
        inc     rsi             
 
        inc     r12             
        and     r12, 0xF        
        jz      newline         
         
        jmp     top             
 
newline: 
        xor     r12, r12        
        mov     rdi, nl         
        push    rsi             
        call    printf 
        pop     rsi             
        jmp     top             
 
bottom:                         
        mov     rdi, nl         
        xor     rax, rax        
        call    printf          
        xor     rax, rax        
        ret                     
format:  
        db      '%c', 0 
nl:      
        db      10, 0 