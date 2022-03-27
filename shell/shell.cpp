#include "shell.h"
shell::shell(int k) {
  energyLevel = k;
  // there are only 4 maxmimum subshells possible, and so the min() function takes care of this for smaller and larger i
  for (int i = 1; i <= min(k, 4); i++) 
    subshells.push_back(subshell(i, i));
}
// get sum for each subshell
int shell::occupied(int whichLevel) { 
  return subshells[whichLevel].occupied;
}
// sum of all the total electrons in all subshells of a particular shell 
int shell::howMany() {  
  int sum = 0;
  for (int i = 1; i < subshells.size(); i++)
    sum += occupied(i);
  return sum;
}
// returns number of electrons in the valence shell 
int shell::valence() { 
  return occupied(energyLevel);
}