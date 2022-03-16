
from components.subshell import subshell

class shell:
    def __init__(self, energy_level):
        self.subshells = [subshell(-1, -1)]
        self.energy_level = energy_level
        for i in range(1, min(energy_level, 4)+1):
            self.subshells.append(subshell(i, i))
    
    def occupied(self, which_level):
        return self.subshells[which_level].occupied

    def howMany(self):
        sum = 0
        for current_subshell in range(1, len(self.subshells)):
            sum += self.occupied(current_subshell)
        return sum
    
    def valence(self):
        return self.occupied(self.energy_level)
        