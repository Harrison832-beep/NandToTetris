//20125919 Qicheng CHEN

//Exponential function

//Exponential calculation can be done by using one number to do repeated addition to achieve multiplication
//and another to do counting which is the power number j
//everytime when j increments, k is used to remember the value of R2 in the last round 
//RAM[0]=x, RAM[1]=y, RAM[2]=z

//if x==0 and y==0, goto ZERO
//only one of x or y can be checked if it is zero at a time
//if x==0, goto ZR first, if y!=0, jump back to MAIN
@R0
D = M
@ZERO
D; JEQ

(MAIN)
@R3
M = 1
@i
M = 1	//initialise i
@j
M = 1	//initialise j

@R0
D = M
@R2
M = D	//initialise RAM[2]=RAM[0]
@k
M = D	//initialise k=RAM[0]
//if y==0, RAM[2]=1
@R1
D = M
@ONE
D; JEQ

(MULT)
@k
D = M
@R2
M = M + D
@i
M = M + 1	//i++
D = M
@R0
D = M - D	//x-i
@EXP
D; JLE		//if i>=x, goto EXP
@MULT
0; JMP		//else, loop

(EXP)
@j
M = M + 1	//j++
D = M
@R1
D = M - D	//y-j
@END
D; JLE		//if j>=y, goto END

//else i=1, k=RAM[2] then back to MULT
@R2
D = M
@k
M = D
@i
M = 1
@MULT
0; JMP

(ONE)
@R2
M = 1

(ZERO)
//if y==0, RAM[2]=-1, RAM[3]=-1
@R1
D = M	//D=y
@MAIN
D; JNE	//if (y!=0), back to MAIN
//otherwise
@R2
M = -1	//RAM[2]=-1
@R3
M = -1	//RAM[3]=-1

(END)
@END
0; JMP		//infinite loop
