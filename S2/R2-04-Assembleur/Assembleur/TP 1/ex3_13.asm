.DATA

valinit DW 13
Fact DSW 1

.CODE

LEA SP,STACK

LD R0,1
LD R1,2

boucle: LD R2, valinit
	CMP R1, R2
	BGTU sk		
	MULU R0, R1	
	ADD R1, 1
	JMP boucle	
			
sk:	ST R0, Fact
	HLT

.STACK 100
