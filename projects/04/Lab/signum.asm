// signum, if RAM[0]>0, RAM[1] = 1, 
// else RAM[1] = 0  

// code:
@R0
D = M
@RESULT1
D; JGT		// if RAM[0]>0, jump, else
@R1
M = 0		// RAM[1] = 0
@END
0; JMP		// goto END

(RESULT1)
@R1
M = 1		// RAM[1] = 1
(END)
@END
0; JMP		// Infinite loop