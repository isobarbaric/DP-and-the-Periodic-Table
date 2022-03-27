#include "subshell.h"
subshell::subshell(int origin, int which) {
  energyLevel = origin;
  // checks to make sure that this is not the case of the one-indexed dummy element
  if (origin != -1) { 
    switch (which) { 
      case 1: 
        capacity = 2;
        identifier = 's';
        break;
      case 2:
        capacity = 6;
        identifier = 'p';
        break;
      case 3:
        capacity = 10;
        identifier = 'd';
        break;
      case 4:
        capacity = 14;
        identifier = 'f';
        break;
    }
  }
}