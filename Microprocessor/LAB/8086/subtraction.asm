;Sujal Meher Kayastha  
;Subtraction

ORG 100h


.data
    msg1 db 'Enter first digit: $'
    msg2 db 13,10,'Enter second digit: $'
    msg3 db 13,10,'Difference : $'

.code
start:
    ; Initialize data segment
    mov ax, @data
    mov ds, ax

    ; Prompt for first digit
    mov ah, 09h
    lea dx, msg1
    int 21h

    ; Read first digit
    mov ah, 01h
    int 21h
    sub al, '0'
    mov bl, al

    ; Prompt for second digit
    mov ah, 09h
    lea dx, msg2
    int 21h

    ; Read second digit
    mov ah, 01h
    int 21h
    sub al, '0'
    sub bl, al

    ; Show result message
    mov ah, 09h
    lea dx, msg3
    int 21h

    ; Display result
    mov dl, bl
    add dl, '0'
    mov ah, 02h
    int 21h

    ; Exit
    mov ah, 4Ch
    int 21h
