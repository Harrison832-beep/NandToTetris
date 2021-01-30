(Sys.init)
@256
D = A
@SP
M = D
@300
D = A
@LCL
M = D
@400
D = A
@ARG
M = D
@3000
D = A
@THIS
M = D
@3010
D = A
@THAT
M = D

(MAIN)
//Push
@4
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
@0
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
@2
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
