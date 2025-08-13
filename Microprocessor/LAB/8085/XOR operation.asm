
;<Sujal Meher Kayasstha>
;XOR oeration

jmp start

;data


;code
start: nop
	LDA 2000H        ; Load value from 2000H into A
	MOV B, A         ; Copy A into B

	LDA 2001H        ; Load value from 2001H into A
	XRA B            ; A = A XOR B

	STA 2002H        ; Store result into 2002H

	HLT              ; Halt