from Constant import Constant
from Local import Local
from Temp import Temp
from Static import Static
from Argument import Argument
from Pointer import Pointer, This, That

class SegmentFactory:
    def get_segment(self, segment, filename):
        
        if segment == "constant":
            return Constant(filename)
        elif segment == "local":
            return Local(filename)
        elif segment == "temp":
            return Temp(filename)
        elif segment == "static":
            return Static(filename)
        elif segment == "argument":
            return Argument(filename)
        elif segment == "this":
            return This(filename)
        elif segment == "that":
            return That(filename)
        elif segment == "pointer":
            return Pointer(filename)
            