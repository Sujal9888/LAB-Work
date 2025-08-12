
;<Sujal Meher Kayastha>
;Add with Carry

jmp start

;data


;code
start: nop
        LDA 1000H        ; Load first number into accumulator
        MOV B, A         ; Store it in register B

        LDA 1001H        ; Load second number into accumulator
        ADC B            ; Add B to A with carry

        STA 1002H        ; Store result at memory location 8002H
        HLT              ; Halt the program

