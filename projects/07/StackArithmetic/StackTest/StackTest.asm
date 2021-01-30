// push constant 17
        @17
        D = A
        
        @SP
        A = M
        M = D
        
        @SP
        M = M + 1
        
// push constant 17
        @17
        D = A
        
        @SP
        A = M
        M = D
        
        @SP
        M = M + 1
        
// eq0
        @SP
        M = M - 1
        A = M
        D = M
        
        @SP
        M = M - 1
        A = M
        D = M - D
        
        @EQ_TRUE_0
        D; JEQ
        @EQ_FALSE_0
        0; JMP
        
        (EQ_TRUE_0)
            @SP
            A = M
            M = -1
            
            @EQ_END_0
            0; JMP
        
        (EQ_FALSE_0)
            @SP
            A = M
            M = 0
            
            @EQ_END_0
            0; JMP
        
        (EQ_END_0)
            @SP
            M = M + 1
        
// push constant 17
        @17
        D = A
        
        @SP
        A = M
        M = D
        
        @SP
        M = M + 1
        
// push constant 16
        @16
        D = A
        
        @SP
        A = M
        M = D
        
        @SP
        M = M + 1
        
// eq1
        @SP
        M = M - 1
        A = M
        D = M
        
        @SP
        M = M - 1
        A = M
        D = M - D
        
        @EQ_TRUE_1
        D; JEQ
        @EQ_FALSE_1
        0; JMP
        
        (EQ_TRUE_1)
            @SP
            A = M
            M = -1
            
            @EQ_END_1
            0; JMP
        
        (EQ_FALSE_1)
            @SP
            A = M
            M = 0
            
            @EQ_END_1
            0; JMP
        
        (EQ_END_1)
            @SP
            M = M + 1
        
// push constant 16
        @16
        D = A
        
        @SP
        A = M
        M = D
        
        @SP
        M = M + 1
        
// push constant 17
        @17
        D = A
        
        @SP
        A = M
        M = D
        
        @SP
        M = M + 1
        
// eq2
        @SP
        M = M - 1
        A = M
        D = M
        
        @SP
        M = M - 1
        A = M
        D = M - D
        
        @EQ_TRUE_2
        D; JEQ
        @EQ_FALSE_2
        0; JMP
        
        (EQ_TRUE_2)
            @SP
            A = M
            M = -1
            
            @EQ_END_2
            0; JMP
        
        (EQ_FALSE_2)
            @SP
            A = M
            M = 0
            
            @EQ_END_2
            0; JMP
        
        (EQ_END_2)
            @SP
            M = M + 1
        
// push constant 892
        @892
        D = A
        
        @SP
        A = M
        M = D
        
        @SP
        M = M + 1
        
// push constant 891
        @891
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
        
// push constant 891
        @891
        D = A
        
        @SP
        A = M
        M = D
        
        @SP
        M = M + 1
        
// push constant 892
        @892
        D = A
        
        @SP
        A = M
        M = D
        
        @SP
        M = M + 1
        
// lt1
        @SP
        M = M - 1
        A = M
        D = M
        
        @SP
        M = M - 1
        A = M
        D = M - D
        
        @LT_TRUE_1
        D; JLT
        @LT_FALSE_1
        0; JMP
        
        (LT_TRUE_1)
            @SP
            A = M
            M = -1
            
            @LT_END_1
            0; JMP
        
        (LT_FALSE_1)
            @SP
            A = M
            M = 0
            
            @LT_END_1
            0; JMP
        
        (LT_END_1)
            @SP
            M = M + 1
        
// push constant 891
        @891
        D = A
        
        @SP
        A = M
        M = D
        
        @SP
        M = M + 1
        
// push constant 891
        @891
        D = A
        
        @SP
        A = M
        M = D
        
        @SP
        M = M + 1
        
