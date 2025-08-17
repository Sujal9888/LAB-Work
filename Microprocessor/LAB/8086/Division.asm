;Sujal Meher Kayastha
;Division 
org 100h

.data
    prompt1 db 'Enter first digit (0-9): $'
    prompt2 db 13, 10, 'Enter second digit (1-9): $'
    resultMsg db 13, 10, 'Division: $'
    num1 db ?
    num2 db ?
    result db ?

.code
start:
    mov ax, @data
    mov ds, ax

    ; Prompt for first digit
    lea dx, prompt1
    mov ah, 09h
    int 21h

    ; Read first digit
    mov ah, 01h
    int 21h
    sub al, '0'
    mov bl, al     ; store first digit in BL

    ; Prompt for second digit
    lea dx, prompt2
    mov ah, 09h
    int 21h

    ; Read second digit
    mov ah, 01h
    int 21h
    sub al, '0'
    mov cl, al     ; store second digit in CL

    ; Divide BL by CL
    xor ah, ah
    mov al, bl
    div cl         ; AL = BL / CL

    ; Convert result to ASCII
    add al, '0'
    mov result, al

    ; Show result message
    lea dx, resultMsg
    mov ah, 09h
    int 21h

    ; Show result
    mov dl, result
    mov ah, 02h
    int 21h

    ; Exit
    mov ah, 4Ch
    int 21h