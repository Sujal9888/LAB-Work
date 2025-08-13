
;<Sujal Meher Kayasstha>
;Multiplication of two number from memory

jmp start

;data


;code
start: nop
	LXI H, 1000H     ; HL = 1000H
	MOV B, M         ; B = first number
	INX H            ; HL = C001H
	MOV C, M         ; C = second number

	MVI A, 00H       ; A = 0 (accumulator for result)

	LOOP:	ADD B            ; A = A + B
		DCR C            ; C = C - 1
	JNZ LOOP         ; Repeat until C = 0

	STA 1002H        ; Store result at 1002H
	HLT              ; End program