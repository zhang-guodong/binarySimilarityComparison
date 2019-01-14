//
// Created by mufengjun260 on 4/5/18.
//

#ifndef ICESHAVER_TYPERESOLVER_H
#define ICESHAVER_TYPERESOLVER_H

#include <bitset>
#include <vector>
#include <map>
#include <string>

using namespace std;

class MIPSOperationResolver {
public:
	MIPSOperationResolver();

	vector<string> resolveAllOperation(string dumpFile);

	vector<int> readOperationFromFile(string operationFile);

private:
	map<string, int> instructionSet;
};


#endif //ICESHAVER_TYPERESOLVER_H
