// function Sys.init init
// label
    (Sys.init)
        
// push constant 4
        @4
        D = A
        
        @SP
        A = M
        M = D
        
        @SP
        M = M + 1
        
// call
        @Main.fibonacci$ret.0
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
        
        @ARG
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
        @5
        D = D - A
        @1
        D = D - A
        @ARG
        M = D
        
        @SP
        D = M
        @LCL
        M = D
        
        @Main.fibonacci
        0; JMP
        
    (Main.fibonacci$ret.0)
        
// label
    (WHILE)
        
// goto
        @WHILE
        0; JMP
        
// function Main.fibonacci init
// label
    (Main.fibonacci)
        
// push argument 0
            @0
            D = A
            @ARG
            D = M + D
            A = D
            D = M
            @SP
            A = M
            M = D
            
            @SP
            M = M + 1
            
// push constant 2
        @2
        D = A
        
        @SP
        A = M
        M = D
        
        @SP
        M = M + 1
        
// lt0
        @SP
        M = M - 1
        A = M
        D = M
        
        @SP
        M = M - 1
        A = M
        D = M - D
        
        @LT_TRUE_0
        D; JLT
        @LT_FALSE_0
        0; JMP
        
        (LT_TRUE_0)
            @SP
            A = M
            M = -1
            
            @LT_END_0
            0; JMP
        
        (LT_FALSE_0)
            @SP
            A = M
            M = 0
            
            @LT_END_0
            0; JMP
        
        (LT_END_0)
            @SP
            M = M + 1
        
// if-goto
        @SP
        M = M - 1
        A = M
        D = M
        @IF_TRUE
        D; JNE
        
// goto
        @IF_FALSE
        0; JMP
        
// label
    (IF_TRUE)
        
// push argument 0
            @0
            D = A
            @ARG
            D = M + D
            A = D
            D = M
            @SP
            A = M
            M = D
            
            @SP
            M = M + 1
            
// return
        @LCL
        D = M
        @R13
        M = D
        
        @5
        D = A
        @R13
        A = M - D
        D = M
        @R14
        M = D
        
        @SP
        M = M - 1
        A = M
        D = M
        @ARG
        A = M
        M = D
        
        @ARG
        D = M + 1
        @SP
        M = D
        
        @R13
        D = M - 1
        A = D
        D = M
        @THAT
        M = D
        
        @2
        D = A
        @R13
        D = M - D
        A = D
        D = M
        @THIS
        M = D
        
        @3
        D = A
        @R13
        D = M - D
        A = D
        D = M
        @ARG
        M = D
        
        @4
        D = A
        @R13
        D = M - D
        A = D
        D = M
        @LCL
        M = D
        
        @R14
        A = M
        0; JMP
        
// label
    (IF_FALSE)
        
// push argument 0
            @0
            D = A
            @ARG
            D = M + D
            A = D
            D = M
            @SP
            A = M
            M = D
            
            @SP
            M = M + 1
            
// push constant 2
        @2
        D = A
        
        @SP
        A = M
        M = D
        
        @SP
        M = M + 1
        
// sub
        @SP
        M = M - 1
        A = M
        D = M
        
        @SP
        M = M - 1
        A = M
        M = M - D
        
        @SP
        M = M + 1
        
// call
        @Main.fibonacci$ret.1
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
        
        @ARG
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
        @5
        D = D - A
        @1
        D = D - A
        @ARG
        M = D
        
        @SP
        D = M
        @LCL
        M = D
        
        @Main.fibonacci
        0; JMP
        
    (Main.fibonacci$ret.1)
        
// push argument 0
            @0
            D = A
            @ARG
            D = M + D
            A = D
            D = M
            @SP
            A = M
            M = D
            
            @SP
            M = M + 1
            
// push constant 1
        @1
        D = A
        
        @SP
        A = M
        M = D
        
        @SP
        M = M + 1
        
// sub
        @SP
        M = M - 1
        A = M
        D = M
        
        @SP
        M = M - 1
        A = M
        M = M - D
        
        @SP
        M = M + 1
        
// call
        @Main.fibonacci$ret.2
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
        
        @ARG
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
        @5
        D = D - A
        @1
        D = D - A
        @ARG
        M = D
        
        @SP
        D = M
        @LCL
        M = D
        
        @Main.fibonacci
        0; JMP
        
    (Main.fibonacci$ret.2)
        
// add
        @SP
        M = M - 1
        A = M
        D = M
        
        @SP
        M = M - 1
        A = M
        M = M + D
        
        @SP
        M = M + 1
        
// return
        @LCL
        D = M
        @R13
        M = D
        
        @5
        D = A
        @R13
        A = M - D
        D = M
        @R14
        M = D
        
        @SP
        M = M - 1
        A = M
        D = M
        @ARG
        A = M
        M = D
        
        @ARG
        D = M + 1
        @SP
        M = D
        
        @R13
        D = M - 1
        A = D
        D = M
        @THAT
        M = D
        
        @2
        D = A
        @R13
        D = M - D
        A = D
        D = M
        @THIS
        M = D
        
        @3
        D = A
        @R13
        D = M - D
        A = D
        D = M
        @ARG
        M = D
        
        @4
        D = A
        @R13
        D = M - D
        A = D
        D = M
        @LCL
        M = D
        
        @R14
        A = M
        0; JMP
        
