class Arithmetic:
    def tranlsate(self):
        pass

class Add(Arithmetic):
    def translate(self):
        # SP--; value1 = *SP; SP--; *SP = *SP + value1
        assembly = '''// add
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
        '''

        return assembly

class Sub(Arithmetic):
    def translate(self):
        assembly = '''// sub
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
        '''

        return assembly

class Neg(Arithmetic):
    def translate(self):
        assembly = '''// neg
        @SP
        M = M - 1
        A = M
        M = -M
        
        @SP
        M = M + 1
        '''

        return assembly


class Eq(Arithmetic):
    index = 0
    
    def translate(self):
        assembly = f'''// eq{Eq.index}
        @SP
        M = M - 1
        A = M
        D = M
        
        @SP
        M = M - 1
        A = M
        D = M - D
        
        @EQ_TRUE_{Eq.index}
        D; JEQ
        @EQ_FALSE_{Eq.index}
        0; JMP
        
        (EQ_TRUE_{Eq.index})
            @SP
            A = M
            M = -1
            
            @EQ_END_{Eq.index}
            0; JMP
        
        (EQ_FALSE_{Eq.index})
            @SP
            A = M
            M = 0
            
            @EQ_END_{Eq.index}
            0; JMP
        
        (EQ_END_{Eq.index})
            @SP
            M = M + 1
        '''
        
        Eq.index += 1
        
        return assembly

class Gt(Arithmetic):
    index = 0
    def translate(self):
        assembly = f'''// gt{Gt.index}
        @SP
        M = M - 1
        A = M
        D = M
        
        @SP
        M = M - 1
        A = M
        D = M - D
        
        @GT_TRUE_{Gt.index}
        D; JGT
        @GT_FALSE_{Gt.index}
        0; JMP
        
        (GT_TRUE_{Gt.index})
            @SP
            A = M
            M = -1
            
            @GT_END_{Gt.index}
            0; JMP
        
        (GT_FALSE_{Gt.index})
            @SP
            A = M
            M = 0
            
            @GT_END_{Gt.index}
            0; JMP
        
        (GT_END_{Gt.index})
            @SP
            M = M + 1
        '''
        
        Gt.index += 1
        
        return assembly

class Lt(Arithmetic):
    index = 0
    def translate(self):
        assembly = f'''// lt{Lt.index}
        @SP
        M = M - 1
        A = M
        D = M
        
        @SP
        M = M - 1
        A = M
        D = M - D
        
        @LT_TRUE_{Lt.index}
        D; JLT
        @LT_FALSE_{Lt.index}
        0; JMP
        
        (LT_TRUE_{Lt.index})
            @SP
            A = M
            M = -1
            
            @LT_END_{Lt.index}
            0; JMP
        
        (LT_FALSE_{Lt.index})
            @SP
            A = M
            M = 0
            
            @LT_END_{Lt.index}
            0; JMP
        
        (LT_END_{Lt.index})
            @SP
            M = M + 1
        '''
        
        Lt.index += 1
        
        return assembly

class And(Arithmetic):
    def translate(self):
        assembly = '''// and
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
        '''

        return assembly

        
class Or(Arithmetic):
    def translate(self):
        assembly = '''// or
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
        '''

        return assembly

        
class Not(Arithmetic):
    def translate(self):
        assembly = '''// neg
        @SP
        M = M - 1
        A = M
        M = !M
        
        @SP
        M = M + 1
        '''

        return assembly

