; Sujal Meher Kayastha
; True Binary 1's Complement of a Digit
org 100h
.data
    msg1 db 'Enter a digit (0-9): $'
    msg2 db 13,10,'1''s Complement is: $'

.code
start:
    ; Initialize data segment
    mov ax, @data
    mov ds, ax

    ; Prompt for digit
    mov ah, 09h
    lea dx, msg1
    int 21h

    ; Read digit
    mov ah, 01h
    int 21h
    sub al, '0'         ; Convert ASCII to number

    ; Apply 1's complement to lower 4 bits
    not al
    and al, 0Fh         ; Mask to 4 bits

    ; Convert result to ASCII
    mov ah, 0           ; Clear AH
    mov cx, 0           ; Clear CX (digit count)

    ; Convert binary to decimal (manual method)
    mov bx, 10
convert_loop:
    xor dx, dx
    div bx              ; AX / 10 ? AL = quotient, DL = remainder
    push dx             ; Save remainder (digit)
    inc cx              ; Count digits
    cmp ax, 0
    jne convert_loop

    ; Show result message
    mov ah, 09h
    lea dx, msg2
    int 21h

    ; Display digits from stack
print_loop:
    pop dx
    add dl, '0'
    mov ah, 02h
    int 21h
    loop print_loop

    ; Exit
    mov ah, 4Ch
    int 21h