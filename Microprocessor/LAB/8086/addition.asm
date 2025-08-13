;Sujal Meher Kayastha
org 100h

.data

msg1 db 'Enter first digit: $'
msg2 db 0Dh, 0Ah, 'Enter second digit: $'
resultMsg db 0Dh, 0Ah, 'Result: $'

.code
start:
    mov ax,@data
    mov ds, ax

    ; Prompt for first digit
    lea dx, msg1
    mov ah, 09h
    int 21h

    ; Read first digit
    mov ah, 01h
    int 21h
    sub al, '0'       ; convert ASCII to number
    mov bl, al        ; store in BL

    ; Prompt for second digit
    lea dx, msg2
    mov ah, 09h
    int 21h

    ; Read second digit
    mov ah, 01h
    int 21h
    sub al, '0'
    add bl, al        ; add to first digit

    ; Convert result to ASCII
    add bl, '0'

    ; Display result message
    lea dx, resultMsg
    mov ah, 09h
    int 21h

    ; Display result
    mov dl, bl
    mov ah, 02h
    int 21h

    ; Exit
    mov ah, 4Ch
    int 21h