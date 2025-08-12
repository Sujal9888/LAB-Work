
;<Sujal Meher Kayastha>
;ADD FROM MEMORY

jmp start

;data


;code
start: nop
        LDA 1000H        ; Load first number into accumulator
        MOV B, A         ; Move it to register B
        LDA 1001H        ; Load second number into accumulator
        ADD B            ; Add B to accumulator (A = A + B)
        STA 1002H        ; Store result at address 8002H
        HLT              ; Halt the program

hlt