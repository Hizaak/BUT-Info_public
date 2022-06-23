.DATA

valinit DW 6
Fact DSW 1

.CODE

LEA SP,STACK

LD R0,1 ; R0 <- 1
LD R1,2 ; R1 <- 2

boucle:		LD R2, valinit	; R2 <- valinit
			CMP R1, R2		; comparaison de R1 et R2
			BGTU sk			; si (R1 > R2) -> aller à 'sk'
			MULU R0, R1		; R0 <- R0 * R1
			ADD R1, 1		; R1 <- R1 + 1
			JMP boucle		; aller à 'boucle'
			
sk:			ST R0, Fact		; Fact <- R0
			HLT

.STACK 100
