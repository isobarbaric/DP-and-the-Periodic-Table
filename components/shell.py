
from components.subshell import subshell

class shell:
    def __init__(self, energy_level):
        self.subshells = [subshell(-1, -1)]
        self.energy_level = energy_level
        for i in range(1, min(energy_level, 4)+1):
            self.subshells.append(subshell(i, i))        