//20125919 Qicheng CHEN

//Division
//division can be done by doing decrementing x with y or incrementing x with y if x<0
//when x gets another sign or 0, determine round-off and output the result 

//problem: the original x is gone, have to use another RAM to do the calculation
//remember to complete all the calculation contexts

//if y==0, goto YZR
@R1
D = M
@YZR
D; JEQ
@R3
M = 1

@R0
D = M
@j
M = D	//use j as RAM[0]
@R2
M = 0	//initialise RAM[2]

//if x>=0, goto DIV1, otherwise DIV2
@DIV1
D; JGE	
@DIV2
D; JLT	

//x>0, y>0
(DIV1)
@R1
D = M

//if y<0, goto DIV3
@DIV3
D; JLT

@j
M = M - D
D = M
@R2
M = M + 1

@RESULT1
D; JLE		//if x<=0, jump to result, otherwise loop
@DIV1
0; JMP

//x<0, y>0
(DIV2)
@R1
D = M

//if y<0, goto DIV4
@DIV4
D; JLT

@j
M = M + D
D = M
@R2
M = M - 1

@RESULT2
D; JGE		//if x>=0, jump to result, otherwise loop
@DIV2
0; JMP

//x>0, y<0
(DIV3)
@R1
D = M
@j
M = M + D
D = M
@R2
M = M - 1

@RESULT3
D; JLE		//if x>=0, jump to result, otherwise loop
@DIV3
0; JMP

(DIV4)
@R1
D = M
@j
M = M - D
D = M
@R2
M = M + 1

@RESULT4
D; JGE		//if x<=0, jump to result, otherwise loop
@DIV4
0; JMP

(RESULT1)
@j
D = M
@R1
D = M + D	//the last x
@i
M = D		//use i to remember the last x
D = M
@j
D = D + M
@ROUND_DOWN
D; JLT		//j+i<0, the last (x/y)<(1/2), round down
@END
0; JMP		//otherwise, goto END

(RESULT2)
@j
D = M
@R1
D = D - M	//the last x
@i
M = D		//use i to remember the last x
D = M
@j
D = D + M
@ROUND_UP
D; JGE		//j+i>=0, the last (|x|/y)>=(1/2), round up
@END
0; JMP		//otherwise, goto END

(RESULT3)
@j
D = M
@R1
D = D - M	//the last x
@i
M = D		//use i to remember the last x
D = M
@j
D = D + M
@ROUND_UP
D; JLE		//j+i<=0, the last (x/|y|)>=(1/2) round up
@END
0; JMP		//otherwise, goto END

(RESULT4)
@j
D = M
@R1
D = M + D	//the last x
@i
M = D		//use i to remember the last x
D = M
@j
D = D + M
@ROUND_DOWN
D; JGT		//j+i>0, the last (|x|/|y|)<(1/2)round down
@END
0; JMP		//otherwise, goto END

(ROUND_DOWN)
@R2
M = M - 1
@END
0; JMP		//goto END

(ROUND_UP)
@R2
M = M  + 1
@END
0; JMP		//goto END

(YZR)
//if y==0, RAM[2]=-1, RAM[3]=-1
@R2
M = -1
@R3
M = -1

(END)
@END
0; JMP		//infinite loop

