#include "smithCounter.h"
#include <iostream>
#include <iomanip>
#include <istream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

//Sean Blucker

using namespace std;

namespace csci5814
{
    SmithCounter::SmithCounter()
    {
        prediction = 0;
    }

    bool SmithCounter::getPrediction()
    {
        return prediction >> 1;
    }

    void SmithCounter::updatePrediction(string takenBranch)
    {
        if(takenBranch == "T" and prediction < 3)
            prediction++;
        else if(prediction > 0)
            prediction--;
    }

}
