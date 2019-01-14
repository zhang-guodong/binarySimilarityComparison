//
// Created by mufengjun260 on 4/23/18.
//

#ifndef SUFFIXTREERESOLVER_SUFFIXTREEMATCH_H
#define SUFFIXTREERESOLVER_SUFFIXTREEMATCH_H


#include <vector>
#include "MatchSaver.h"

class SuffixTreeMatch {
	vector<MatchSaver>
	getMatchResult(vector<int> matchVector, vector<int> targetVector, string matchFilePath,
	               string targetFilePath,
	               int BML);
};


#endif //SUFFIXTREERESOLVER_SUFFIXTREEMATCH_H
