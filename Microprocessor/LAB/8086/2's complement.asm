;Sujal Meher Kayastha
;2's complement
org 100h
.data
    msg1 db 'Enter a digit (0-9): $'
    msg2 db 13,10,'2''s Complement is: $'
.code
start:
    mov ax,@data
    mov ds,ax

    ; prompt
    mov ah,09h
    lea dx,msg1
    int 21h

    ; read single character
    mov ah,01h
    int 21h
    sub al,'0'       ; convert ASCII to number 0–9

    ; calculate 2's complement (4-bit)
    mov bl,al
    not bl           ; 1's complement
    add bl,1         ; +1 ? 2's complement
    and bl,0Fh       ; keep 4 bits

    ; print message
    mov ah,09h
    lea dx,msg2
    int 21h

    ; print decimal
    mov al,bl
    cmp al,9
    jbe print_single
    ; two-digit number
    mov ah,0
    mov bl,10
    div bl           ; AL=tens, AH=ones
    add al,'0'
    mov dl,al
    mov ah,02h
    int 21h
    add ah,'0'
    mov dl,ah
    mov ah,02h
    int 21h
    jmp exit
print_single:
    add al,'0'
    mov dl,al
    mov ah,02h
    int 21h
exit:
    mov ah,4Ch
    int 21h
end start
