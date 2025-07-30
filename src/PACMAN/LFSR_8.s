				AREA	LFSR, CODE, READONLY, ALIGN=3
Next_State		PROC
				EXPORT Next_State							[WEAK]
				PUSH {R4-R8, R10-R11, LR}
				AND R4, R0, #0x1;
				STR R4, [R2]
				CLZ R2, R1
				RSB R2, R2, #31
				LSR R4, R0, R2
				AND R4, R4, #1
				SUB R2, #1
Loop			LSR R3, R1, R2
				AND R3, R3, #1
				CMP R3, #1
				LSREQ R5, R0, R2
				ANDEQ R5, R5, #1
				EOREQ R4, R4, R5	
				SUBS R2, #1
				BNE Loop
				AND R3, R1, #1
				CMP R3, #1
				ANDEQ R5, R0, #1
				EOREQ R4, R4, R5
				LSL R4, #7
				LSR R0, #1
				ORR R0, R0, R4
				POP {R4-R8, R10-R11, PC}
				ENDP
				END
