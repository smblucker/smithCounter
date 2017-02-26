#include "smithCounter.h"
#include <iostream>
#include <istream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

namespace csci5814
{
    smithCounter::smithCounter()
    {
        int totalBranches = 0;		// Total # of Branches
        int branchTaken = 0;		// # of branches taken
        int branchNotTaken = 0;		// # of branches not taken
        int countTaken = 0;		// # of branches taken correctly
        int countNotTaken = 0;		// # of branches not taken correctly
        double correctPercent = 0;		// % correctly predicted

        for (int i=0; i < 64; i++)
        {
          table[i] = 2;
        }
    }

    int smithCounter::getTotalBranches()
    {
        return totalBranches;
    }

    int smithCounter::getBranchTaken()
    {
        return branchTaken;
    }

    int smithCounter::getBranchNotTaken()
    {
        return branchNotTaken;
    }

    int smithCounter::getCountTaken()
    {
        return countTaken;
    }

    int smithCounter::getCountNotTaken()
    {
        return countNotTaken;
    }

    double smithCounter::getCorrectPercent()
    {
        return correctPercent;
    }

    bool smithCounter::checkhash(int b)
    {
        if (table[b%64] < 2)
          return true;
        else
          return false;
    }

    void smithCounter::predictor()
    {
        string branch;		// string from file
        string path;			// path from file taken-not taken
        bool previousPath = true;	// keeps track of prev path actions

        ifstream line("branch_trace.dat");

        bool takenPath;
        bool hashed;
        int instruction;
        int switchcase;

        while (getline(line, branch, ' '))
        {
          getline(line, path, '\n');
          instruction = atoi(branch.c_str());
          hashed = checkhash(instruction);

          if (path == "T")
            takenPath = true;
          else
            takenPath = false;

          if (hashed)
            branchTaken++;
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

          switch(switchcase)
          {
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

        line.close();
    }

    void smithCounter::percentage()
    {
        int totalCountCorrect;
        totalCountCorrect = countTaken + countNotTaken;
        correctPercent = (totalCountCorrect / totalBranches) * 100;
    }
}
