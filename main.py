
from components.element import element
from components.data_manip import extractor

class periodicTable:
    NUM_ELEMENTS = 119

    def __init__(self):
        self.pTable = [-1]
        self.pTableNames = extractor()
        self.nameToAtomicNumber = dict()

    def present(self):
        for i in range(1, self.NUM_ELEMENTS+1):
            print(self.pTable[i])

    def process(self):
        for i in range(1, self.NUM_ELEMENTS+1):
            currentElement = element(self.pTableNames[i][0], i, self.pTable)
            if (self.pTableNames[i][1] == "noble gas"):
                currentElement.nobleGas = True
            self.nameToAtomicNumber[self.pTableNames[i][0]] = i
            self.pTable.append(currentElement)

    def main(self):
        self.process()
        self.present()

PeriodicTable = periodicTable()
PeriodicTable.main()