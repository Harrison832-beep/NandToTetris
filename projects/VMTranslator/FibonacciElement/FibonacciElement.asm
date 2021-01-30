
(Sys.init)
//Push
@4
D = A
@SP
A = M
M = D
@SP
M = M + 1
(CALL_START1)
@ARG
D = M
@R13
M = D
@1
D = A
@SP
D = M - D
@ARG
M = D
@CALL_END1
D = A
@SP
A = M
M = D
@SP
M = M + 1
@LCL
D = M
@SP
A = M
M = D
@SP
M = M + 1
@R13
D = M
@SP
A = M
M = D
@SP
M = M + 1
@THIS
D = M
@SP
A = M
M = D
@SP
M = M + 1
@THAT
D = M
@SP
A = M
M = D
@SP
M = M + 1
@SP
D = M
@LCL
M = D
@Main.fibonacci
0; JMP
(CALL_END1)

(WHILE)
@WHILE              
0; JMP

(Main.fibonacci)
//Push
@0
D = A
@ARG
A = M + D
D = M
@SP
A = M
M = D
@SP
M = M + 1
//Push
@2
D = A
@SP
A = M
M = D
@SP
M = M + 1
//LessThan
@SP
M = M - 1
A = M
D = M
@SP
M = M - 1
A = M
D = M - D
@LT0
D; JLT
D = 0
@LTRESULT0
0; JMP
(LT0)
D = -1
@LTRESULT0
0; JMP
(LTRESULT0)
@SP
A = M
M = D
@SP
M = M + 1
//If-goto
@SP
M = M - 1
A = M
D = M
@IF_TRUE
D; JNE
@IF_FALSE
0; JMP
(IF_TRUE)
//Push
@0
D = A
@ARG
A = M + D
D = M
@SP
A = M
M = D
@SP
M = M + 1
//Return
@SP
A = M - 1
D = M
@R15
M = D
@ARG
D = M
@R13
M = D
@LCL
D = M
@SP
M = D - 1
A = M
D = M
@THAT
M = D
@SP
M = M - 1
A = M
D = M
@THIS
M = D
@SP
M = M - 1
A = M
D = M
@ARG
M = D
@SP
M = M - 1
A = M
D = M
@LCL
M = D
@SP
M = M - 1
A = M
D = M
@R14
M = D
@R15
D = M
@R13
A = M
M = D
@R13
D = M
@SP
M = D + 1
@R14
A = M
A; JMP
(IF_FALSE)
//Push
@0
D = A
@ARG
A = M + D
D = M
@SP
A = M
M = D
@SP
M = M + 1
//Push
@2
D = A
@SP
A = M
M = D
@SP
M = M + 1
//Sub
@SP
M = M - 1
A = M
D = M
@SP
M = M - 1
A = M
D = M - D
@SP
A = M
M = D
@SP
M = M + 1
(CALL_START2)
@ARG
D = M
@R13
M = D
@1
D = A
@SP
D = M - D
@ARG
M = D
@CALL_END2
D = A
@SP
A = M
M = D
@SP
M = M + 1
@LCL
D = M
@SP
A = M
M = D
@SP
M = M + 1
@R13
D = M
@SP
A = M
M = D
@SP
M = M + 1
@THIS
D = M
@SP
A = M
M = D
@SP
M = M + 1
@THAT
D = M
@SP
A = M
M = D
@SP
M = M + 1
@SP
D = M
@LCL
M = D
@Main.fibonacci
0; JMP
(CALL_END2)

//Push
@0
D = A
@ARG
A = M + D
D = M
@SP
A = M
M = D
@SP
M = M + 1
//Push
@1
D = A
@SP
A = M
M = D
@SP
M = M + 1
//Sub
@SP
M = M - 1
A = M
D = M
@SP
M = M - 1
A = M
D = M - D
@SP
A = M
M = D
@SP
M = M + 1
(CALL_START3)
@ARG
D = M
@R13
M = D
@1
D = A
@SP
D = M - D
@ARG
M = D
@CALL_END3
D = A
@SP
A = M
M = D
@SP
M = M + 1
@LCL
D = M
@SP
A = M
M = D
@SP
M = M + 1
@R13
D = M
@SP
A = M
M = D
@SP
M = M + 1
@THIS
D = M
@SP
A = M
M = D
@SP
M = M + 1
@THAT
D = M
@SP
A = M
M = D
@SP
M = M + 1
@SP
D = M
@LCL
M = D
@Main.fibonacci
0; JMP
(CALL_END3)

//Add
@SP
M = M - 1
A = M
D = M
@SP
M = M - 1
A = M
D = M + D
@SP
A = M
M = D
@SP
M = M + 1
//Return
@SP
A = M - 1
D = M
@R15
M = D
@ARG
D = M
@R13
M = D
@LCL
D = M
@SP
M = D - 1
A = M
D = M
@THAT
M = D
@SP
M = M - 1
A = M
D = M
@THIS
M = D
@SP
M = M - 1
A = M
D = M
@ARG
M = D
@SP
M = M - 1
A = M
D = M
@LCL
M = D
@SP
M = M - 1
A = M
D = M
@R14
M = D
@R15
D = M
@R13
A = M
M = D
@R13
D = M
@SP
M = D + 1
@R14
A = M
A; JMP
