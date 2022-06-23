.DATA

texte	DW "la superbe chaine"
		DW 0
maxi	DSW 1

.CODE

LEA SP,STACK

LD	R1,0
LEA	R2, texte	; R2 <- @ du 1er caractère

boucle:
	LD R0,[R2]	; R0 <- caractère courant
	CMP R0,0	; Si 0 -> FIN
	BEQ fin		; si (R0 == 0) -> aller à 'e'
	CMP R0,R1	; comparaison entre R0 et R1
	BLTU else	; si (R0 < R1) -> aller à 'else'
	LD R1,R0	; R1 <- R0
else:
	INC R2
	JMP boucle

fin:	ST R1,maxi	; placement de R1 dans la variable maxi
		HLT	; arret du programme
		
			

.STACK 10