from Segment import Segment

class Local(Segment):
    def push(self, index):
        assembly = f'''// push local {index}
            @{index}
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
            '''
        return assembly
        
    def pop(self, index):
        assembly = f'''// pop local {index}
            @{index}
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
            '''
        return assembly