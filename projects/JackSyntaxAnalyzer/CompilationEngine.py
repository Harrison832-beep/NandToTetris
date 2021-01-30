import re

# Lexical Terms
from termcolor import cprint

from JackTokenizer import JackTokenizer
from Patterns import type_re, var_name_re, _type, subroutine_name, var_name, subroutine_name_re, class_name, \
    class_name_re, term_head_re, op_re, unary_op, unary_op_re

statement_keyword = ["if", "while", "let", "do", "return"]
ops = ['+', '-', '*', '/', '&eq;', '&gt;', '&lt;', '|', '&amp;']
keywordConstants = ["true", "false", "null", "this"]
terms = ["integerConstant", "stringConstant", "identifier"] + keywordConstants
unaryOps = ["-", "~"]


class CompilationEngine:
    def __init__(self, in_file, out_file):
        """Creates a new compilation engine with the given input and output.
        The next routine called must be compileClass()"""
        in_file_re = re.compile(r".+\.jack")
        out_file_re = re.compile(r".+\.xml")
        assert in_file_re.match(in_file.name)
        assert out_file_re.match(out_file.name)

        self.in_file = in_file
        self.out_file = out_file

        self.tokens = get_tokens(self.in_file)
        self.token_v = None
        self.token_c = None

        self.__next__()

    def __next__(self):
        # Get the next token from the input file
        # Also set the value of the token as well as the classification
        regex = re.compile(r"<(.*)> (.*) </(.*)>")
        self.token = self.tokens.pop(0).strip() if len(self.tokens) > 0 else None

        if self.token == "<tokens>":  # If the token is a <token> or </token>, abandon and get the next token
            self.token = self.tokens.pop(0).strip() if len(self.tokens) > 0 else None
        elif self.token == "</tokens>":
            self.token = None

        if self.token is None:
            return

        # print(self.token)
        self.token_v = regex.match(self.token).group(2)
        self.token_c = regex.match(self.token).group(1)

    def __write_token_and_advance__(self):
        print(self.token, file=self.out_file)
        self.__next__()

    def compile_class(self):
        """Complies a complete class."""

        # class className {classVarDec* subroutineDec*}
        print("<class>", file=self.out_file)

        self.eat("class")
        assert class_name_re.match(self.token_v)
        self.__write_token_and_advance__()
        self.eat('{')

        # Repeat until the end of class
        while self.token_v != '}':
            # classVarDec: (static|field) (type) varName(,var_name)*;
            # subroutineDec: (constructor|function|method) (void|type) subroutineName'('parameterList')' subroutineBody
            if self.token_v in ["static", "field"]:
                self.compile_class_var_dec()
            elif self.token_v in ["function", "method", "constructor"]:
                self.compile_subroutine_dec()
            else:
                raise ValueError(f"compileClass: unrecognized subroutine or class var: {self.token}")

        self.eat('}')

        print("</class>", file=self.out_file)

    def compile_class_var_dec(self):
        """Compiles a static variable declaration or a field declaration."""
        # classVarDec: (static|field) (type) varName(,var_name)*;
        print("<classVarDec>", file=self.out_file)

        assert self.token_v in ["static", "field"]
        self.__write_token_and_advance__()
        assert type_re.match(self.token_v)
        self.__write_token_and_advance__()
        assert var_name_re.match(self.token_v)
        self.__write_token_and_advance__()

        while self.token_v == ',':
            self.eat(',')
            assert var_name_re.match(self.token_v)
            self.__write_token_and_advance__()
        self.eat(';')

        print("</classVarDec>", file=self.out_file)

    def compile_subroutine_dec(self):
        """Compiles a complete method, function or constructor."""
        print("<subroutineDec>", file=self.out_file)

        regex1 = re.compile(r"constructor|function|method")
        regex2 = re.compile(rf"void|{_type}")
        regex3 = re.compile(rf"{subroutine_name}")

        assert regex1.match(self.token_v)
        self.__write_token_and_advance__()
        assert regex2.match(self.token_v)
        self.__write_token_and_advance__()
        assert regex3.match(self.token_v)
        self.__write_token_and_advance__()
        self.eat('(')
        self.compile_parameter_list()
        self.eat(')')
        self.compile_subroutine_body()

        print("</subroutineDec>", file=self.out_file)

    def compile_parameter_list(self):
        """Compiles a (possibly empty) parameter list. Does not handle the 
        enclosing "()"."""
        print("<parameterList>", file=self.out_file)
        while type_re.match(self.token_v):
            self.__write_token_and_advance__()
            assert var_name_re.match(self.token_v)
            self.__write_token_and_advance__()

        print("</parameterList>", file=self.out_file)

    def compile_subroutine_body(self):
        """Compiles a subroutine's body."""
        print("<subroutineBody>", file=self.out_file)
        self.eat('{')

        # var_dec*
        while self.token_v == "var":
            self.compile_var_dec()

        # statements*
        while self.token_v in statement_keyword:
            self.compile_statements()

        self.eat('}')

        print("</subroutineBody>", file=self.out_file)

    def compile_var_dec(self):
        """Compiles a var declaration."""
        print("<varDec>", file=self.out_file)

        re1 = re.compile(rf"{_type}")
        re2 = re.compile(rf"{var_name}")

        assert self.token_v == "var"
        self.__write_token_and_advance__()
        assert re1.match(self.token_v)
        self.__write_token_and_advance__()
        assert re2.match(self.token_v)
        self.__write_token_and_advance__()

        while self.token_v == ',':
            self.__write_token_and_advance__()
            assert re2.match(self.token_v)
            self.__write_token_and_advance__()
        assert self.token_v == ';'
        self.__write_token_and_advance__()  # ';'

        print("</varDec>", file=self.out_file)

    def compile_statements(self):
        """Compiles a sequence of statements.
        Does not handle the enclosing "{}"."""
        print("<statements>", file=self.out_file)
        # print(self.token_v)
        while self.token_v in statement_keyword:
            if self.token_v == "let":
                self.compile_let()
            elif self.token_v == "do":
                self.compile_do()
            elif self.token_v == "while":
                self.compile_while()
            elif self.token_v == "if":
                self.compile_if()
            elif self.token_v == "return":
                self.compile_return()
            else:
                raise ValueError(f"Unrecognized statement: {self.token}")

        print("</statements>", file=self.out_file)

    def compile_let(self):
        """Compiles a let statement."""
        print("<letStatement>", file=self.out_file)
        self.eat("let")

        assert var_name_re.match(self.token_v)
        self.__write_token_and_advance__()

        if self.token_v == '[':
            self.eat('[')
            self.compile_expression()
            self.eat(']')
        self.eat('=')
        self.compile_expression()
        self.eat(';')

        print("</letStatement>", file=self.out_file)

    def compile_if(self):
        """Compiles a if statement."""
        print("<ifStatement>", file=self.out_file)
        self.eat("if")
        self.eat('(')
        self.compile_expression()
        self.eat(')')
        self.eat('{')
        self.compile_statements()
        self.eat('}')

        if self.token_v == "else":
            self.eat("else")
            self.eat('{')
            self.compile_statements()
            self.eat('}')

        print("</ifStatement>", file=self.out_file)

    def compile_while(self):
        """Compiles a while statement."""
        print("<whileStatement>", file=self.out_file)
        self.eat("while")
        self.eat('(')
        self.compile_expression()
        self.eat(')')
        self.eat('{')
        self.compile_statements()
        self.eat('}')

        print("</whileStatement>", file=self.out_file)

    def compile_do(self):
        """Compiles a do statement."""
        print("<doStatement>", file=self.out_file)
        self.eat("do")

        self.__compile_subroutine_call__()
        self.eat(';')

        print("</doStatement>", file=self.out_file)

    def __compile_subroutine_call__(self):
        re1 = re.compile(rf"{subroutine_name}|({class_name}|{var_name})")
        assert re1.match(self.token_v)
        self.__write_token_and_advance__()

        if self.token_v == '(':
            self.eat('(')
            self.compile_expression_list()
            self.eat(')')
        elif self.token_v == '.':
            self.eat('.')
            self.__compile_subroutine_call__()

    def compile_return(self):
        """Compiles a return statement."""
        print("<returnStatement>", file=self.out_file)
        self.eat("return")

        if self.token_v != ';':
            self.compile_expression()
        self.eat(';')

        print("</returnStatement>", file=self.out_file)

    def compile_expression(self):
        """Compiles an expression."""
        print("<expression>", file=self.out_file)

        assert term_head_re.match(self.token_v)
        self.compile_term()

        while op_re.match(self.token_v):  # Don't print end sym
            self.__write_token_and_advance__()
            self.compile_term()

        print("</expression>", file=self.out_file)

    def compile_term(self):
        """Compiles a term.
        If the current token is an identifier the routine must distinguish between
        a variable, and an array entry, or a subroutine call.
        A single look-ahead token, which may be one of "[", "(", or ".", suffices to
        distinguish between the possibilities. Any other token is not part of this
        term and should not be advanced over."""
        print("<term>", file=self.out_file)

        if self.token_v == '(':
            self.eat('(')
            self.compile_expression()
            self.eat(')')
        elif unary_op_re.match(self.token_v):
            self.__write_token_and_advance__()
            self.compile_term()
        else:
            try:
                next_token_v = self.__peek__()
            except AttributeError:
                next_token_v = None

            if next_token_v is not None:
                # Look-ahead
                # Subroutine call
                if next_token_v in ['.', '(']:
                    self.__compile_subroutine_call__()
                # Array entry
                elif next_token_v == '[':  # Array entry ends with ']'
                    assert var_name_re.match(self.token_v)
                    self.__write_token_and_advance__()
                    self.eat('[')
                    self.compile_expression()
                    self.eat(']')
                else:
                    self.__write_token_and_advance__()
            else:
                assert term_head_re.match(self.token_v)
                self.__write_token_and_advance__()

        print("</term>", file=self.out_file)

    def __peek__(self):
        regex = re.compile(r"<(.*)> (.*) </(.*)>")
        token_v = regex.match(self.tokens[0]).group(2)
        return token_v

    def compile_expression_list(self):
        """Compiles a (possibly empty) comma-separated list of expressiosns."""
        print("<expressionList>", file=self.out_file)

        while self.token_v != ')':  # Don't print ')'
            self.compile_expression()
            assert self.token_v == ',' or self.token_v == ')'
            if self.token_v == ',':
                self.__write_token_and_advance__()  # ','

        assert self.token_v == ')'
        print("</expressionList>", file=self.out_file)

    def close(self):
        self.in_file.close()
        self.out_file.close()

    def eat(self, token_v):
        assert self.token_v == token_v
        self.__write_token_and_advance__()


def get_tokens(in_file):
    tokenizer = JackTokenizer(in_file)
    tokens = ["<tokens>"]

    tokenizer.advance()
    while tokenizer.hasMoreTokens():
        tokens.append(tokenizer.get_current_token().__str__())
        tokenizer.advance()

    tokens.append("</tokens>")
    return tokens
