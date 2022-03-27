#include "element.h"
extern vector<element> periodicTable;
vector<pair<int, int>> aufbau = { // stores {shell, subshell} where {s : 1, p : 2, d : 3, f : 4}
  {1, 1}, {2, 1}, {2, 2}, {3, 1}, {3, 2}, {4, 1}, {3, 3}, {4, 2}, {5, 1}, {4, 3}, {5, 2}, {6, 1}, {4, 4}, {5, 3}, {6, 2}, {7, 1}, {5, 4}, {6, 3}, {7, 2}, {8, 1}, {6, 4}, {7, 3}, {8, 2}, {7, 4}
};
void element::baseCase() { // electron configuration for H, He
  int electronsLeft = electrons;
  // iterating through aufbau in the order that we need to fill electrons whilst also making sure we have a non-negative number of electrons
  for (int location = 0; location < aufbau.size() && electronsLeft > 0; location++) {
    int currentShell = aufbau[location].first; 
    int currentSubshell = aufbau[location].second;
    // in every possible iteration, the shell and subshell that is used is noted so that in the future, if this element is a noble gas, then this particular information can be used to generate the next period on the periodic table 
    lastIndexAufbau = location;
    // check to see if we can add any electrons at this particular shell and subshell (only possible cases are there are electrons to be added OR there are no electrons to be added)
    if (eConfig[currentShell].subshells[currentSubshell].capacity > eConfig[currentShell].subshells[currentSubshell].occupied) { 
      // electronsToAdd > 0 is guaranteed by if statement
      int electronsToAdd = eConfig[currentShell].subshells[currentSubshell].capacity-eConfig[currentShell].subshells[currentSubshell].occupied;
      if (electronsLeft >= electronsToAdd) { 
        electronsLeft -= electronsToAdd;
        eConfig[currentShell].subshells[currentSubshell].occupied = eConfig[currentShell].subshells[currentSubshell].capacity;
      } else {
        eConfig[currentShell].subshells[currentSubshell].occupied += electronsLeft;
        electronsLeft = 0;
      }
    }
  }
}
void element::filler() { // electron configuration for all elements other than H, He
  // trying to find the largest noble gas before the current element 
  for (int j = atomicNumber-1; j >= 0; j--) {
    if (periodicTable[j].nobleGas) {
      nearestNobleGas = j;
      break;
    }
  }
  eConfig = periodicTable[nearestNobleGas].eConfig;
  // the number of electrons that have to be added on top of those present in the noble gas already can be found by subtraction
  int electronsLeft = electrons - (nearestNobleGas + 1);
  // given the location where the previous noble gas stopped, the current element picks up that location and then fills electrons starting from there
  for (int location = periodicTable[nearestNobleGas].lastIndexAufbau; location < aufbau.size() && electronsLeft > 0; location++) {
    int currentShell = aufbau[location].first;
    int currentSubshell = aufbau[location].second;
    // in every possible iteration, the shell and subshell that is used is noted so that in the future, if this element is a noble gas, then this particular information can be used to generate the next period on the periodic table 
    lastIndexAufbau = location; 
    // check to see if we can add any electrons at this particular shell and subshell (only possible cases are there are electrons to be added OR there are no electrons to be added)
    if (eConfig[currentShell].subshells[currentSubshell].occupied < eConfig[currentShell].subshells[currentSubshell].capacity) {
      // electronsToAdd  > 0 is guaranteed by if statement
      int electronsToAdd = eConfig[currentShell].subshells[currentSubshell].capacity-eConfig[currentShell].subshells[currentSubshell].occupied;
      if (electronsLeft >= electronsToAdd) { 
        electronsLeft -= electronsToAdd;
        eConfig[currentShell].subshells[currentSubshell].occupied = eConfig[currentShell].subshells[currentSubshell].capacity;
      } else {
        eConfig[currentShell].subshells[currentSubshell].occupied += electronsLeft;
        electronsLeft = 0;
      }
    }
  }
}
element::element(string Name, int aNumber) {
  name = Name;
  atomicNumber = aNumber;
  electrons = atomicNumber; 
  // the '+1' is a buffer just in case, otherwise only 8 shells are really needed  
  for (int energy_level = 1; energy_level <= 8+1; energy_level++)  
    eConfig.push_back(shell(energy_level));
  // Hydrogen and Helium are the base cases and so aufbau is simulated from the beginning for both of them, for other elements, dp can be used to get the electron configuration for the other elements 
  if (atomicNumber <= 2) baseCase();
  else filler();
}
void element::printer() { 
  cout << name << "\n";
  for (auto i : periodicTable[atomicNumber-1].eConfig) {
    if (i.energyLevel == -1) continue;
    for (int j = 1; j < i.subshells.size(); j++) {
      if (!i.subshells[j].occupied) continue;
      cout << i.energyLevel << i.subshells[j].identifier << i.subshells[j].occupied << " "; 
    }
  }
  cout << '\n';
}