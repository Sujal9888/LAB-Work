
;<Sujal Meher Kayastha>
;2's complement for 16 bit

jmp start

;data


;code
start: nop
	LDA 1000H     ; Load low byte
	CMA           ; 1's complement
	ADI 01H       ; Add 1
	STA 1001H     ; Store result

	LDA 1003H     ; Load high byte
	CMA           ; 1's complement
	ACI 00H       ; Add carry from low byte
	STA 1004H     ; Store result

	HLT