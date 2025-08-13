
;<Sujal Meher Kayasstha>
;Count number

jmp start

;data


;code
start: nop
	MVI B, 0AH        ; B = 10 (number of counts)
	MVI C, 00H        ; C = counter starting from 0
	LXI H, 1010H      ; HL points to starting memory location

	LOOP:	MOV M, C          ; Store current count at memory[HL]
		INX H             ; Move to next memory location
		INR C             ; Increment counter
		DCR B             ; Decrement loop counter
	JNZ LOOP          ; Repeat until B = 0

	HLT               ; End program