//
// Created by mufengjun260 on 18-1-31.
//

#ifndef ICESHAVER_FUNCTIONANALYZER_H
#define ICESHAVER_FUNCTIONANALYZER_H

#include <string>
#include "FunctionCutter.h"
#include "TableAnalyzer.h"
#include "SectionAnalyzer.h"
#include "MIPSPretreatment.h"
using namespace std;

extern string FUNCPath, DUMPPath, TOKENPath, binaryFilePath;

class FunctionAnalyzer {
public:
	vector<string> analyzeFunction(string binaryFilePath);
};

#endif //ICESHAVER_FUNCTIONANALYZER_H
