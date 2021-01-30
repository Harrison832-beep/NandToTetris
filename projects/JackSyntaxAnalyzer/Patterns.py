import re

keyword = "class|constructor|function|method|field|static|var|int|char|boolean" \
          "|void|true|false|null|this|let|do|if|else|while|return"
symbol = "\{|\}|\(|\)|\[|\]|\.|,|;|\+|-|\*|/|&|\||<|>|=|~"
integer_constant = "\d+"
string_constant = '"\w*"'
identifier = "(_)*(\w|\d)+(_)*"
var_name = class_name = subroutine_name = identifier

_type = f"int|char|boolean|{class_name}"
class_var_dec = f"(static|field) ({_type}) {var_name}(,\s*{var_name})*;"
var_dec = f"var {_type} {var_name}(,\s*{var_name})*;"

keyword_constant = "true|false|null|this"
op = "\+|-|\*|/|&amp;|\||&lt;|&gt;|="
unary_op = "-|~"
term_head = f"{integer_constant}|{string_constant}|{keyword_constant}|{var_name}|{subroutine_name}|\(|{unary_op}"


keyword_re = re.compile(keyword)
symbol_re = re.compile(symbol)
integer_constant_re = re.compile(integer_constant)
string_constant_re = re.compile(string_constant)
identifier_re = re.compile(identifier)
var_name_re = class_name_re = subroutine_name_re = identifier_re
type_re = re.compile(_type)
class_var_dec_re = re.compile(class_var_dec)
var_dec_re = re.compile(var_dec)
keyword_constant_re = re.compile(keyword_constant)
term_head_re = re.compile(term_head)
op_re = re.compile(op)
unary_op_re = re.compile(unary_op)