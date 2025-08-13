
;<Sujal Meher Kayastha>
;Subroutine call addition

jmp start

;data


;code
start: nop
	LXI H, 2000H     ; HL = 2000H
	MOV A, M         ; A = first number
	INX H            ; HL = 2001H
	MOV B, M         ; B = second number

	CALL ADD         ; Call subroutine to add A and B

	STA 2002H        ; Store result at 2002H
	HLT              ; Halt

	; Subroutine 
	ADD: ADD B       ; A = A + B
	RET              ; Return to main program