//
// Created by mufengjun260 on 4/23/18.
//

#ifndef ICESHAVER_SUFFIXTREERESOLVER_H
#define ICESHAVER_SUFFIXTREERESOLVER_H

#include <string>
#include <iostream>
#include <vector>
#include <SuffixTree.h>
#include "MatchSaver.h"

class SuffixTreeResolver {
public:
	SuffixTree buildSuffixTree(vector<int> plain);

	vector<MatchSaver> getCompareResult(vector<int> matchVector, vector<int> targetVector, string matchFilePath,
	                                    string targetFilePath, int BML, int instructionSetMax);
};


#endif //ICESHAVER_SUFFIXTREERESOLVER_H
