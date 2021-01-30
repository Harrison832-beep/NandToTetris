import unittest

from CompilationEngine import CompilationEngine
from tests.TextCompare import compare_text


class CompilationEngineTest(unittest.TestCase):
    def test_field(self):
        expected = '''
        <class>
            <keyword> class </keyword>
            <identifier> ClassVarDec1 </identifier>
            <symbol> { </symbol>
            <classVarDec>
                <keyword> field </keyword>
                <keyword> int </keyword>
                <identifier> x </identifier>
                <symbol> , </symbol>
                <identifier> y </identifier>
                <symbol> ; </symbol>
            </classVarDec>
            <classVarDec>
                <keyword> field </keyword>
                <keyword> int </keyword>
                <identifier> size </identifier>
                <symbol> ; </symbol>
            </classVarDec>
            <symbol> } </symbol>
        </class>
        '''

        in_file = open("../test_files/classVarDec/classVarDec1.jack", 'r')
        out_file = open("../test_files/classVarDec/classVarDec1.xml", 'w')
        compiler = CompilationEngine(in_file, out_file)
        try:
            compiler.compile_class()
        except Exception as e:
            print(e)
        finally:
            in_file.close()
            out_file.close()

        out_name = out_file.name
        out_file = open(out_name, 'r')
        self.assertTrue(compare_text(out_file, expected))
        out_file.close()

    def test_static(self):
        expected = '''
                <class>
                    <keyword> class </keyword>
                    <identifier> ClassVarDec2 </identifier>
                    <symbol> { </symbol>
                    <classVarDec>
                        <keyword> static </keyword>
                        <keyword> int </keyword>
                        <identifier> x </identifier>
                        <symbol> , </symbol>
                        <identifier> y </identifier>
                        <symbol> ; </symbol>
                    </classVarDec>
                    <classVarDec>
                        <keyword> static </keyword>
                        <keyword> int </keyword>
                        <identifier> size </identifier>
                        <symbol> ; </symbol>
                    </classVarDec>
                    <symbol> } </symbol>
                </class>
                '''

        in_file = open("../test_files/classVarDec/classVarDec2.jack", 'r')
        out_file = open("../test_files/classVarDec/classVarDec2.xml", 'w')
        compiler = CompilationEngine(in_file, out_file)
        try:
            compiler.compile_class()
        except Exception as e:
            print(e)
        finally:
            in_file.close()
            out_file.close()

        out_name = out_file.name
        out_file = open(out_name, 'r')
        self.assertTrue(compare_text(out_file, expected))
        out_file.close()

    def test_field_and_static(self):
        expected = '''
                        <class>
                            <keyword> class </keyword>
                            <identifier> ClassVarDec3 </identifier>
                            <symbol> { </symbol>
                            <classVarDec>
                                <keyword> field </keyword>
                                <keyword> int </keyword>
                                <identifier> x </identifier>
                                <symbol> , </symbol>
                                <identifier> y </identifier>
                                <symbol> ; </symbol>
                            </classVarDec>
                            <classVarDec>
                                <keyword> field </keyword>
                                <keyword> int </keyword>
                                <identifier> size </identifier>
                                <symbol> ; </symbol>
                            </classVarDec>
                            <classVarDec>
                                <keyword> static </keyword>
                                <keyword> int </keyword>
                                <identifier> a </identifier>
                                <symbol> , </symbol>
                                <identifier> b </identifier>
                                <symbol> , </symbol>
                                <identifier> c </identifier>
                                <symbol> ; </symbol>
                            </classVarDec>
                            <classVarDec>
                                <keyword> static </keyword>
                                <keyword> boolean </keyword>
                                <identifier> HORIZONTAL </identifier>
                                <symbol> ; </symbol>
                            </classVarDec>
                            <symbol> } </symbol>
                        </class>
                        '''
        in_file = open("../test_files/classVarDec/classVarDec3.jack", 'r')
        out_file = open("../test_files/classVarDec/classVarDec3.xml", 'w')
        compiler = CompilationEngine(in_file, out_file)
        try:
            compiler.compile_class()
        except Exception as e:
            print(e)
        finally:
            in_file.close()
            out_file.close()

        out_name = out_file.name
        out_file = open(out_name, 'r')
        self.assertTrue(compare_text(out_file, expected))
        out_file.close()

    def test_constructor_function_method(self):
        expected = '''
        <class>
            <keyword> class </keyword>
            <identifier> SubroutineDec1 </identifier>
            <symbol> { </symbol>
                <subroutineDec>
                    <keyword> constructor </keyword>
                    <identifier> SubroutineDec1 </identifier>
                    <identifier> new </identifier>
                    <symbol> ( </symbol>
                    <parameterList>
                    </parameterList>
                    <symbol> ) </symbol>
                    <subroutineBody>
                        <symbol> { </symbol>
                        <symbol> } </symbol>
                    </subroutineBody>
                </subroutineDec>
                <subroutineDec>
                    <keyword> function </keyword>
                    <keyword> void </keyword>
                    <identifier> main </identifier>
                    <symbol> ( </symbol>
                    <parameterList>
                    </parameterList>
                    <symbol> ) </symbol>
                    <subroutineBody>
                        <symbol> { </symbol>
                        <symbol> } </symbol>
                    </subroutineBody>
                </subroutineDec>
                <subroutineDec>
                    <keyword> method </keyword>
                    <keyword> void </keyword>
                    <identifier> test1 </identifier>
                    <symbol> ( </symbol>
                    <parameterList>
                    </parameterList>
                    <symbol> ) </symbol>
                    <subroutineBody>
                        <symbol> { </symbol>
                        <symbol> } </symbol>
                    </subroutineBody>
                </subroutineDec>
            <symbol> } </symbol>
        </class>
        '''
        in_file = open("../test_files/SubroutineDec/SubroutineDec1.jack", 'r')
        out_file = open("../test_files/SubroutineDec/SubroutineDec1.xml", 'w')
        compiler = CompilationEngine(in_file, out_file)
        try:
            compiler.compile_class()
        except Exception as e:
            print(e)
        finally:
            in_file.close()
            out_file.close()

        out_name = out_file.name
        out_file = open(out_name, 'r')
        self.assertTrue(compare_text(out_file, expected))
        out_file.close()

    def test_if(self):
        expected = '''
        <statements>
            <ifStatement>
                <keyword> if </keyword>
                <symbol> ( </symbol>
                <expression>
                    <term>
                        <keyword> true </keyword>
                    </term>
                </expression>
                <symbol> ) </symbol>
                <symbol> { </symbol>
                <statements>
                </statements>
                <symbol> } </symbol>
            </ifStatement>
        </statements>
        '''
        in_file = open("../test_files/Statements/Statements1.jack", 'r')
        out_file = open("../test_files/Statements/Statements1.xml", 'w')
        compiler = CompilationEngine(in_file, out_file)
        try:
            compiler.compile_statements()
        except Exception as e:
            print(e)
        finally:
            in_file.close()
            out_file.close()

        out_name = out_file.name
        out_file = open(out_name, 'r')
        self.assertTrue(compare_text(out_file, expected))
        out_file.close()

    def test_if_else(self):
        expected = '''
            <statements>
                <ifStatement>
                    <keyword> if </keyword>
                    <symbol> ( </symbol>
                    <expression>
                        <term>
                            <keyword> false </keyword>
                        </term>
                    </expression>
                    <symbol> ) </symbol>
                    <symbol> { </symbol>
                    <statements>
                    </statements>
                    <symbol> } </symbol>
                    <keyword> else </keyword>
                    <symbol> { </symbol>
                    <statements>
                    </statements>
                    <symbol> } </symbol>
                </ifStatement>
            </statements>
            '''
        in_file = open("../test_files/Statements/Statements2.jack", 'r')
        out_file = open("../test_files/Statements/Statements2.xml", 'w')
        compiler = CompilationEngine(in_file, out_file)
        try:
            compiler.compile_statements()
        except Exception as e:
            print(e)
        finally:
            in_file.close()
            out_file.close()

        out_name = out_file.name
        out_file = open(out_name, 'r')
        self.assertTrue(compare_text(out_file, expected))
        out_file.close()

    def test_let(self):
        expected = '''
            <statements>
                <letStatement>
                    <keyword> let </keyword>
                    <identifier> num </identifier>
                    <symbol> = </symbol>
                    <expression>
                        <term>
                            <integerConstant> 0 </integerConstant>
                        </term>
                    </expression>
                    <symbol> ; </symbol>
                </letStatement>
            </statements>
        '''
        in_file = open("../test_files/Statements/Statements3.jack", 'r')
        out_file = open("../test_files/Statements/Statements3.xml", 'w')
        compiler = CompilationEngine(in_file, out_file)
        try:
            compiler.compile_statements()
        except Exception as e:
            print(e)
        finally:
            in_file.close()
            out_file.close()

        out_name = out_file.name
        out_file = open(out_name, 'r')
        self.assertTrue(compare_text(out_file, expected))
        out_file.close()

    def test_let_with_array(self):
        expected = '''
        <statements>
            <letStatement>
                <keyword> let </keyword>
                <identifier> num </identifier>
                <symbol> [ </symbol>
                <expression>
                    <term>
                        <integerConstant> 0 </integerConstant>
                    </term>
                </expression>
                <symbol> ] </symbol>
                <symbol> = </symbol>
                <expression>
                    <term>
                        <identifier> x </identifier>
                    </term>
                </expression>
                <symbol> ; </symbol>
            </letStatement>
        </statements>
        '''
        in_file = open("../test_files/Statements/LetWithArray.jack", 'r')
        out_file = open("../test_files/Statements/LetWithArray.xml", 'w')
        compiler = CompilationEngine(in_file, out_file)
        try:
            compiler.compile_statements()
        except Exception as e:
            print(e)
        finally:
            in_file.close()
            out_file.close()

        out_name = out_file.name
        out_file = open(out_name, 'r')
        self.assertTrue(compare_text(out_file, expected))
        out_file.close()

    def test_while(self):
        expected = '''
            <statements>
                <whileStatement>
                    <keyword> while </keyword>
                    <symbol> ( </symbol>
                    <expression>
                        <term>
                            <keyword> false </keyword>
                        </term>
                    </expression>
                    <symbol> ) </symbol>
                    <symbol> { </symbol>
                    <statements>
                    </statements>
                    <symbol> } </symbol>
                </whileStatement>
            </statements>
        '''
        in_file = open("../test_files/Statements/Statements4.jack", 'r')
        out_file = open("../test_files/Statements/Statements4.xml", 'w')
        compiler = CompilationEngine(in_file, out_file)
        try:
            compiler.compile_statements()
        except Exception as e:
            print(e)
        finally:
            in_file.close()
            out_file.close()

        out_name = out_file.name
        out_file = open(out_name, 'r')
        self.assertTrue(compare_text(out_file, expected))
        out_file.close()

    def test_do_method(self):
        expected = '''
            <statements>
                <doStatement>
                    <keyword> do </keyword>
                    <identifier> game </identifier>
                    <symbol> . </symbol>
                    <identifier> play </identifier>
                    <symbol> ( </symbol>
                    <expressionList>
                    </expressionList>
                    <symbol> ) </symbol>
                    <symbol> ; </symbol>
                </doStatement>
            </statements>
        '''
        in_file = open("../test_files/Statements/Statements5.jack", 'r')
        out_file = open("../test_files/Statements/Statements5.xml", 'w')
        compiler = CompilationEngine(in_file, out_file)
        try:
            compiler.compile_statements()
        except Exception as e:
            print(e)
        finally:
            in_file.close()
            out_file.close()

        out_name = out_file.name
        out_file = open(out_name, 'r')
        self.assertTrue(compare_text(out_file, expected))
        out_file.close()

    def test_do_function(self):
        expected = '''
                    <statements>
                        <doStatement>
                            <keyword> do </keyword>
                            <identifier> multiply </identifier>
                            <symbol> ( </symbol>
                            <expressionList>
                                <expression>
                                    <term>
                                        <identifier> x </identifier>
                                    </term>
                                </expression>
                                <symbol> , </symbol>
                                <expression>
                                    <term>
                                        <identifier> y </identifier>
                                    </term>
                                </expression>
                            </expressionList>
                            <symbol> ) </symbol>
                            <symbol> ; </symbol>
                        </doStatement>
                    </statements>
                '''
        in_file = open("../test_files/Statements/Statements6.jack", 'r')
        out_file = open("../test_files/Statements/Statements6.xml", 'w')
        compiler = CompilationEngine(in_file, out_file)
        try:
            compiler.compile_statements()
        except Exception as e:
            print(e)
        finally:
            in_file.close()
            out_file.close()

        out_name = out_file.name
        out_file = open(out_name, 'r')
        self.assertTrue(compare_text(out_file, expected))
        out_file.close()

    def test_return(self):
        expected = '''
        <statements>
            <returnStatement>
                <keyword> return </keyword>
                <expression>
                    <term>
                        <keyword> null </keyword>
                    </term>
                </expression>
                <symbol> ; </symbol>
            </returnStatement>
        </statements>
        '''
        in_file = open("../test_files/Statements/Statements7.jack", 'r')
        out_file = open("../test_files/Statements/Statements7.xml", 'w')
        compiler = CompilationEngine(in_file, out_file)
        try:
            compiler.compile_statements()
        except Exception as e:
            print(e)
        finally:
            in_file.close()
            out_file.close()

        out_name = out_file.name
        out_file = open(out_name, 'r')
        self.assertTrue(compare_text(out_file, expected))
        out_file.close()

    def test_term_op_term(self):
        expected = '''
        <expression>
            <term>
                <identifier> x </identifier>
            </term>
            <symbol> + </symbol>
            <term>
                <identifier> y </identifier>
            </term>
        </expression>
                '''
        in_file = open("../test_files/Expression/Expression1.jack", 'r')
        out_file = open("../test_files/Expression/Expression1.xml", 'w')
        compiler = CompilationEngine(in_file, out_file)
        try:
            compiler.compile_expression()
        except Exception as e:
            print(e)
        finally:
            in_file.close()
            out_file.close()

        out_name = out_file.name
        out_file = open(out_name, 'r')
        self.assertTrue(compare_text(out_file, expected))
        out_file.close()

    def test_unaryOp_term(self):
        expected = '''
        <expression>
            <term>
                <symbol> - </symbol>
                <term>
                    <identifier> x </identifier>
                </term>
            </term>
        </expression>
        '''
        in_file = open("../test_files/Expression/Expression2.jack", 'r')
        out_file = open("../test_files/Expression/Expression2.xml", 'w')
        compiler = CompilationEngine(in_file, out_file)
        try:
            compiler.compile_expression()
        except Exception as e:
            print(e)
        finally:
            in_file.close()
            out_file.close()

        out_name = out_file.name
        out_file = open(out_name, 'r')
        self.assertTrue(compare_text(out_file, expected))
        out_file.close()

    def test_term_op_subroutineCall(self):
        expected = '''
        <expression>
            <term>
                <identifier> x </identifier>
            </term>
            <symbol> + </symbol>
            <term>
                <identifier> multiply </identifier>
                <symbol> ( </symbol>
                    <expressionList>
                        <expression>
                            <term>
                                <identifier> x </identifier>
                            </term>
                        </expression>
                        <symbol> , </symbol>
                        <expression>
                            <term>
                                <identifier> y </identifier>
                            </term>
                        </expression>
                    </expressionList>
                <symbol> ) </symbol>
            </term>
        </expression>
                '''
        in_file = open("../test_files/Expression/Expression3.jack", 'r')
        out_file = open("../test_files/Expression/Expression3.xml", 'w')
        compiler = CompilationEngine(in_file, out_file)
        try:
            compiler.compile_expression()
        except Exception as e:
            print(e)
        finally:
            in_file.close()
            out_file.close()

        out_name = out_file.name
        out_file = open(out_name, 'r')
        self.assertTrue(compare_text(out_file, expected))
        out_file.close()

    def test_term_and_parentheses(self):
        expected = '''
        <expression>
            <term>
                <identifier> x </identifier>
            </term>
            <symbol> + </symbol>
            <term>
                <symbol> ( </symbol>
                <expression>
                    <term>
                        <identifier> x </identifier>
                    </term>
                    <symbol> * </symbol>
                    <term>
                        <identifier> y </identifier>
                    </term>
                </expression>
                <symbol> ) </symbol>
            </term>
        </expression>
        '''
        in_file = open("../test_files/Expression/Expression4.jack", 'r')
        out_file = open("../test_files/Expression/Expression4.xml", 'w')
        compiler = CompilationEngine(in_file, out_file)
        try:
            compiler.compile_expression()
        except Exception as e:
            print(e)
        finally:
            in_file.close()
            out_file.close()

        out_name = out_file.name
        out_file = open(out_name, 'r')
        self.assertTrue(compare_text(out_file, expected))
        out_file.close()

    def test_term_with_array(self):
        expected = '''
        <expression>
            <term>
                <identifier> x </identifier>
            </term>
            <symbol> + </symbol>
            <term>
                <identifier> array </identifier>
                <symbol> [ </symbol>
                <expression>
                    <term>
                        <integerConstant> 5 </integerConstant>
                    </term>
                </expression>
                <symbol> ] </symbol>
            </term>
        </expression>
        '''
        in_file = open("../test_files/Expression/Expression5.jack", 'r')
        out_file = open("../test_files/Expression/Expression5.xml", 'w')
        compiler = CompilationEngine(in_file, out_file)
        try:
            compiler.compile_expression()
        except Exception as e:
            print(e)
        finally:
            in_file.close()
            out_file.close()

        out_name = out_file.name
        out_file = open(out_name, 'r')
        self.assertTrue(compare_text(out_file, expected))
        out_file.close()

    def test_ExpressionLessSquare_Main(self):
        in_file = open("../test_files/ExpressionLessSquare/Main.jack", 'r')
        out_file = open("../test_files/Test.xml", 'w')

        compiler = CompilationEngine(in_file, out_file)
        compiler.compile_class()

        in_file.close()
        out_file.close()

        out_name = out_file.name
        out_file = open(out_name, 'r')

        expected_token_file_name = "../test_files/ExpressionLessSquare/Main.xml"
        expected = get_expected(expected_token_file_name)
        self.assertTrue(compare_text(out_file, expected))
        out_file.close()


def get_expected(expected_token_file_name):
    expected_token_file = open(expected_token_file_name, 'r')
    expected = expected_token_file.read()
    expected_token_file.close()
    return expected


if __name__ == "__main__":
    unittest.main()
