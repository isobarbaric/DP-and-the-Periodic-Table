#pragma once 
#include "../shell/shell.h"
class element {
  public:
    string name;
    int atomicNumber, electrons, lastIndexAufbau, nearestNobleGas;
    bool nobleGas = false;
    // one element is already put in this container so that 1-based indexing can be used
    vector<shell> eConfig = {shell(-1)};
    void baseCase();
    void filler();
    element(string, int);
    void printer();
};