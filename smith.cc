#include "smithCounter.h"
#include <iostream>
#include <istream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
using namespace csci5814;

int main() {

  smithCounter counter;

  counter.predictor();
  counter.percentage();

  cout << "Number of Branches: " << counter.getTotalBranches() << endl;
  cout << "Number of branches taken: " << counter.getBranchTaken() << endl;
  cout << "Number of taken branches correctly predicted: " << counter.getCountTaken() << endl;
  cout << "Number of branches not taken: " << counter.getBranchNotTaken() << endl;
  cout << "Number of not taken branches correctly predicted: " << counter.getCountNotTaken() << endl;
  cout << "Overall rate of correct predictions: " << counter.getCorrectPercent() << endl;

  return 0;
}
