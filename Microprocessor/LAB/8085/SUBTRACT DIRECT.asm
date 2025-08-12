
;<Sujal Meher Kayastha>
;SUBTRACT DIRECT

jmp start

;data


;code
start: nop
        MVI A, 9H       ; Load first number (e.g., 9H) into accumulator
        MVI B, 6H       ; Load second number (e.g., 6H) into register B
        SUB B           ; SUB B from accumulator
        STA 1000H	; Store the result at accumulator
HLT             	; Halt the program

