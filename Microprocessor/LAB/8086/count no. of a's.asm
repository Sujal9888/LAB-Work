;Sujal Meher Kayastha
;Count no.of a's
org 100h

jmp start


.data
    msg_prompt db 'Enter your name: $'
    msg_result db 13, 10, 'NUMBER OF A''s: $'
    newline    db 13, 10, '$'
    input_buf  db 30
               db ?
               db 30 dup(?)


.code
start:
    mov ax, @data
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

    ; Count 'a' or 'A'
    lea si, input_buf + 2      ; skip length bytes
    mov cl, [input_buf + 1]    ; actual length
    mov bl, 0                  ; counter for 'a'

count_loop:
    cmp cl, 0
    je show_result

    mov al, [si]
    cmp al, 'a'
    je inc_count
    cmp al, 'A'
    je inc_count
    jmp skip

inc_count:
    inc bl

skip:
    inc si
    dec cl
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