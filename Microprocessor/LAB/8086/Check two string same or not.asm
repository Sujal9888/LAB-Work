;Sujal Meher Kayastha
;Read two string and check whether they are same
org 100h

.data
str1 db 20 dup(0)
str2 db 20 dup(0)
msg1 db 'Enter first string: $'
msg2 db 13,10, 'Enter second string: $'
equalMsg db 13,10, 'Strings are equal.$'
notEqualMsg db 13,10, 'Strings are NOT equal.$'

.code
start:
    mov ax, @data
    mov ds, ax

    ; Prompt for first string
    lea dx, msg1
    mov ah, 09h
    int 21h

    ; Read first string
    lea si, str1
read1:
    mov ah, 01h
    int 21h
    cmp al, 13         ; Enter key?
    je done1
    mov [si], al
    inc si
    jmp read1
done1:
    mov byte ptr [si], 0   ; null-terminate

    ; Prompt for second string
    lea dx, msg2
    mov ah, 09h
    int 21h

    ; Read second string
    lea si, str2
read2:
    mov ah, 01h
    int 21h
    cmp al, 13
    je done2
    mov [si], al
    inc si
    jmp read2
done2:
    mov byte ptr [si], 0

    ; Compare strings
    lea si, str1
    lea di, str2
compare:
    mov al, [si]
    mov bl, [di]
    cmp al, bl
    jne not_equal
    cmp al, 0
    je equal
    inc si
    inc di
    jmp compare

equal:
    lea dx, equalMsg
    mov ah, 09h
    int 21h
    jmp exit

not_equal:
    lea dx, notEqualMsg
    mov ah, 09h
    int 21h

exit:
    mov ah, 4Ch
    int 21h