;Sujal Meher Kayastha  
;Zero Count

org 100h

.data
    prompt      db 'Enter a number (0-9): $'
    newline     db 13, 10, '$'
    resultMsg   db 'Number of 0s: $'
    resultChar  db '?', '$'

.code
start:
    mov ax, @data
    mov ds, ax

    ; Show prompt
    lea dx, prompt
    mov ah, 09h
    int 21h

    ; Read one character
    mov ah, 01h
    int 21h         ; input in AL

    sub al, '0'     ; convert ASCII to number (0–9)

    ; Count 0 bits
    mov cl, 8
    mov bl, 0

countLoop:
    shr al, 1
    jc skipZero
    inc bl
skipZero:
    dec cl
    jnz countLoop

    ; Convert result to ASCII
    add bl, '0'
    mov resultChar, bl

    ; Print newline
    lea dx, newline
    mov ah, 09h
    int 21h

    ; Print result message
    lea dx, resultMsg
    mov ah, 09h
    int 21h

    ; Print result character
    lea dx, resultChar
    mov ah, 09h
    int 21h

    ; Exit
    mov ah, 4Ch
    int 21h
