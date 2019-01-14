//
// Created by mufengjun260 on 18-2-28.
//

#ifndef ICESHAVER_ANALYZEWHOLEX86DIR_H
#define ICESHAVER_ANALYZEWHOLEX86DIR_H

#include <string>
#include <map>
#include <vector>
#include "DirParser.h"
#include "Pretreatment.h"
#include "FileNameGenerator.h"
#include "AnalyzeBetweenX86Files.h"

using namespace std;

class AnalyzeWholeX86Dir {
public:
	map<vector<string>, double>
	analyzeX86Dir(string dirPath, int gramSize, int windowStep, int windowLength, string resultPath);

private:
	float sandRatio;
public:
	float getSandRatio() const;

	void setSandRatio(float sandRatio);
};


#endif //ICESHAVER_ANALYZEWHOLEX86DIR_H
