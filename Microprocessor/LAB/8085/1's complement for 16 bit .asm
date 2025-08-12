
;<Sujal Meher Kayastha>
;1's complement for 16 bit

jmp start

;data


;code
start: nop
	LDA 1000H     ; Load low byte into accumulator
	CMA           ; Complement accumulator
	STA 1001H     ; Store complemented low byte at 1001H

	LDA 1002H     ; Load high byte into accumulator
	CMA           ; Complement accumulator
	STA 1003H     ; Store complemented high byte at 1003H

	HLT           ; Halt program

