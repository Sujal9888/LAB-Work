org 100h           ; Required for .COM file

mov ah, 09h        ; Function to display string
mov dx, offset msg ; Correct: load offset address of msg
int 21h            ; Call DOS interrupt to print string
                       
mov ah, 4Ch        ; Exit function
int 21h

msg db 'Sujal Meher Kayastha$'    ; Message string, ends with '$'
