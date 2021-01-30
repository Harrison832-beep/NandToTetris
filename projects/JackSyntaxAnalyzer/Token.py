

class Token:
    def __init__(self, token_type, value):
        self.token_type = token_type
        if token_type == "stringConstant":
            value = value.replace('"', "")
        
        if value in ['&', '<', '>', '"']:
            value = self.__convert_symbol__(value)
        
        self.value = value
    
    def __convert_symbol__(self, value):
        if value == '&':
            return "&amp;"
        if value == '<':
            return "&lt;"
        if value == '>':
            return "&gt;"
        if value == '"':
            return "&quot;"
    
    def __str__(self):
        return f"<{self.token_type}> {self.value} </{self.token_type}>"
