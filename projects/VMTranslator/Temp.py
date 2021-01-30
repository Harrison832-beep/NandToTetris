from Segment import Segment

class Temp(Segment):
    def push(self, index):
        assembly = f'''// push temp {index}
            @{index}
            D = A
            @5
            A = A + D
            D = M
            @SP
            A = M
            M = D
            
            @SP
            M = M + 1
            '''
        return assembly
        
    def pop(self, index):
        assembly = f'''// pop temp {index}
            @SP
            M = M - 1
            A = M
            D = M
            
            @{5+index}
            M = D
            '''
        return assembly
        