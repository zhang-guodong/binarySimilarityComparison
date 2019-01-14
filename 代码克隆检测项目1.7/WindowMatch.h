//
// Created by mufengjun260 on 17-12-22.
//

#ifndef ICESHAVER_WINDOWMATCH_H
#define ICESHAVER_WINDOWMATCH_H


#include <vector>
#include <algorithm>
#include <iostream>
#include "MatchSaver.h"
#include <bitset>

class WindowMatch {
public:
	vector<MatchSaver>
	getMatchMIPSResult(vector<int> matchVector, vector<int> targetVector, string matchFilePath,
	                   string targetFilePath,
	                   int windowStep, int windowLength);

	vector<MatchSaver>
	getMatchX86Result(vector<int> matchVector, vector<int> targetVector, string matchFilePath, string targetFilePath,
	                  int windowStep, int windowLength);

	vector<MatchSaver>
	getMatchJavaResult(vector<int> matchVector,vector<int> targetVector,string matchFilePath,string targetFilePath,int windowStep,int windowLength);
	double getRatio(vector<MatchSaver>);

	bool isSand(int matchStartLine1, int matchEndLine1, int matchStartLine2, int matchEndLine2, int targetStartLine1,
	            int targetEndLine1, int targetStartLine2, int targetEndLine2, float sandRatio);

private:
	float sandRatio;
public:
	float getSandRatio() const;

	void setSandRatio(float sandRatio);
};


#endif //ICESHAVER_WINDOWMATCH_H
