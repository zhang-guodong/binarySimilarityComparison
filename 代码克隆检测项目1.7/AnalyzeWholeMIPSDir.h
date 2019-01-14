//
// Created by mufengjun260 on 17-10-27.
//

#ifndef ICESHAVER_ANALYZEWHOLEMIPSDIR_H
#define ICESHAVER_ANALYZEWHOLEMIPSDIR_H

#include <string>
#include <map>
#include <vector>
#include "DirParser.h"
#include "Pretreatment.h"
#include "FileNameGenerator.h"

using namespace std;

class AnalyzeWholeMIPSDir {
public:
    map<vector<string>, double>
    analyzeMIPSDir(string dirPath, int gramSize, int windowStep, int windowLength, string resultPath);

private:
    float sandRatio;
public:
    float getSandRatio() const;

    void setSandRatio(float sandRatio);
};


#endif //ICESHAVER_ANALYZEWHOLEMIPSDIR_H
