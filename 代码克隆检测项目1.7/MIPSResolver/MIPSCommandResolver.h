//
// Created by mufengjun260 on 18-1-31.
//

#ifndef ICESHAVER_MIPSCOMMANDANALYZER_H
#define ICESHAVER_MIPSCOMMANDANALYZER_H

#include <string>
#include <vector>
#include <fstream>
#include <bitset>

using namespace std;

class MIPSCommandResolver {
public:
	vector<string> resolveAllMIPSCommand(vector<string> functionFilePaths);

	string resolveMIPSCommand(string functionFilePath);
};


#endif //ICESHAVER_MIPSCOMMANDANALYZER_H
