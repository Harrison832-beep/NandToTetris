from Segment import Segment

class Pointer(Segment):
    def push(self, index):
        assembly = f'''// push pointer {index}
            @{'THIS' if index==0 else 'THAT'}
            D = M
            
            @SP
            A = M
            M = D
            
            @SP
            M = M + 1
            '''
        return assembly
        
    def pop(self, index):
        assembly = f'''// pop pointer {index}
            @SP
            M = M - 1
            A = M
            D = M
            
            @{'THIS' if index==0 else 'THAT'}
            M = D
            '''
        return assembly


class This(Segment):
    def push(self, index):
        assembly = f'''// push this {index}
            @{index}
            D = A
            @THIS
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
        assembly = f'''// pop this {index}
            @{index}
            D = A
            @THIS
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

class That(Segment):
    def push(self, index):
        assembly = f'''// push that {index}
            @{index}
            D = A
            @THAT
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
        assembly = f'''// pop that {index}
            @{index}
            D = A
            @THAT
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
