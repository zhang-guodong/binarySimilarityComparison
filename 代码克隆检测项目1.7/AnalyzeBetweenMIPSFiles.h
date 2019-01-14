//
// Created by mufengjun260 on 17-10-26.
//

#ifndef ICESHAVER_ANALYZETHROUGHTWOMIPSFILES_H
#define ICESHAVER_ANALYZETHROUGHTWOMIPSFILES_H

#include <string>
#include <iomanip>
#include "Levenshtein.h"
#include "SuffixTreeResolver.h"
#include <bitset>

class AnalyzeBetweenMIPSFiles {
public:
    double
    analyzeBetweenMIPSFiles(std::string filePath1, std::string filePath2, int gramSize, int ISM,
                            int windowLength,
                            string resultPath);

    string intToString(int tmpInt);
    string doubleToString(double tmpDouble);

private:
    float sandRatio;
public:
	float getSandRatio() const;

	void setSandRatio(float sandRatio);
};


#endif //ICESHAVER_ANALYZETHROUGHTWOMIPSFILES_H
