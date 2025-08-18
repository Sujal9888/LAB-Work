;Sujal Meher Kayastha
;Count no. of a's in given text
org 100h

jmp start

.data
    text db 'Nepal is a oldest country in south asia$'
    msg_text db 13, 10, 'TEXT: $'
    msg_result db 13, 10, 'NUMBER OF A''s: $'
    newline db 13, 10, '$'

.code
start:
    mov ax, @data
    mov ds, ax

    ; Print newline
    mov dx, offset newline
    mov ah, 09h
    int 21h

    ; Print "TEXT: "
    mov dx, offset msg_text
    mov ah, 09h
    int 21h

    ; Print the actual text
    mov dx, offset text
    mov ah, 09h
    int 21h

    ; Print newline
    mov dx, offset newline
    mov ah, 09h
    int 21h

    ; Count 'a' or 'A'
    mov si, offset text
    mov bl, 0          ; counter for 'a'

count_loop:
    mov al, [si]
    cmp al, '$'        ; end of string
    je show_result

    cmp al, 'a'
    je inc_count
    cmp al, 'A'
    je inc_count
    jmp skip

inc_count:
    inc bl

skip:
    inc si
    jmp count_loop

show_result:
    ; Print result message
    mov dx, offset msg_result
    mov ah, 09h
    int 21h

    ; Convert count to ASCII and print
    add bl, '0'
    mov dl, bl
    mov ah, 02h
    int 21h

exit:
    mov ah, 4Ch
    int 21h