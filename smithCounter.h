#ifndef SMITHCOUNTER_H
#define	SMITHCOUNTER_H

namespace csci5814
{
    class smithCounter
    {
    private:
        int branches;
        int branchTakenCount;
        int correctlyPredictedTakenBranches;
        int branchNotTakenCount;
        int correctlyPredictedNotTakenBranches;
        int table[150];
    public:
        smithCounter();
        int getBranches();
        int getBranchTakenCount();
        int getCorrectlyPredictedTakenBranches();
        int getBranchNotTakenCount();
        int getCorrectlyPredictedNotTakenBranches();
        double getPercent();
        bool checkHash(int b);
        void trace();
    };
}


#endif
