// swap two numbers
// Code:
@50
D = A
@R0
M = D		// RAM[0] = 50
@100
D = A
@R1
M = D		// RAM[1] = 100
D = M
@temp
M = D		// temp = RAM[1]

// swap
@R0
D = M
@R1
M = D		// RAM[1] = RAM[0]
@temp
D = M
@R0
M = D		// RAM[0] = RAM[1]

(END)
@END
0; JMP		// Infinite loop


