from CommandEnum import CommandEnum
class Parser:
    def __init__(self, filename):
        """Opens the input file/stream and gets ready to parse it"""
        self.inputfile = open(filename, 'r')
        self.filename = filename
        self.current = None
        self.cur_line = None

    def hasMoreCommands(self):
        """Are there more commands in the input?"""
        if self.cur_line is not None:
            return True
        
        line = str(self.inputfile.readline())
        while line != '':
            comment1 = line.find("//")
            comment2 = line.find("/*")
            comment3 = line.find("*/")
            
            if comment1 == 0 or comment2 == 0 or comment3 == 0:
                line = str(self.inputfile.readline())
            elif line.isspace():
                line = str(self.inputfile.readline())
            else:
                self.cur_line = line
                return True
        
        return False
        
    
    def advance(self):
        """Reads the next command from the input and makes it the 
        current command. Should called only if hasMoreCommands() is true.
        Initially there is no current command"""
        if not self.hasMoreCommands():
            return None
        
        line = self.cur_line
        comment1 = line.find("//")
        comment2 = line.find("/*")
        comment3 = line.find("*/")
        
        if comment1 != -1:
            line = line[:comment1]
        elif comment2 != -1:
            line = line[:comment2]
        elif comment3 != -1:
            line = line[comment3+2:]
        
        line = line.strip()
        self.current = line
        self.cur_line = None
        
    
    def commandType(self):
        """Returns a constant representing the type of the current command.
        C_ARITHMETIC is returned for all the arithemtic/logical commands."""
        if self.current is None:
            raise ValueError("Current is None")
        
        # arithmetic_regex = re.compile("{add|sub|neg|eq|gt|lt|and|or|not}")
        if self.current in ["add", "sub", "neg", "eq", "gt", "lt", "and", "or", "not"]:
           return CommandEnum.C_ARITHMETIC
        elif "push" in self.current:
            return CommandEnum.C_PUSH
        elif "pop" in self.current:
            return CommandEnum.C_POP
        elif "goto" in self.current and "if-goto" not in self.current:
            return CommandEnum.C_GOTO
        elif "if-goto" in self.current:
            return CommandEnum.C_IF_GOTO
        elif "label" in self.current:
            return CommandEnum.C_LABEL
        elif "function" in self.current:
            return CommandEnum.C_FUNCTION
        elif "return" in self.current:
            return CommandEnum.C_RETURN
        elif "call" in self.current:
            return CommandEnum.C_CALL
        
    
    def arg1(self):
        """Returns the first argument of the current command.
        In the case of C_ARITHMETIC, the command iteself (add, sub, etc.) is 
        returned. Should not be called if the current command is C_RETURN"""
        if self.commandType() == CommandEnum.C_RETURN:
            raise ValueError("Should not be called when the current command is C_RETURN")
        
        if self.commandType() == CommandEnum.C_ARITHMETIC:
            return self.current
        else:
            return self.current.split()[1]
        
    
    def arg2(self):
        """Returns the second argument of the current command.
        Should be called only if the current command is 
        C_PUSH, C_POP, C_FUNCTION, or C_CALL"""
        if self.commandType() not in [CommandEnum.C_PUSH, CommandEnum.C_POP, CommandEnum.C_FUNCTION, CommandEnum.C_CALL]:
            raise ValueError("Should be called only if the current command is C_PUSH, C_POP, C_FUNCTION, or C_CALL")

        return self.current.split()[2]
        
        
        