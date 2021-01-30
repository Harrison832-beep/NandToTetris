// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)

// Put your code here.
// Multiply R0 and R1, store result in R2.
// int i, R2;
//	for(i=0; i<R1; i++){
//		R2 += R0;
//  }

	
@i	// Memory Location of i
M = 0	// i = 0
@R2	// Memory Location of R2
M = 0	// R2 = 0 

(LOOP)
@i
D = M	// D = i
@R1	// A = the address of R1 (which is 1)
D = M-D	// D = R1-i
@END
D; JEQ	// if i == R0, goto END, otherwise

@R0
D = M	// D = R0
@R2
M = M + D // R2 += R0
@i
M = M + 1	// i ++
@LOOP
0; JMP	// goto back to LOOP

(END)
@END
0; JMP	// infinite loop
