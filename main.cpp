#include <fstream>
#include "json/json.h"
#include "element/element.h"
#define NUM_ELEMENTS 118
using namespace std;
vector<element> periodicTable; 
// map will be used to provide I/O functionality to switch from name to atomic number
map<string, int> nameToAtomicNumber;
void present() {
  for (auto e : periodicTable) 
    e.printer();
  cout << "\n\n";
}
int main() { 
  // set up stream for I/O with ptable.json located in the json directory
  ifstream ifs("json/ptable.json");
  // using JSONCpp to parse through ptable.json
  Json::Reader viewer;
  Json::Value target;
  viewer.parse(ifs, target);
  for (int i = 1; i <= 2; i++) { // anything more than 2 gets MLE, ideally 2 should be replaced with NUM_ELEMENTS
    // pushing a variable of type element into pTable that gets naming data from pTable.json using methods and structs from the JSONCpp library
    periodicTable.push_back(element(target["elements"][i-1]["name"].asString(), i));
    // if the element is a noble gas, then mark its nobleGas property as true 
    if (target["elements"][i-1]["category"].asString() == "noble gas") 
      periodicTable[periodicTable.size()-1].nobleGas = true;
    nameToAtomicNumber[target["elements"][i-1]["name"].asString()] = i;
  }
  // prints out the elements and electron configurations of the periodic table 
  present();
  // basic IO functionality to query with the data base 
  while (true) {
    cout << "Type # to continue with the program or press any other character to quit.\n";
    char execution; cin >> execution;
    if (execution != '#') break;
    // allowing for two types of input based on the needs of the user 
    cout << "Enter 0 if you want to provide an atomic number or 1 if you want to provide a name.\n";
    // invalid input check to ensure proper input is provided 
    int type1; 
    while (true) {
      cin >> type1;
      if (type1 == 0) break;
      if (type1 == 1) break; 
      cout << "Invalid input, please try again\n";
    }
    bool type2 = type1 == 1;
    // addressing each type of query separately, type 1 and type 2 
    if (type2) {
      string query;
      cin >> query;
      periodicTable[nameToAtomicNumber[query]-1].printer();
    } else {
      int query;
      cin >> query;
      periodicTable[query-1].printer();
    }
    cout << '\n';
  }
  return 0;
}