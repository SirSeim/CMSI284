global main

extern puts

section .text


main:
        mov     rdx, maker           
        mov     al, 32                
setter:
        mov byte     [rdx], al             
        inc     al                     
        inc     rdx                    

        cmp     al, 127             
        je      fin                      
        test    al, 15                
        jnz     setter                      
        mov byte    [edx], 10             
        inc     rdx                    
        jmp     setter                      
fin:
        mov byte   [rdx], 0             
        mov     rdi, maker
        call    puts
        ret

        section .bss
maker:
        resb  101