// lt2
        @SP
        M = M - 1
        A = M
        D = M
        
        @SP
        M = M - 1
        A = M
        D = M - D
        
        @LT_TRUE_2
        D; JLT
        @LT_FALSE_2
        0; JMP
        
        (LT_TRUE_2)
            @SP
            A = M
            M = -1
            
            @LT_END_2
            0; JMP
        
        (LT_FALSE_2)
            @SP
            A = M
            M = 0
            
            @LT_END_2
            0; JMP
        
        (LT_END_2)
            @SP
            M = M + 1
        
// push constant 32767
        @32767
        D = A
        
        @SP
        A = M
        M = D
        
        @SP
        M = M + 1
        
// push constant 32766
        @32766
        D = A
        
        @SP
        A = M
        M = D
        
        @SP
        M = M + 1
        
// gt0
        @SP
        M = M - 1
        A = M
        D = M
        
        @SP
        M = M - 1
        A = M
        D = M - D
        
        @GT_TRUE_0
        D; JGT
        @GT_FALSE_0
        0; JMP
        
        (GT_TRUE_0)
            @SP
            A = M
            M = -1
            
            @GT_END_0
            0; JMP
        
        (GT_FALSE_0)
            @SP
            A = M
            M = 0
            
            @GT_END_0
            0; JMP
        
        (GT_END_0)
            @SP
            M = M + 1
        
// push constant 32766
        @32766
        D = A
        
        @SP
        A = M
        M = D
        
        @SP
        M = M + 1
        
// push constant 32767
        @32767
        D = A
        
        @SP
        A = M
        M = D
        
        @SP
        M = M + 1
        
// gt1
        @SP
        M = M - 1
        A = M
        D = M
        
        @SP
        M = M - 1
        A = M
        D = M - D
        
        @GT_TRUE_1
        D; JGT
        @GT_FALSE_1
        0; JMP
        
        (GT_TRUE_1)
            @SP
            A = M
            M = -1
            
            @GT_END_1
            0; JMP
        
        (GT_FALSE_1)
            @SP
            A = M
            M = 0
            
            @GT_END_1
            0; JMP
        
        (GT_END_1)
            @SP
            M = M + 1
        
// push constant 32766
        @32766
        D = A
        
        @SP
        A = M
        M = D
        
        @SP
        M = M + 1
        
// push constant 32766
        @32766
        D = A
        
        @SP
        A = M
        M = D
        
        @SP
        M = M + 1
        
// gt2
        @SP
        M = M - 1
        A = M
        D = M
        
        @SP
        M = M - 1
        A = M
        D = M - D
        
        @GT_TRUE_2
        D; JGT
        @GT_FALSE_2
        0; JMP
        
        (GT_TRUE_2)
            @SP
            A = M
            M = -1
            
            @GT_END_2
            0; JMP
        
        (GT_FALSE_2)
            @SP
            A = M
            M = 0
            
            @GT_END_2
            0; JMP
        
        (GT_END_2)
            @SP
            M = M + 1
        
// push constant 57
        @57
        D = A
        
        @SP
        A = M
        M = D
        
        @SP
        M = M + 1
        
// push constant 31
        @31
        D = A
        
        @SP
        A = M
        M = D
        
        @SP
        M = M + 1
        
// push constant 53
        @53
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
        
// push constant 112
        @112
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
        
// neg
        @SP
        M = M - 1
        A = M
        M = -M
        
        @SP
        M = M + 1
        
// and
        @SP
        M = M - 1
        A = M
        D = M
        
        @SP
        M = M - 1
        A = M
        M = M & D
        
        @SP
        M = M + 1
        
// push constant 82
        @82
        D = A
        
        @SP
        A = M
        M = D
        
        @SP
        M = M + 1
        
// or
        @SP
        M = M - 1
        A = M
        D = M
        
        @SP
        M = M - 1
        A = M
        M = M | D
        
        @SP
        M = M + 1
        
// neg
        @SP
        M = M - 1
        A = M
        M = !M
        
        @SP
        M = M + 1
        
