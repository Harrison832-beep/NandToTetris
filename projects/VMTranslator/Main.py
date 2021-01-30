import sys
from CommandEnum import CommandEnum
from Parser import Parser
from CodeWriter import CodeWriter

def is_read(read, file):
    return file in read

def main():
    
    dir_name = "/"
    file_name = ""
    if sys.argv[1].find('.') == -1:
        dir_name = sys.argv[1] + "/"
        file_name = "Sys.vm"
    else:
        file_name = sys.argv[1]
    
    in_filename = dir_name + file_name
    files = [in_filename]
    read = set()
    codeWriter = None
    while len(files) > 0:
        file = files.pop(0)
        read.add(file)
        
        parser = Parser(file)
        if codeWriter is None:
            codeWriter = CodeWriter(file)
        else:
            codeWriter.setFileName(file)
        while parser.hasMoreCommands():
            parser.advance()
            command = parser.current
            commandType = parser.commandType()
            
            try:
                arg1 = parser.arg1()
            except ValueError:
                arg1 = None
            
            try:
                arg2 = int(parser.arg2())
            except ValueError:
                arg2 = None

            if commandType == CommandEnum.C_ARITHMETIC:
                codeWriter.writeArithmetic(command)
            elif commandType == CommandEnum.C_PUSH or commandType == CommandEnum.C_POP:
                codeWriter.writePushPop(commandType, arg1, arg2)
            elif commandType == CommandEnum.C_LABEL:
                codeWriter.writeLabel(arg1)
            elif commandType == CommandEnum.C_GOTO:
                codeWriter.writeGoto(arg1)
            elif commandType == CommandEnum.C_IF_GOTO:
                codeWriter.writeIf(arg1)
            elif commandType == CommandEnum.C_FUNCTION:
                codeWriter.writeFunction(arg1, arg2)
            elif commandType == CommandEnum.C_CALL:
                codeWriter.writeCall(arg1, arg2)
                new_file = dir_name + arg1.split('.')[0] + ".vm"
                if not is_read(read, new_file):
                    files.append(new_file)
            elif commandType == CommandEnum.C_RETURN:
                codeWriter.writeReturn()
        
        
        
        parser.inputfile.close()
        
    codeWriter.close()

if __name__== '__main__':
    main()
