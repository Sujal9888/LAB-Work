
;<Sujal Meher Kayasstha>
;NOR oeration

jmp start

;data


;code
start: nop
	LDA 3000H        ; Load value from 3000H into A
	MOV B, A         ; Copy A into B

	LDA 3001H        ; Load value from 3001H into A
	ORA B            ; A = A OR B

	CMA              ; A = NOT A (complement accumulator)

	STA 3002H        ; Store result into 3002H

	HLT              ; Halt