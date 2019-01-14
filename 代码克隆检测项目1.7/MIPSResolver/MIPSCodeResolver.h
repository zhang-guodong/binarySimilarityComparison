//
// Created by mufengjun260 on 18-2-3.
//

#ifndef ICESHAVER_MIPSTOKENGENERATER_H
#define ICESHAVER_MIPSTOKENGENERATER_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>


using namespace std;

class MIPSCodeResolver {
public:
	string resolveMIPSCode(string dumpFilePath);

	vector<string> resolveAllMIPSCode(vector<string> dumpFilePaths);

	vector<bitset<12>> readCodeFromFile(string filePath);
};


#endif //ICESHAVER_MIPSTOKENGENERATER_H
