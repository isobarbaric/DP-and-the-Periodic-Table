#pragma once 
#include "../subshell/subshell.h"
class shell { 
  public:
    int energyLevel = -1;
    // one element is already put in this container so that 1-based indexing can be used 
    vector<subshell> subshells = {subshell(-1, -1)}; 
    shell(int);
    int occupied(int);
    int howMany();
    int valence();
};