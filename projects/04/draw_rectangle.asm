// Set screen base address (16384) pointer
@SCREEN
D = A
@addr
M = D

// Parameter at R0
@0
D = M
@n
M = D

// Initialize i
@i
M = 0

(LOOP)
	// if i > n, go to END
	@i
	D = M
	@n
	D = D - M
	@END
	D; JGT
	
	// else, draw rectangle
	// RAM[addr] = -1
	@addr
	A = M
	M = -1
	@32
	D = A
	@addr
	M = M + D
	@i
	M = M + 1
	@LOOP
	0; JMP

(END)
@END
0; JMP




