;Sujal Meher Kayastha 
;Highest number
org 100h

.data
prompt1     db 'Enter first number (0-9): $'
prompt2     db 13, 10, 'Enter second number (0-9): $'
prompt3     db 13, 10, 'Enter third number (0-9): $'
resultMsg   db 13, 10, 'Highest number is: $'
resultChar  db '?', '$'

.code
start:
    mov ax, @data        ; initialize data segment
    mov ds, ax

    ; First number
    lea dx, prompt1
    mov ah, 09h
    int 21h
    mov ah, 01h
    int 21h
    sub al, '0'
    mov bl, al           ; bl = first number

    ; Second number
    lea dx, prompt2
    mov ah, 09h
    int 21h
    mov ah, 01h
    int 21h
    sub al, '0'
    cmp al, bl
    jbe skip1
    mov bl, al           ; bl = max so far
skip1:

    ; Third number
    lea dx, prompt3
    mov ah, 09h
    int 21h
    mov ah, 01h
    int 21h
    sub al, '0'
    cmp al, bl
    jbe skip2
    mov bl, al           ; bl = max
skip2:

    ; Convert result to ASCII
    add bl, '0'
    mov resultChar, bl

    ; Show result
    lea dx, resultMsg
    mov ah, 09h
    int 21h

    lea dx, resultChar
    mov ah, 09h
    int 21h

    ; Exit
    mov ah, 4Ch
    int 21h