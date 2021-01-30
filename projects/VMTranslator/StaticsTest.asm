// function Sys.init init
// label
    (Sys.init)
        
// push constant 6
        @6
        D = A
        
        @SP
        A = M
        M = D
        
        @SP
        M = M + 1
        
// push constant 8
        @8
        D = A
        
        @SP
        A = M
        M = D
        
        @SP
        M = M + 1
        
// call
        @Class1.set$ret.0
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
        @2
        D = D - A
        @ARG
        M = D
        
        @SP
        D = M
        @LCL
        M = D
        
        @Class1.set
        0; JMP
        
    (Class1.set$ret.0)
        
// pop temp 0
            @SP
            M = M - 1
            A = M
            D = M
            
            @5
            M = D
            
// push constant 23
        @23
        D = A
        
        @SP
        A = M
        M = D
        
        @SP
        M = M + 1
        
// push constant 15
        @15
        D = A
        
        @SP
        A = M
        M = D
        
        @SP
        M = M + 1
        
// call
        @Class2.set$ret.0
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
        @2
        D = D - A
        @ARG
        M = D
        
        @SP
        D = M
        @LCL
        M = D
        
        @Class2.set
        0; JMP
        
    (Class2.set$ret.0)
        
// pop temp 0
            @SP
            M = M - 1
            A = M
            D = M
            
            @5
            M = D
            
// call
        @Class1.get$ret.0
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
        
        @Class1.get
        0; JMP
        
    (Class1.get$ret.0)
        
// call
        @Class2.get$ret.0
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
        
        @Class2.get
        0; JMP
        
    (Class2.get$ret.0)
        
// label
    (WHILE)
        
// goto
        @WHILE
        0; JMP
        
// function Class1.set init
// label
    (Class1.set)
        
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
            
// pop static 0 (Class1)
            @SP
            M = M - 1
            A = M
            D = M
            
            @Class1.0
            M = D
            
// push argument 1
            @1
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
            
// pop static 1 (Class1)
            @SP
            M = M - 1
            A = M
            D = M
            
            @Class1.1
            M = D
            
// push constant 0
        @0
        D = A
        
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
        
// function Class1.get init
// label
    (Class1.get)
        
// push static 0 (Class1)
            @Class1.0
            D = M
            
            @SP
            A = M
            M = D
            
            @SP
            M = M + 1
            
// push static 1 (Class1)
            @Class1.1
            D = M
            
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
        
// function Class2.set init
// label
    (Class2.set)
        
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
            
// pop static 0 (Class2)
            @SP
            M = M - 1
            A = M
            D = M
            
            @Class2.0
            M = D
            
// push argument 1
            @1
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
            
// pop static 1 (Class2)
            @SP
            M = M - 1
            A = M
            D = M
            
            @Class2.1
            M = D
            
// push constant 0
        @0
        D = A
        
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
        
// function Class2.get init
// label
    (Class2.get)
        
// push static 0 (Class2)
            @Class2.0
            D = M
            
            @SP
            A = M
            M = D
            
            @SP
            M = M + 1
            
// push static 1 (Class2)
            @Class2.1
            D = M
            
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
        
// function Class1.set init
// label
    (Class1.set)
        
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
            
// pop static 0 (Class1)
            @SP
            M = M - 1
            A = M
            D = M
            
            @Class1.0
            M = D
            
// push argument 1
            @1
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
            
// pop static 1 (Class1)
            @SP
            M = M - 1
            A = M
            D = M
            
            @Class1.1
            M = D
            
// push constant 0
        @0
        D = A
        
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
        
// function Class1.get init
// label
    (Class1.get)
        
// push static 0 (Class1)
            @Class1.0
            D = M
            
            @SP
            A = M
            M = D
            
            @SP
            M = M + 1
            
// push static 1 (Class1)
            @Class1.1
            D = M
            
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
        
// function Class2.set init
// label
    (Class2.set)
        
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
            
// pop static 0 (Class2)
            @SP
            M = M - 1
            A = M
            D = M
            
            @Class2.0
            M = D
            
// push argument 1
            @1
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
            
// pop static 1 (Class2)
            @SP
            M = M - 1
            A = M
            D = M
            
            @Class2.1
            M = D
            
// push constant 0
        @0
        D = A
        
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
        
// function Class2.get init
// label
    (Class2.get)
        
// push static 0 (Class2)
            @Class2.0
            D = M
            
            @SP
            A = M
            M = D
            
            @SP
            M = M + 1
            
// push static 1 (Class2)
            @Class2.1
            D = M
            
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
        
