
from components.shell import shell
import copy 

class element:
    aufbau =  [[1, 1], [2, 1], [2, 2], [3, 1], [3, 2], [4, 1], [3, 3], [4, 2], [5, 1], [4, 3], [5, 2], [6, 1], [4, 4], [5, 3], [6, 2], [7, 1], [5, 4], [6, 3], [7, 2], [8, 1], [6, 4], [7, 3], [8, 2], [7, 4]]

    pTable = -1

    def __init__(self, name, atomicNumber, pTable):
        self.name = name
        self.atomicNumber = atomicNumber
        self.electrons = atomicNumber
        self.eConfig = [shell(-1)]
        self.lastIndexAufbau = -1
        self.nearestNobleGas = -1
        self.nobleGas = False
        element.pTable = pTable
        for energy_level in range(1, 10):
            self.eConfig.append(shell(energy_level))
        if (self.atomicNumber <= 2):
            self.baseCase()
        else:
            self.filler()
        
    def baseCase(self):
        if (self.electrons == -1):
            return
        electronsLeft = self.electrons
        for location in range(0, len(element.aufbau)):
            if not electronsLeft > 0:
                assert electronsLeft == 0
                break
            assert electronsLeft > 0
            currentShell = element.aufbau[location][0]
            currentSubshell = element.aufbau[location][1]
            self.lastIndexAufbau = location
            difference = self.eConfig[currentShell].subshells[currentSubshell].capacity - self.eConfig[currentShell].subshells[currentSubshell].occupied
            # assert difference >= 0
            if (difference > 0):
                electronsToAdd = difference
                if (electronsLeft >= electronsToAdd):
                    electronsLeft -= electronsToAdd
                    self.eConfig[currentShell].subshells[currentSubshell].occupied = self.eConfig[currentShell].subshells[currentSubshell].capacity
                else:
                    self.eConfig[currentShell].subshells[currentSubshell].occupied += electronsLeft
                    electronsLeft = 0

    def filler(self):
        for i in range(self.atomicNumber-1, 0, -1):
            if (element.pTable[i].nobleGas):
                self.nearestNobleGas = i
                break
        self.eConfig = copy.deepcopy(element.pTable[self.nearestNobleGas].eConfig)
        electronsLeft = self.electrons - self.nearestNobleGas 
        for location in range(element.pTable[self.nearestNobleGas].lastIndexAufbau, len(element.aufbau)):
            if not electronsLeft > 0:
                assert electronsLeft == 0
                break
            assert self.electrons > 0
            currentShell = element.aufbau[location][0]
            currentSubshell = element.aufbau[location][1]
            self.lastIndexAufbau = location
            difference = self.eConfig[currentShell].subshells[currentSubshell].capacity - self.eConfig[currentShell].subshells[currentSubshell].occupied
            assert difference >= 0
            if (difference > 0):
                electronsToAdd = difference
                if (electronsLeft >= electronsToAdd):
                    electronsLeft -= electronsToAdd
                    self.eConfig[currentShell].subshells[currentSubshell].occupied = self.eConfig[currentShell].subshells[currentSubshell].capacity
                else:
                    self.eConfig[currentShell].subshells[currentSubshell].occupied += electronsLeft
                    electronsLeft = 0

    def __repr__(self):
        info = self.name + '\n' 
        for some_shell in element.pTable[self.atomicNumber].eConfig:
            if (some_shell.energy_level == -1):
                continue
            for some_subshell in range(1, len(some_shell.subshells)):
                if not some_shell.subshells[some_subshell].occupied:
                    continue
                info += str(some_shell.energy_level) +  str(some_shell.subshells[some_subshell].identifier) + str(some_shell.subshells[some_subshell].occupied)
                info += " "
        return info + '\n\n'
