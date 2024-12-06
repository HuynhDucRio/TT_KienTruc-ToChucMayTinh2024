ORG 00H
	LOOP:
	MOV A,P3 ;input
	ANL A, #0Fh ;clear 4 bit cao
	MOV R2,A ;copy to R2
	
	MOV A,P3 ;input
	SWAP A ;swap 4 bit cao thanh 4 bit thap
	ANL A, #0Fh ; clear 4 bit cao
	
	ADD A,R2 ;Cong hai so 4 bit
	MOV P1,A ;Output
	
	JMP LOOP ;Vong lap
END