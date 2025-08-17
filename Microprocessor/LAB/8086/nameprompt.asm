;Sujal Meher Kayastha
org 100h

.data
                                     
    prompt_msg db "Enter your name: $"
    hello_msg db 0Dh, 0Ah, "Hello, $"
    name_input db 30 dup('$') ; buffer for input

.code
start:
    ; Set DS = CS since COM programs share segment
    mov ax, @data
    mov ds, ax

    ; Display prompt
    lea dx, prompt_msg
    mov ah, 09h
    int 21h

    ; Read string input
    mov ah, 0Ah
    lea dx, name_input
    int 21h

    ; Display greeting
    lea dx, hello_msg
    mov ah, 09h
    int 21h

    ; Display entered name
    lea dx, name_input+2     ; skip length bytes
    mov ah, 09h
    int 21h

    ; Exit
    mov ah, 4Ch
    int 21h  
    
name input db 30,0,30 dup<'$'>

ret