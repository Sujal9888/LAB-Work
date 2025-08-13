
;<Sujal Meher Kayasstha>
;Multiplication of two number Direct

jmp start

;data


;code
start: nop
	MVI B, 03H       ; Multiplicand
	MVI C, 04H       ; Multiplier
	MVI A, 00H       ; Result accumulator

	LOOP: ADD B      ; A = A + B
	DCR C            ; Decrement multiplier
	JNZ LOOP         ; Repeat until C = 0

	STA 3000H        ; Store result at memory location 3000H
	HLT              ; Halt