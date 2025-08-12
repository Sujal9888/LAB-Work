
;<Sujal Meher Kayastha>
;ADD DIRECT

jmp start

;data


;code
start: nop
        MVI A, 6H       ; Load first number (e.g., 6H) into accumulator
        MVI B, 8H       ; Load second number (e.g., 8H) into register B
        ADD B           ; Add B to accumulator
        STA 1000H	; Store the result at accumulator
HLT             	; Halt the program

