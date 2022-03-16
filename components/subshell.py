
class subshell:
    def __init__(self, origin, which):
        self.energy_level = origin
        self.capacity = -1
        self.occupied = 0
        if origin != -1:
            if which == 1:
                self.capacity = 2
                self.identifier = 's'
            elif which == 2:
                self.capacity = 6
                self.identifier = 'p'
            elif which == 3:
                self.capacity = 10
                self.identifier = 'd'
            elif which == 4:
                self.capacity = 14
                self.identifier = 'f'