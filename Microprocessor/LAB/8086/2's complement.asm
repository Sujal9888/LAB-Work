;Sujal Meher Kayastha
; 2's complement
org 100h

.data
prompt db 'Enter a number (0-9): $'
msg db 13,10, '2''s complement is: $'
num db ?
result db ?

.code
start:
    mov ax, @data      ; initialize data segment
    mov ds, ax

    ; Display prompt
    lea dx, prompt
    mov ah, 09h
    int 21h

    ; Read character input
    mov ah, 01h
    int 21h            ; AL = ASCII character
    sub al, 30h        ; convert ASCII to number
    mov num, al

    ; Calculate 2's complement
    lea si, num
    mov al, [si]
    not al
    add al, 1
    mov result, al

    ; Display result message
    lea dx, msg
    mov ah, 09h
    int 21h

    ; Convert result to ASCII and display
    mov al, result
    add al, 30h        ; convert to ASCII
    mov dl, al
    mov ah, 02h
    int 21h

    ; Exit
    mov ah, 4ch
    int 21h