from CommandEnum import CommandEnum
from SegmentFactory import SegmentFactory
from ArithmeticFactory import ArithmeticFactory

class CodeWriter:
    
    def __init__(self, filename):
        """Opens the output file/stream and gets ready to write into it"""
        
        if filename.find('/') != -1:
            output_filename = filename[:filename.find('/')]
        elif filename.find('.') != -1:
            output_filename = filename[:filename.find('.')]
        
        self.outputfile = open(output_filename + ".asm", 'w')
        self.fileName = filename
        self.function_dict = dict()
        
        #if "Sys" in filename:
         #   self.writeInit()
        
    def writeArithmetic(self, command):
        """Writes to the output file the assembly code that implements the 
        given arithmetic command"""
        if type(command) != str:
            raise ValueError("Command should be a string")
        factory = ArithmeticFactory()
        arithmetic_obj = factory.get_arithmetic(command)
        
        assembly = arithmetic_obj.translate()
        print(assembly, file=self.outputfile)
        
        
    def writePushPop(self, commandType, segment, index):
        """Writes to the output file the assembly code that implements the 
        given command, where command is either C_PUSH or C_POP"""
        if commandType != CommandEnum.C_PUSH and commandType != CommandEnum.C_POP:
            raise ValueError("Command should be either C_PUSH or C_POP")
        factory = SegmentFactory()
        segment_obj = factory.get_segment(segment, self.fileName)
        if commandType == CommandEnum.C_PUSH:
            assembly = segment_obj.push(index)
        elif commandType == CommandEnum.C_POP:
            assembly = segment_obj.pop(index)
        else:
            raise ValueError(f"Segment object is {segment_obj}")
        
        
        print(assembly, file=self.outputfile)
            
    def close(self):
        """Close the output file"""
        self.outputfile.close()
    
    def setFileName(self, fileName):
        """Informs the codeWriter that the translation of a new VM file
        has started (called by the main program of the VM translator)."""
        self.fileName = fileName
        
    def writeInit(self):
        """Writes the assembly instructions that effect the bootstrap code
        that initializes the VM. This code must be placed at the beginning of
        the generated *.asm file."""
        assembly = '''// Bootstrap code
        // SP = 256
        @256
        D = A
        @SP
        M = D
        // call Sys.init
        '''
        
        print(assembly, file=self.outputfile)
        
        self.writeCall("Sys.init", 0)
        
        assembly = '''
        // Infinite loop
    (END)
        @END
        0; JMP
        '''
        
        print(assembly, file=self.outputfile)
        
    
    def writeLabel(self, label):
        """Writes assembly code that effects the label command."""
        assembly = f'''// label
    ({label})
        '''
        
        print(assembly, file=self.outputfile)
        
        
    def writeGoto(self, label):
        """Writes assembly code that effects the goto command."""
        assembly = f'''// goto
        @{label}
        0; JMP
        '''
        
        print(assembly, file=self.outputfile)
    
    def writeIf(self, label):
        """Writes assembly code that effects the if-goto command."""
        assembly = f'''// if-goto
        @SP
        M = M - 1
        A = M
        D = M
        @{label}
        D; JNE
        '''
        
        print(assembly, file=self.outputfile)
        
    
    def writeFunction(self, functionName, numVars):
        """Writes assembly code that effects the function command."""
        print(f"// function {functionName} init", file=self.outputfile)
        self.writeLabel(functionName)
        
        for i in range(numVars):
            # Push local for numVars times
            self.writePushPop(CommandEnum.C_PUSH, "constant", 0)
        
        
    
    def writeCall(self, functionName, numArgs):
        """Writes assembly code that effects the call command."""
        #   push retAddrLabel
        #   push LCL
        #   push ARG
        #   push THIS
        #   push THAT
        #   ARG = SP - 5 - nArgs
        #   LCL = SP
        #   goto functionName
        # (retAddrLabel)
        
        if functionName in self.function_dict:
            count = self.function_dict[functionName]
        else:
            count = 0
            self.function_dict[functionName] = 0
        
        assembly = f'''// call
        @{functionName}$ret.{count}
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
        @{numArgs}
        D = D - A
        @ARG
        M = D
        
        @SP
        D = M
        @LCL
        M = D
        
        @{functionName}
        0; JMP
        
    ({functionName}$ret.{count})
        '''
        
        self.function_dict[functionName] += 1
        print(assembly, file=self.outputfile)
    
    def writeReturn(self):
        """Writes assembly code that effects the return command."""
        # endFrame = LCL
        # retAddr = *(endFrame - 5)
        # *ARG = pop()
        # SP = ARG + 1
        # THAT = *(endFrame - 1)
        # THIS = *(endFrame - 2)
        # ARG = *(endFrame - 3)
        # LCL = *(endFrame - 4)
        # goto retAddr
        
        assembly = '''// return
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
        '''
        
        print(assembly, file=self.outputfile)
        
    
    
    
    
    