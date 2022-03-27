#pragma once 
#include <bits/stdc++.h>
using namespace std;
// one of {s, p, d, f}
class subshell {
  public:
    int energyLevel, capacity, occupied = 0;
    char identifier;
    subshell(int, int);
};