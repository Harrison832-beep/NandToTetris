// RAM[0]+RAM[1], store result in RAM[2].
// Code:
@R0
D = M
@R1
D = M + D	// R0+R1
@R2
M = D		// Store in R2

(END)
@END
0; JMP		// Infinite loop

