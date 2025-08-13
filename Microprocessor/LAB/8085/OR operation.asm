
;<Sujal Meher Kayasstha>
;OR oeration

jmp start

;data


;code
start: nop
	LDA 1000H        ; Load value from 1000H into A
	MOV B, A         ; Copy A into B

	LDA 1001H        ; Load value from 1001H into A
	ORA B            ; A = A OR B

	STA 1002H        ; Store result into 1002H

	HLT              ; Halt