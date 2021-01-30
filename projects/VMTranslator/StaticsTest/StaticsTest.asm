
(Sys.init)
//Push
@6
D = A
@SP
A = M
M = D
@SP
M = M + 1
//Push
@8
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
@2
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
@Class1.set
0; JMP
(CALL_END1)

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
@23
D = A
@SP
A = M
M = D
@SP
M = M + 1
//Push
@15
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
@2
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
@Class2.set
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
(CALL_START3)
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
@Class1.get
0; JMP
(CALL_END3)

(CALL_START4)
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
@CALL_END4
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
@Class2.get
0; JMP
(CALL_END4)

(WHILE)
@WHILE
0; JMP

(Class1.set)
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
//Pop
@SP
A = M - 1
D = M
@0
D = A
@static
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
@1
D = A
@ARG
A = M + D
D = M
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
@static
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

(Class1.get)
//Push
@0
D = A
@static
A = D + A
D = M
@SP
A = M
M = D
@SP
M = M + 1
//Push
@1
D = A
@static
A = D + A
D = M
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

(Class2.set)
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
//Pop
@SP
A = M - 1
D = M
@2
D = A
@static
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
@1
D = A
@ARG
A = M + D
D = M
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
@static
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

(Class2.get)
//Push
@2
D = A
@static
A = D + A
D = M
@SP
A = M
M = D
@SP
M = M + 1
//Push
@3
D = A
@static
A = D + A
D = M
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
