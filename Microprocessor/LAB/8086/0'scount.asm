;Sujal Meher Kayastha

org 100h

mov al, 5Ah       ; example number = 01011010
mov cl, 8         ; check 8 bits
mov bl, 0         ; counter for 0s

next:
shr al, 1         ; shift right ? LSB ? CF
jc skip           ; if carry = 1, bit was 1 ? skip
inc bl            ; if carry = 0, bit was 0 ? count

skip:
dec cl
jnz next

; Convert count (bl) to ASCII
add bl, 30h       
mov ah, 02h       
mov dl, bl        
int 21h           ; print the number of 0s

mov ah, 4Ch
int 21h

