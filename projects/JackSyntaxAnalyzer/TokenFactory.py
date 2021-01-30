import TokenTypeConst
from Patterns import keyword_re, symbol_re, integer_constant_re, string_constant_re, identifier_re
from Token import Token


symbols = ['{','}','(',')','[',']','.',',',';','+','-','*','/','&','|','<','>','=','~']


class TokenFactory:
    @staticmethod
    def get_token(current_token):
        if keyword_re.match(current_token):
            token_type = TokenTypeConst.KEYWORD
        elif symbol_re.match(current_token):
            token_type = TokenTypeConst.SYMBOL
        elif integer_constant_re.match(current_token):
            token_type = TokenTypeConst.INT_CONST
        elif string_constant_re.match(current_token):
            token_type = TokenTypeConst.STRING_CONST
        elif identifier_re.match(current_token):
            token_type = TokenTypeConst.IDENTIFIER
        else:
            raise ValueError(f"Token not recognized: {current_token}")
        
        if token_type is TokenTypeConst.KEYWORD:
            return Token("keyword", current_token)
        elif token_type is TokenTypeConst.IDENTIFIER:
            return Token("identifier", current_token)
        elif token_type is TokenTypeConst.INT_CONST:
            return Token("integerConstant", current_token)
        elif token_type is TokenTypeConst.STRING_CONST:
            return Token("stringConstant", current_token)
        elif token_type is TokenTypeConst.SYMBOL:
            return Token("symbol", current_token)
        