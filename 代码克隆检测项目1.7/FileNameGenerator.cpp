//
// Created by mufengjun260 on 17-11-14.
//

#include "FileNameGenerator.h"

vector<string> FileNameGenerator::getCorrespondFileName(string thisFileName, vector<string> binaryVector) {
	vector<string> resultVector;
	string funcName = "";
	int thisLocation;
	for (int i = 0; i <= binaryVector.size() - 1; i++) {
		if (thisFileName.find(binaryVector[i]) != string::npos) {
			int begin = binaryVector[i].size();
			thisFileName = thisFileName.substr(begin, thisFileName.size() - begin + 1);
			funcName = thisFileName;
			thisLocation = i;
		}
	}

	for (int i = 0; i <= binaryVector.size() - 1; i++) {
		if (i != thisLocation) {
			resultVector.push_back(binaryVector[i] + funcName);
		}
	}
	return resultVector;
}
