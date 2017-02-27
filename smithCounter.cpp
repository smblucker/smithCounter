#include "smithCounter.h"
#include <iostream>
#include <iomanip>
#include <istream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

namespace csci5814
{
    smithCounter::smithCounter()
    {
        int branches = 0;
        int branchTakenCount = 0;
        int correctlyPredictedTakenBranches = 0;
        int branchNotTakenCount = 0;
        int correctlyPredictedNotTakenBranches = 0;

        for (int i=0; i < 150; i++)
        {
          table[i] = 2;
        }
    }

    int smithCounter::getBranches()
    {
        return branches;
    }

    int smithCounter::getBranchTakenCount()
    {
        return branchTakenCount;
    }

    int smithCounter::getCorrectlyPredictedTakenBranches()
    {
        return correctlyPredictedTakenBranches;
    }

    int smithCounter::getBranchNotTakenCount()
    {
        return branchNotTakenCount;
    }

    int smithCounter::getCorrectlyPredictedNotTakenBranches()
    {
        return correctlyPredictedNotTakenBranches;
    }

    double smithCounter::getPercent()
    {
        double branchC = correctlyPredictedTakenBranches + correctlyPredictedNotTakenBranches;
    	  double totalBranches = branches;
        return (branchC/totalBranches) * 100;
    }

    bool smithCounter::checkHash(int b)
    {
        if (table[b%64] < 2)
          return false;
        else
          return true;
    }

    void smithCounter::trace()
    {
      bool lastPath = true;
    	string branch;
    	string takeuntake;

    	ifstream input("branch_trace.dat");
    	bool hashed;
    	bool correctpath;
    	int instruction;
    	int switchcase;

    	while (getline(input,branch,' '))
      {
    		getline(input,takeuntake,'\n');
    		instruction = atoi(branch.c_str());
    		hashed = checkHash(instruction);

    		if (takeuntake == "T")
        {
          correctpath=true;
        }
        else
          correctpath=false;

    		if (hashed)
        {
          branchTakenCount++;
        }

		    if (!hashed)
        {
          branchNotTakenCount++;
        }

    		if (hashed && correctpath)
        {
          switchcase=0;
        }
    		else if (hashed && !correctpath)
        {
          switchcase=1;
        }
    		else if ( !hashed && !correctpath)
        {
          switchcase=2;
        }
    		else if ( !hashed && correctpath)
        {
          switchcase=3;
        }

    		switch(switchcase)
        {
        	case 0:
           	 correctlyPredictedTakenBranches++;
    				 table[instruction%64]++;
           	 break;
        	case 1:
          		table[instruction%64]--;
           		break;
        	case 2:
          		correctlyPredictedNotTakenBranches++;
    				  table[instruction%64]--;
           		break;
        	case 3:
          		table[instruction%64]++;
           		break;
    		}

    		branches++;
    	}

    	input.close();
    }

}
