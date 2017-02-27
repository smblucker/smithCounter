#include "smithCounter.h"
#include <iostream>
#include <iomanip>
#include <istream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
using namespace csci5814;

int main(){

	smithCounter counter;
	counter.trace();

	cout << "Number of branches: " << counter.getBranches() << endl;
	cout << "Number of branches taken: " << counter.getBranchTakenCount() << endl;
	cout << "Number taken branches correctly predicted: " << counter.getCorrectlyPredictedTakenBranches() << endl;
	cout << "Number of branches not taken: " << counter.getBranchNotTakenCount() << std::endl;
	cout << "Number not taken branches correctly predicted: " << counter.getCorrectlyPredictedNotTakenBranches() << endl;
	cout << "Overall rate of correct predictions: " << counter.getPercent() << "%" << endl;

	return 0;
}
