;Sujal Meher Kayastha
;Multiplilcation
org 100h

.data
    prompt1 db 'Enter first digit (0-9): $'
    prompt2 db 13,10,'Enter second digit (0-9): $'
    resultMsg db 13,10,'Multipllication: $'
    result dw ?

.code
start:
    mov ax, @data     ; Initialize data segment
    mov ds, ax

    ; Prompt for first digit
    lea dx, prompt1
    mov ah, 09h
    int 21h

    ; Read first digit
    mov ah, 01h
    int 21h
    sub al, '0'       ; Convert ASCII to number
    mov bl, al        ; Store in BL

    ; Prompt for second digit
    lea dx, prompt2
    mov ah, 09h
    int 21h

    ; Read second digit
    mov ah, 01h
    int 21h
    sub al, '0'
    mov bh, al        ; Store in BH

    ; Multiply BL * BH
    mov al, bl
    mul bh            ; Result in AX
    mov result, ax

    ; Display result message
    lea dx, resultMsg
    mov ah, 09h
    int 21h

    ; Convert result to ASCII and print
    mov ax, result
    call PrintNumber

    ; Exit program
    mov ah, 4Ch
    int 21h   
    
    ; Subroutine to print number in AX
    PrintNumber proc
        mov cx, 0
        mov bx, 10
    
convertLoop:
    xor dx, dx
    div bx
    push dx
    inc cx
    test ax, ax
    jnz convertLoop

printLoop:
    pop dx
    add dl, '0'
    mov ah, 02h
    mov dl, dl
    int 21h
    loop printLoop
    ret
PrintNumber endp