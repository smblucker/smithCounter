#ifndef SMITHCOUNTER_H
#define	SMITHCOUNTER_H

namespace csci5814
{
    class smithCounter
    {
    private:
        int table[64];
        int totalBranches;		// Total # of Branches
        int branchTaken;		// # of branches taken
        int branchNotTaken;		// # of branches not taken
        int countTaken;		// # of branches taken correctly
        int countNotTaken;		// # of branches not taken correctly
        double correctPercent;		// % correctly predicted
    public:
        smithCounter();
        int getTotalBranches();
        int getBranchTaken();
        int getBranchNotTaken();
        int getCountTaken();
        int getCountNotTaken();
        double getCorrectPercent();
        bool checkhash(int b);
        void predictor();
        void percentage();
    };
}


#endif
