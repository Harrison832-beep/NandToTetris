import TokenTypeConst
from TokenFactory import TokenFactory, symbols


class JackTokenizer:

    def __init__(self, in_file):
        """Opens the input .jack file and gets ready to tokenize it."""
        self.input_file = in_file
        self.file_name = in_file.name
        self.current_token = None

        self.tokenFactory = TokenFactory()
        self.current_line = ""
        self.queue = []

        self.__process_file__()

    def hasMoreTokens(self):
        """Are there more tokens in the input?"""

        return len(self.queue) > 0 or self.current_token is not None

    def advance(self):
        """Gets the next token from the input, and makes it the current token.        
        This method should be called only if hasMoreTokens() is true.
        Initially there is no current token."""
        if not self.hasMoreTokens():
            raise ValueError("advance() should be called only when hasMoreTokens() is True.")

        self.current_token = self.queue.pop(0) if len(self.queue) > 0 else None

    def __process_file__(self):
        lines = self.input_file.read()

        single_line_comment = False
        multi_line_comment = False
        str_constant = False
        token = ""

        for i in range(len(lines)):
            c = lines[i]
            if str_constant:
                if c == '"':
                    if i > 0 and lines[i - 1] != "\\":
                        str_constant = False
                        self.__process_token__(token)
                        token = ""
                else:
                    token += c
                continue

            if c == '/':
                if i < len(lines) and lines[i + 1] == '/':
                    single_line_comment = True
                elif i < len(lines) and lines[i + 1] == '*':
                    multi_line_comment = True
                elif i > 0 and lines[i - 1] == '*':
                    multi_line_comment = False
                    continue

            if c == '\n':
                self.__process_token__(token)
                single_line_comment = False
            elif single_line_comment or multi_line_comment:
                continue
            elif c.isspace():
                self.__process_token__(token)
                token = ""
            elif c in symbols:
                self.__process_token__(token)
                token = ""
                self.__process_token__(c)
            else:
                if c == '"':
                    str_constant = True
                token += c

        if len(token) != 0:
            self.__process_token__(token)
            token = ""

    def __process_token__(self, token):
        if len(token) == 0:
            return
        token_obj = self.tokenFactory.get_token(token)
        self.queue.append(token_obj)

    def tokenType(self):
        """Returns the type of the current token, as a constant."""
        return self.current_token.get_type()

    def keyWord(self):
        """Returns the keyword which is the current token, as a constant.
        This method should be called only if tokenType is KEYWORD."""
        if self.tokenType() is not TokenTypeConst.KEYWORD:
            raise ValueError("Method keyWord() should be called only if tokenType is KEYWORD")

        return self.current_token

    def symbol(self):
        """Returns the character which is the current token. Should be called only if
        tokenType is SYMBOL."""
        if self.tokenType() is not TokenTypeConst.SYMBOL:
            raise ValueError("Method symbol() should be called only if tokenType is SYMBOL")

        return self.current_token

    def identifier(self):
        """Returns the identifier which is the current token. Should be called only if
        tokenType is IDENTIFIER."""
        if self.tokenType() is not TokenTypeConst.IDENTIFIER:
            raise ValueError("Method symbol() should be called only if tokenType is SYMBOL")

        return self.current_token

    def intVal(self):
        """Returns the integer value of the current token. Should be called only if 
        tokenType is INT_CONST."""
        if self.tokenType() is not TokenTypeConst.INT_CONST:
            raise ValueError("Method symbol() should be called only if tokenType is SYMBOL")

        return int(self.current_token)

    def stringVal(self):
        """Returns the string value of the current token, without the two enclosing 
        double quotes. Should be called only if tokenType is STRING_CONST."""
        if self.tokenType() is not TokenTypeConst.STRING_CONST:
            raise ValueError("Method symbol() should be called only if tokenType is SYMBOL")

        return self.current_token

    def get_current_token(self):
        return self.current_token
