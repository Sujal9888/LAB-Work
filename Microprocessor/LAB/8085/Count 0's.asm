
;<Sujal Meher Kayasstha>
;Count 0's in  a byte

jmp start

;data


;code
start: nop
	LXI H, 1000H     ; HL = 1000H
	MOV A, M         ; Load byte into accumulator
	MVI B, 08H       ; B = 8 bits to check
	MVI C, 00H       ; C = 0-bit counter

	LOOP:	RAR         ; Rotate right through carry
		JNC COUNT   ; If carry = 0, it's a 0 bit
		JMP SKIP    ; If carry = 1, skip

	COUNT:	INR C      ; Increment 0-bit counter

	SKIP:	DCR B       ; Decrement bit counter
		JNZ LOOP    ; Repeat until B = 0

	MOV A, C         ; Move result to A
	STA 1001H        ; Store result at 1001H
	HLT              ; Halt