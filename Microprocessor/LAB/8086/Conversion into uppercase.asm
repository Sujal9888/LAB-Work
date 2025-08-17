;Sujal Meher Kayastha
;Conversion into Uppercase
org 100h

jmp start


.data
    msg_prompt db 'Enter your name: $'
    msg_upper  db 13, 10, 'UPPERCASE: $'
    newline    db 13, 10, '$'
    input_buf  db 30         ; max length of input
               db ?          ; actual length entered (filled by DOS)
               db 30 dup(?)  ; buffer for characters


.code
start:
    mov ax, @data        ; initialize data segment
    mov ds, ax

    ; Show prompt
    mov dx, offset msg_prompt
    mov ah, 09h
    int 21h

    ; Read input string
    mov ah, 0Ah
    mov dx, offset input_buf
    int 21h

    ; Print newline
    mov dx, offset newline
    mov ah, 09h
    int 21h

    ; Print "UPPERCASE: "
    mov dx, offset msg_upper
    mov ah, 09h
    int 21h

    ; Convert and print uppercase characters
    lea si, input_buf + 2      ; skip first two bytes (length info)
    mov cl, [input_buf + 1]    ; actual length entered

convert_loop:
    cmp cl, 0
    je done

    mov al, [si]
    cmp al, 'a'
    jb print_char
    cmp al, 'z'
    ja print_char
    sub al, 32                 ; convert to uppercase

print_char:
    mov dl, al
    mov ah, 02h
    int 21h

    inc si
    dec cl
    jmp convert_loop

done:
    mov ah, 4Ch
    int 21h