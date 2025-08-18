; Sujal Meher Kayastha
; 2's complement (signed output)

org 100h

.data
prompt db 'Enter a number (0-9): $'
msg    db 13,10,'2''s complement is: $'
minus  db '-' , '$'

.code
start:
    mov ax, @data
    mov ds, ax

    ; Display prompt
    lea dx, prompt
    mov ah, 09h
    int 21h

    ; Read input digit
    mov ah, 01h
    int 21h
    sub al, 30h          ; ASCII ? number

    ; Calculate 2's complement (4-bit only)
    not al
    add al, 1
    and al, 0Fh          ; keep 4 bits
    mov bl, al           ; store result

    ; Show message
    lea dx, msg
    mov ah, 09h
    int 21h

    ; Check if signed negative (>=8)
    cmp bl, 8
    jb print_positive

    ; Negative case
    mov ah, 09h
    lea dx, minus
    int 21h
    mov al, 16
    sub al, bl           ; signed value = -(16-bl)
    jmp print_number

print_positive:
    mov al, bl

print_number:
    ; Decimal conversion
    mov ah, 0
    mov cl, 10
    div cl               ; AL ÷ 10 ? AL=quotient, AH=remainder

    cmp al, 0
    je print_units

    ; Tens digit
    add al, '0'
    mov dl, al
    mov ah, 02h
    int 21h

print_units:
    mov al, ah
    add al, '0'
    mov dl, al
    mov ah, 02h
    int 21h

    ; Exit
    mov ah, 4Ch
    int 21h
