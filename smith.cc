#include <iostream>
#include <istream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int table[64];
int totalBranches = 0;		// Total # of Branches
int branchTaken = 0;		// # of branches taken
int branchNotTaken = 0;		// # of branches not taken 
int countTaken = 0;		// # of branches taken correctly
int countNotTaken = 0;		// # of branches not taken correctly
double correctPercent;		// % correctly predicted

int main() {
  
  for (i=0; i < 64; i++) {
    table[i] = 2;
  }

  predictor();
  percentage();

  cout << "Number of Branches: " << totalBranches << endl;
  cout << "Number of branches taken: " << branchTaken << endl;
  cout << "Number of taken branches correctly predicted: " << countTaken << endl;
  cout << "Number of branches not taken: " << branchNotTaken << endl;
  cout << "Number of not taken branches correctly predicted: " << countNotTaken << endl;
  cout << "Overall rate of correct predictions: " << correctPercent << endl;

  return 0;
}


void predictor() {
  string branch;		// string from file
  string path;			// path from file taken-not taken
  bool previousPath = true;	// keeps track of prev path actions
  
  ifstream line("branch_trace.dat");
  bool takenPath;
  bool hashed;
  int instruction;
  int switchcase;

  while (getline(line, branch, ' ')) {
    getline(line, path, '\n');
    instruction = atoi(branch.c_str());
    hashed = checkhash(instruction);
   
    if (path == "T")
      takenPath = true;
    else 
      takenPath = false;

    if (hashed)
      branchtaken++;
    if (!hashed)
      branchNotTaken++;

    if (hashed && takenPath)
      switchcase = 0;
    else if (hashed && !takenPath)
      switchcase = 1;
    else if (!hashed && takenPath)
      switchcase = 2;
    else if (!hashed && !takenPath)
      switchcase = 3;

    switch(switchcase) {
      case 0:
        countTaken++;
        table[instruction%64]++;
        break;

      case 1:
        table[instruction%64]--;
        break;

      case 2:
        table[instruction%64]++;
        break;

      case 3:
        countNotTaken++;
        table[instruction%64]--;
        break;
    }
    totalBranches++;
  }
  input.close();
}


bool checkhash(int b) {

  if (table[b%64] < 2)
    return true;
  else
    return false;
}


void percentage() {
  int totalCountCorrect;

  totalCountCorrect = countTaken + countNotTaken;
  correctPercent = (totalCountCorrect / totalBranches) * 100;
  
}


void
