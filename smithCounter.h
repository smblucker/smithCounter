#ifndef SMITHCOUNTER_H
#define	SMITHCOUNTER_H

//Sean Blucker

#include<string>

namespace csci5814
{
    class SmithCounter
    {
    private:
        int prediction;
    public:
        SmithCounter();
        bool getPrediction();
        void updatePrediction(std::string takenBranch);
    };
}


#endif
