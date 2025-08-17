;Sujal Meher Kayastha
;Reverse Name
org 100h

.data
    prompt  db 'Enter your name: $'
    msg     db 13, 10, 'Your name in reverse is: $'
    input   db 20       ; max length
            db ?        ; actual length entered
            db 20 dup(?) ; buffer for name

.code
start:
    mov ax, @data
    mov ds, ax

    ; Show prompt
    lea dx, prompt
    mov ah, 09h
    int 21h

    ; Get input
    lea dx, input
    mov ah, 0Ah
    int 21h

    ; Show message
    lea dx, msg
    mov ah, 09h
    int 21h

    ; Get length and point to last character
    mov cl, input+1
    mov ch, 0
    lea si, input+2
    add si, cx
    dec si

print_loop:
    mov dl, [si]
    mov ah, 02h
    int 21h
    dec si
    loop print_loop

    ; Exit
    mov ah, 4Ch
    int 21h