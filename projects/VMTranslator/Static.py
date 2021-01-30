from Segment import Segment

class Static(Segment):
    def push(self, index):
        assembly = f'''// push static {index} ({self.filename})
            @{self.filename}.{index}
            D = M
            
            @SP
            A = M
            M = D
            
            @SP
            M = M + 1
            '''
        return assembly
        
    def pop(self, index):
        assembly = f'''// pop static {index} ({self.filename})
            @SP
            M = M - 1
            A = M
            D = M
            
            @{self.filename}.{index}
            M = D
            '''
        return assembly