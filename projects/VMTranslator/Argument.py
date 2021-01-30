from Segment import Segment

class Argument(Segment):
    def push(self, index):
        assembly = f'''// push argument {index}
            @{index}
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
            '''
        return assembly
        
    def pop(self, index):
        assembly = f'''// pop argument {index}
            @{index}
            D = A
            @ARG
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
