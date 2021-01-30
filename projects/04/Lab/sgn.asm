// sgn function
// if RAM[0]<0, RAM[1] = -1
// else if RAM[0] == 0, RAM[1] = 0
// else RAM[1] = 1

// Code:
@R0
D = M
@GREATER
D; JGT		// goto GREATER if RAM[0]>0
@EQUAL
D; JEQ		// goto EQUAL if RAM[0]==0
@SMALLER
D; JLT		// goto SMALLER if RAM[0]<0

(GREATER)
@R1
M = 1		// RAM[1] = 1
@END
0; JMP

(EQUAL)
@R1
M = 0		// RAM[1] = 0
@END
0; JMP

(SMALLER)
@R1
M = -1		// RAM[1] = -1
@END
0; JMP

(END)
@END
0; JMP		// infinite loop
