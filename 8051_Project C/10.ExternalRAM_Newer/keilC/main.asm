
ORG 00H
MAIN:
	MOV P3, #0F0H	;TAT LED
	CALL DELAY
	MOV P3, #0FFH	;BAT LED
	CALL DELAY


	;EXTERNAL RAM
	RAMLOC EQU 000H ; External RAM	location = 6000H
	COUNT EQU 8 ; Variable count =  150d
	
	;COPY 8 BYTES DATA TO XRAM.
	MOV DPTR, #RAMLOC ; Mov DPTR to point	to ext. RAM location
	MOV R3, #COUNT ; Number of bytes of data
	MOV A,#01H
	repX: 	
	MOVX @DPTR, A ; Copy the content of acc to the ext. RAM
	RL A ; rotate left	
	INC DPTR ; Inc DPTR to point to next location
	DJNZ R3, repX ; Repeat this until all the bytes of data are sent

	;Read 8 bytes data, send to P1, with delay.
	MOV DPTR, #RAMLOC ; Mov DPTR to point	to ext. RAM location
	MOV R3, #COUNT ; Number of bytes of data
	repI: 	
	MOVX A,@DPTR	
	MOV P1,A
	ACALL DELAY ; call a delay before repeating the process
	INC DPTR ; Inc DPTR to point to next location
	DJNZ R3, repI ; Repeat this until all the bytes of data are sent

	JMP MAIN

DELAY: 
	MOV R1, #200
	LAPMORE:
		MOV R0, #200
		LAP:
		NOP
		NOP
		DJNZ R0, LAP
	DJNZ R1, LAPMORE
RET

END