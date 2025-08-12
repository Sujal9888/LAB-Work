;<Sujal Meher Kayastha>
;Division for 8 bit

jmp start

;data


;code
start: nop

	LXI H, 1050H     ; HL points to 1050H
	MOV A, M         ; Load dividend into A
	MOV B, A         ; Store dividend in B

	INX H            ; HL now points to 8051H
	MOV A, M         ; Load divisor into A
	MOV C, A         ; Store divisor in C

	MVI D, 00H       ; Initialize quotient to 0

	LOOP: CMP C      ; Compare dividend (B) with divisor (C)
	      JC DONE    ; If B < C, jump to DONE
	      MOV A, B   ; Load dividend into A
	      SUB C      ; Subtract divisor
	      MOV B, A   ; Update dividend
	      INR D      ; Increment quotient
	      JMP LOOP   ; Repeat

	DONE: MOV A, D   ; Move quotient to A
	LXI H, 1052H     ; HL points to 1052H
	MOV M, A         ; Store quotient

	MOV A, B         ; Move remainder to A
	INX H            ; HL points to 8053H
	MOV M, A         ; Store remainder

	HLT              ; End program