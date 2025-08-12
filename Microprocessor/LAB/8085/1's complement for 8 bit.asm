
;<Sujal Meher Kayastha>
;1's complement for 8 bit

jmp start

;data


;code
start: nop
        LDA 1000H        ; Load the 8-bit number from memory
        CMA              ; Complement the accumulator (1's complement)
        STA 1001H        ; Store the result at memory location 8001H
        HLT              ; Halt the program

hlt