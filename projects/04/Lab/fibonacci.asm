// fibonacci: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34...
// calculate fibonacci
@preNum
M = 0
@curNum
M = 1

@2
D = A
@i
M = D //use i to count for fibonacci

@j	//use j to remember curNum
M = 0

@R0
D = M
@END2
D; JEQ	//if RAM[0]==0, goto END2

(LOOP)
@curNum
D = M
@j
M = D		// j = curNum
@preNum
D = M
@curNum
M = M + D	// nextNum = preNum + curNum
@j
D = M
@preNum
M = D		// preNum = curNum

//i ++
@i
M = M + 1
D = M
@R0
D = M - D
@END
D; JLT	//goto END if RAM[0]<i
@LOOP
0; JMP	//goto LOOP

(END)
@curNum
D = M
@R1
M = D
@END
0; JMP	//infinite loop

(END2)
@preNum
D = M
@R1
M = D
@END2
0;JMP	//infinite loop