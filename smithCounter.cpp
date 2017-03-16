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
          table[i] = 0;
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
        return ((double)(correctlyPredictedTakenBranches + correctlyPredictedNotTakenBranches)/(double)branches) * 100;
    }

    bool smithCounter::getPrediction(int counter)
    {
        if (table[(counter/4)%128] >= 2)
            return true;
        else
            return false;
    }

    void smithCounter::trackBranches()
    {
    	string branch;
    	string pathIdentifier;

    	ifstream input("branch_trace.dat");
    	bool counterValue;
    	bool takenPath;
    	int instruction;

    	while (getline(input,branch,' '))
       {
           if(input.eof())
           {
               break;
           }

    	   getline(input,pathIdentifier,'\n');
    	   instruction = atoi(branch.c_str());
    	   counterValue = getPrediction(instruction);

    	   if (pathIdentifier.find('T') != std::string::npos)
           {
               takenPath=true;
               branchTakenCount++;
           }
           else if (pathIdentifier.find('N') != std::string::npos)
           {
               takenPath=false;
               branchNotTakenCount++;
           }

           if (counterValue && takenPath)
           {
               correctlyPredictedTakenBranches++;

               if (table[(instruction/4)%128]==3)
               {
                   table[(instruction/4)%128]=3;
               }
               else
               {
                   table[(instruction/4)%128]++;
               }
           }
           else if (counterValue && !takenPath)
           {
               if (table[(instruction/4)%128]==0)
               {
                   table[(instruction/4)%128]=0;
               }
               else
               {
                   table[(instruction/4)%128]--;
               }
           }
           else if (!counterValue && !takenPath)
           {
               correctlyPredictedNotTakenBranches++;

               if (table[(instruction/4)%128]==0)
               {
                   table[(instruction/4)%128]=0;
               }
               else
               {
                   table[(instruction/4)%128]--;
               }
           }
           else if (!counterValue && takenPath)
           {
               if (table[(instruction/4)%128]==3)
               {
                   table[(instruction/4)%128]=3;
               }
               else
               {
                   table[(instruction/4)%128]++;
               }
           }

    		branches++;
    	}

    	input.close();
    }

}
