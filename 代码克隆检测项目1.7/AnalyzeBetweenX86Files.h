//
// Created by mufengjun260 on 18-2-28.
//

#ifndef ICESHAVER_ANALYZEBETWEENX86FILES_H
#define ICESHAVER_ANALYZEBETWEENX86FILES_H

#include <string>
#include <iomanip>
#include "Levenshtein.h"

class AnalyzeBetweenX86Files {
public:
	double
	analyzeBetweenX86Files(std::string filePath1, std::string filePath2, int gramSize, int windowStep, int windowLength,
	                    string resultPath);

	string intToString(int tmpInt);
	string doubleToString(double tmpDouble);

private:
	float sandRatio;
public:
	float getSandRatio() const;

	void setSandRatio(float sandRatio);
};



#endif //ICESHAVER_ANALYZEBETWEENX86FILES_H
