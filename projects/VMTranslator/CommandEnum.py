"""
Created on Tue Dec 29 18:49:06 2020

@author: Qicheng CHEN
"""

from enum import Enum, auto

class CommandEnum(Enum):
    C_ARITHMETIC = auto()
    C_PUSH = auto()
    C_POP= auto()
    
    C_GOTO = auto()
    C_IF_GOTO = auto()
    C_LABEL = auto()
    
    C_CALL = auto()
    C_FUNCTION = auto()
    C_RETURN = auto()
    
    
    