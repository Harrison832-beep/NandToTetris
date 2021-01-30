class Segment:
    def __init__(self, filename):
        if filename.find('/') != -1:
            filename = filename[filename.find('/')+1:]
            
        if filename.find('.') != -1:
            filename = filename[:filename.find('.')]
        self.filename = filename
        #print(self.filename)
    
    def push(self, index):
        pass
    
    def pop(self, index):
        pass
    
    