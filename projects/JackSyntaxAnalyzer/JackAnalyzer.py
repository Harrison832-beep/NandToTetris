import sys
from JackTokenizer import JackTokenizer
from CompilationEngine import CompilationEngine


def text_compare(text):
    in_name = sys.argv[1]
    compare_file = open(in_name[:in_name.find('.')] + 'T.xml', 'r')
    i = 0
    for line in compare_file:
        if line.strip() != text[i]:
            raise ValueError(f"There is a difference on line {i + 1}:\n {text[i]} : {line}")
        else:
            print(f"line {i + 1}: {text[i]} : {line}")
            i += 1


def tokenize(in_file):
    tokenizer = JackTokenizer(in_file)
    tokens = ["<tokens>"]

    tokenizer.advance()
    while tokenizer.hasMoreTokens():
        tokens.append(tokenizer.get_current_token().__str__())
        tokenizer.advance()

    tokens.append("</tokens>")
    text_compare(tokens)

    in_name = in_file.name()
    out_name_T = in_name[:in_name.find('.')] + "T.xml"
    out_file = open(out_name_T, 'w')
    write_token(out_file, tokens)


def write_token(out_file_T, text):
    print('\n'.join(text), file=out_file_T)
    out_file_T.close()


def compile_program(in_file, out_file):
    engine = CompilationEngine(in_file, out_file)
    engine.compile_class()
    engine.close()


def main():
    in_name = sys.argv[1]
    out_name = in_name[:in_name.find('.')] + ".xml"
    in_file = open(in_name, 'r')
    out_file = open(out_name, 'w')
    compile_program(in_file, out_file)
    out_file.close()


if __name__ == '__main__':
    main()
