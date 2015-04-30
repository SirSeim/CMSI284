        global onebits
        section .text

onebits:
        ;x = x - ((x >> 1) & 0x55555555);
        mov     eax, edi        
        shr     edi, 1  
        and     edi, 0x55555555 
        sub     eax, edi        

        ;x = (x & 0x33333333) + ((x >> 2) & 0x33333333)
        mov     edi, eax
        shr     edi, 2
        and     edi, 0x33333333
        and     eax, 0x33333333
        add     eax, edi

        ;x = (x + (x >> 4)) & 0x0F0F0F0F;
        mov     edi, eax
        shr     edi, 4
        add     eax, edi
        and     eax, 0x0F0F0F0F

        ;x = x + (x >> 8)
        mov     edi, eax
        shr     edi, 8
        add     eax, edi

        ;x = x + (x >> 16)
        mov     edi, eax
        shr     edi, 16
        add     eax, edi

        ;return x & 0x0000003F
        and     eax, 0x0000003F
        ret
