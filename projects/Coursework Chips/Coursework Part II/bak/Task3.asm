//20125919 Qicheng CHEN

//z=logx, base is 2, x is positive integer, the result is rounded down
//RAM[0]=x, RAM[2]=z

//use b to copy the base value 2 to do exponential
//similar to division and exponential calculation
//every round use a to subtract b after calculating exponential function
//every round z is incremented until (x-b)<0

@R2
M = 0	//initialise z
@2
D = A
@R1
M = D	//base 2
@b
M = D	//b=2

(CMP)
//check if (x-b)<0
@R0
D = M		//D=x
@b
D = D - M	//x-b
@END
D; JLT		//if (x-b)<0, goto END

@R2
M = M + 1	// z++
//since it's base 2, b will simply be incremented by itself every operation
@b
D = M
M = D + M

@CMP
0; JMP		//goto CMP

(END)
@END
0; JMP	//infinite loop


