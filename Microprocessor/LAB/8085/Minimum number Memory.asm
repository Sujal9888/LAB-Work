
;<Sujal Meher Kayastha>
;Minimuum number from memory

jmp start

;data


;code
start: nop
	LXI H, 1000H     ; Load HL with starting address of data (1000H)
	MVI C, 03H       ; Load C with count = 3 (number of values to compare)
	MOV A, M         ; Load first value into accumulator (assume it's minimum)
	DCR C            ; Decrement count (2 values left to compare)

	LOOP:	INX H            ; Move HL to next memory location
		CMP M            ; Compare A (current min) with M (next value)
		JC LOOP1         ; If A < M, skip update (A is still smaller)
		MOV A, M         ; If M < A, update A with new minimum

	LOOP1:  DCR C            ; Decrement count
		JNZ LOOP         ; If count ≠ 0, repeat loop

	STA 1003H        ; Store final minimum value at memory location 1003H
	HLT              ; Halt the program