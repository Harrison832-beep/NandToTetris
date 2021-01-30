from Segment import Segment

class Constant(Segment):
    def push(self, index):
        assembly = f'''// push constant {index}
        @{index}
        D = A
        
        @SP
        A = M
        M = D
        
        @SP
        M = M + 1
        '''
        
        return assembly
        