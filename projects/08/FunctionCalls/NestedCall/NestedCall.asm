// Bootstrap code
        // SP = 256
        @256
        D = A
        @SP
        M = D
        // call Sys.init
        
// call
        @Sys.init$ret.0
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
        @0
        D = D - A
        @ARG
        M = D
        
        @SP
        D = M
        @LCL
        M = D
        
        @Sys.init
        0; JMP
        
    (Sys.init$ret.0)
        

        // Infinite loop
    (END)
        @END
        0; JMP
        
// function Sys.init init
// label
    (Sys.init)
        
// push constant 4000
        @4000
        D = A
        
        @SP
        A = M
        M = D
        
        @SP
        M = M + 1
        
// pop pointer 0
            @SP
            M = M - 1
            A = M
            D = M
            
            @THIS
            M = D
            
// push constant 5000
        @5000
        D = A
        
        @SP
        A = M
        M = D
        
        @SP
        M = M + 1
        
// pop pointer 1
            @SP
            M = M - 1
            A = M
            D = M
            
            @THAT
            M = D
            
// call
        @Sys.main$ret.0
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
        @0
        D = D - A
        @ARG
        M = D
        
        @SP
        D = M
        @LCL
        M = D
        
        @Sys.main
        0; JMP
        
    (Sys.main$ret.0)
        
// pop temp 1
            @SP
            M = M - 1
            A = M
            D = M
            
            @6
            M = D
            
// label
    (LOOP)
        
// goto
        @LOOP
        0; JMP
        
// function Sys.main init
// label
    (Sys.main)
        
// push constant 0
        @0
        D = A
        
        @SP
        A = M
        M = D
        
        @SP
        M = M + 1
        
// push constant 0
        @0
        D = A
        
        @SP
        A = M
        M = D
        
        @SP
        M = M + 1
        
// push constant 0
        @0
        D = A
        
        @SP
        A = M
        M = D
        
        @SP
        M = M + 1
        
// push constant 0
        @0
        D = A
        
        @SP
        A = M
        M = D
        
        @SP
        M = M + 1
        
// push constant 0
        @0
        D = A
        
        @SP
        A = M
        M = D
        
        @SP
        M = M + 1
        
// push constant 4001
        @4001
        D = A
        
        @SP
        A = M
        M = D
        
        @SP
        M = M + 1
        
// pop pointer 0
            @SP
            M = M - 1
            A = M
            D = M
            
            @THIS
            M = D
            
// push constant 5001
        @5001
        D = A
        
        @SP
        A = M
        M = D
        
        @SP
        M = M + 1
        
// pop pointer 1
            @SP
            M = M - 1
            A = M
            D = M
            
            @THAT
            M = D
            
// push constant 200
        @200
        D = A
        
        @SP
        A = M
        M = D
        
        @SP
        M = M + 1
        
// pop local 1
            @1
            D = A
            @LCL
            D = M + D
            
            @R13
            M = D
            
            @SP
            M = M - 1
            A = M
            D = M
            
            @R13
            A = M
            M = D
            
// push constant 40
        @40
        D = A
        
        @SP
        A = M
        M = D
        
        @SP
        M = M + 1
        
// pop local 2
            @2
            D = A
            @LCL
            D = M + D
            
            @R13
            M = D
            
            @SP
            M = M - 1
            A = M
            D = M
            
            @R13
            A = M
            M = D
            
// push constant 6
        @6
        D = A
        
        @SP
        A = M
        M = D
        
        @SP
        M = M + 1
        
// pop local 3
            @3
            D = A
            @LCL
            D = M + D
            
            @R13
            M = D
            
            @SP
            M = M - 1
            A = M
            D = M
            
            @R13
            A = M
            M = D
            
// push constant 123
        @123
        D = A
        
        @SP
        A = M
        M = D
        
        @SP
        M = M + 1
        
// call
        @Sys.add12$ret.0
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
        
        @Sys.add12
        0; JMP
        
    (Sys.add12$ret.0)
        
// pop temp 0
            @SP
            M = M - 1
            A = M
            D = M
            
            @5
            M = D
            
// push local 0
            @0
            D = A
            @LCL
            D = M + D
            A = D
            D = M
            @SP
            A = M
            M = D
            
            @SP
            M = M + 1
            
// push local 1
            @1
            D = A
            @LCL
            D = M + D
            A = D
            D = M
            @SP
            A = M
            M = D
            
            @SP
            M = M + 1
            
// push local 2
            @2
            D = A
            @LCL
            D = M + D
            A = D
            D = M
            @SP
            A = M
            M = D
            
            @SP
            M = M + 1
            
// push local 3
            @3
            D = A
            @LCL
            D = M + D
            A = D
            D = M
            @SP
            A = M
            M = D
            
            @SP
            M = M + 1
            
// push local 4
            @4
            D = A
            @LCL
            D = M + D
            A = D
            D = M
            @SP
            A = M
            M = D
            
            @SP
            M = M + 1
            
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
        
// function Sys.add12 init
// label
    (Sys.add12)
        
// push constant 4002
        @4002
        D = A
        
        @SP
        A = M
        M = D
        
        @SP
        M = M + 1
        
// pop pointer 0
            @SP
            M = M - 1
            A = M
            D = M
            
            @THIS
            M = D
            
// push constant 5002
        @5002
        D = A
        
        @SP
        A = M
        M = D
        
        @SP
        M = M + 1
        
// pop pointer 1
            @SP
            M = M - 1
            A = M
            D = M
            
            @THAT
            M = D
            
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
            
// push constant 12
        @12
        D = A
        
        @SP
        A = M
        M = D
        
        @SP
        M = M + 1
        
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
        
