
;<Sujal Meher Kayastha>
;2's complement for 8 bit

jmp start

;data


;code
start: nop
	LDA 1000H     ; Load number into accumulator
        CMA           ; 1's complement
        INR A         ; Add 1 (2's complement)
        STA 1001H     ; Store result
        HLT           ; Halt program
