//
// Created by mufengjun260 on 18-1-28.
//

#ifndef ICESHAVER_FUNCTIONRESOLVER_H
#define ICESHAVER_FUNCTIONRESOLVER_H

#include <string>
#include <fstream>
#include <iostream>
#include "FunctionAnalyzer.h"
#include "MIPSResolverUtil.h"

using namespace std;

class FunctionCutter {
public:
	string
	cutBinaryFunction(string binaryFilePath, string funcName, string funcAddr, string funcSize, string sectionAddr,
	                  string sectionOffset);

	string cutByByte(string binaryFilePath, string outputPath, long offset, int size);

	void TEST();
};


#endif //ICESHAVER_FUNCTIONRESOLVER_H
