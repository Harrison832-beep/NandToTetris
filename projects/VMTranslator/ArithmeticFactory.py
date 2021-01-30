from Arithmetic import Add, Sub, Neg, Eq, Gt, Lt, And, Or, Not

class ArithmeticFactory:
    def get_arithmetic(self, command):
        if command == "add":
            return Add()
        if command == "sub":
            return Sub()
        if command == "neg":
            return Neg()
        if command == "eq":
            return Eq()
        if command == "gt":
            return Gt()
        if command == "lt":
            return Lt()
        if command == "and":
            return And()
        if command == "or":
            return Or()
        if command == "not":
            return Not()
