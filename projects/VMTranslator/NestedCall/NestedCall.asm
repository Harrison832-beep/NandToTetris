
(Sys.init)
//Push
@4000
D = A
@SP
A = M
M = D
@SP
M = M + 1
//Pop
@SP
A = M - 1
D = M
@THIS
M = D
@SP
M = M - 1
//Push
@5000
D = A
@SP
A = M
M = D
@SP
M = M + 1
//Pop
@SP
A = M - 1
D = M
@THAT
M = D
@SP
M = M - 1
(CALL_START1)
@ARG
D = M
@R13
M = D
@0
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
@Sys.main
0; JMP
(CALL_END1)

//Pop
@SP
A = M - 1
D = M
@1
D = A
@R5
A = A + D
D = A
@R13
M = D
@SP
A = M - 1
D = M
@R13
A = M
M = D
@SP
M = M - 1
(LOOP)
@LOOP
0; JMP

(Sys.main)
@SP
A = M
M = 0
@SP
M = M + 1
@SP
A = M
M = 0
@SP
M = M + 1
@SP
A = M
M = 0
@SP
M = M + 1
@SP
A = M
M = 0
@SP
M = M + 1
@SP
A = M
M = 0
@SP
M = M + 1
//Push
@4001
D = A
@SP
A = M
M = D
@SP
M = M + 1
//Pop
@SP
A = M - 1
D = M
@THIS
M = D
@SP
M = M - 1
//Push
@5001
D = A
@SP
A = M
M = D
@SP
M = M + 1
//Pop
@SP
A = M - 1
D = M
@THAT
M = D
@SP
M = M - 1
//Push
@200
D = A
@SP
A = M
M = D
@SP
M = M + 1
//Pop
@SP
A = M - 1
D = M
@1
D = A
@LCL
A = M + D
D = A
@R13
M = D
@SP
A = M - 1
D = M
@R13
A = M
M = D
@SP
M = M - 1
//Push
@40
D = A
@SP
A = M
M = D
@SP
M = M + 1
//Pop
@SP
A = M - 1
D = M
@2
D = A
@LCL
A = M + D
D = A
@R13
M = D
@SP
A = M - 1
D = M
@R13
A = M
M = D
@SP
M = M - 1
//Push
@6
D = A
@SP
A = M
M = D
@SP
M = M + 1
//Pop
@SP
A = M - 1
D = M
@3
D = A
@LCL
A = M + D
D = A
@R13
M = D
@SP
A = M - 1
D = M
@R13
A = M
M = D
@SP
M = M - 1
//Push
@123
D = A
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
@Sys.add12
0; JMP
(CALL_END2)

//Pop
@SP
A = M - 1
D = M
@0
D = A
@R5
A = A + D
D = A
@R13
M = D
@SP
A = M - 1
D = M
@R13
A = M
M = D
@SP
M = M - 1
//Push
@0
D = A
@LCL
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
@LCL
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
@LCL
A = M + D
D = M
@SP
A = M
M = D
@SP
M = M + 1
//Push
@3
D = A
@LCL
A = M + D
D = M
@SP
A = M
M = D
@SP
M = M + 1
//Push
@4
D = A
@LCL
A = M + D
D = M
@SP
A = M
M = D
@SP
M = M + 1
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

(Sys.add12)
//Push
@4002
D = A
@SP
A = M
M = D
@SP
M = M + 1
//Pop
@SP
A = M - 1
D = M
@THIS
M = D
@SP
M = M - 1
//Push
@5002
D = A
@SP
A = M
M = D
@SP
M = M + 1
//Pop
@SP
A = M - 1
D = M
@THAT
M = D
@SP
M = M - 1
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
@12
D = A
@SP
A = M
M = D
@SP
M = M + 1
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
