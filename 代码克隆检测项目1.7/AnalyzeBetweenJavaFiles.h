//
// Created by mufengjun260 on 5/6/18.
//

#ifndef ICESHAVER_ANALYZEBETWEENJAVAFILES_H
#define ICESHAVER_ANALYZEBETWEENJAVAFILES_H


#include <string>
#include <SuffixTreeResolver/SuffixTreeResolver.h>
#include <fstream>
#include <JAVAResolver/JavaResolver.h>
#include <sstream>
#include <iomanip>
#include "WindowMatch.h"

using namespace std;


class AnalyzeBetweenJavaFiles {
public:
	double
	analyzeBetweenJavaFiles(std::string filePath1, std::string filePath2, int gramSize, int ISM,
	                        int windowLength,
	                        std::string resultPath);

	string intToString(int tmpInt);

	string doubleToString(double tmpDouble);
};


#endif //ICESHAVER_ANALYZEBETWEENJAVAFILES_H
