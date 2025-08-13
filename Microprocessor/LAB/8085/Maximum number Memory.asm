
;<Sujal Meher Kayastha>
;Maximum number from memory

jmp start

;data


;code
start: nop
	LXI H, 1000H     ; HL points to first memory location
	MVI C, 03H       ; C = number of values to compare
	MOV A, M         ; A = first value (assume max)
	DCR C            ; C = 2 (remaining comparisons)

	LOOP:	INX H            ; Move to next memory location
		CMP M            ; Compare A with M
		JNC SKIP         ; If A >= M, skip
		MOV A, M         ; If A < M, update max

	SKIP:	DCR C            ; Decrement counter
		JNZ LOOP         ; Repeat until C = 0

	STA 1003H        ; Store max value at 1003H
	HLT              ; Halt	