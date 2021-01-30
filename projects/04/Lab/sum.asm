//sum up a series of numbers
//starting from 1 to n
@i
M = 1	//i=1

(LOOP)
// if i>n, goto END
@i
D = M
@R1
M = M + D
@R0
D = M
@i
M = M + 1
D = D - M
@END
D; JLT	// if(n-i)<0, goto END
@LOOP
0; JMP	// goto LOOP
(END)
@END
0; JMP	// infinite loop