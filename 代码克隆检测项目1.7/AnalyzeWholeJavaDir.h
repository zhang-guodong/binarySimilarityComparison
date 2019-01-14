//
// Created by mufengjun260 on 5/6/18.
//

#ifndef ICESHAVER_ANALYZEWHOLEJAVADIR_H
#define ICESHAVER_ANALYZEWHOLEJAVADIR_H

#include <string>
#include <map>
#include <vector>
#include "DirParser.h"
#include "FileNameGenerator.h"

using namespace std;

class AnalyzeWholeJavaDir {
public:
	map<vector<string>, double>
	analyzeJavaDir(string dirPath, int gramSize, int windowStep, int windowLength, string resultPath);

	float getSandRatio() const;

	void setSandRatio(float sandRatio);

private:
	float sandRatio;
};


#endif //ICESHAVER_ANALYZEWHOLEJAVADIR_H
