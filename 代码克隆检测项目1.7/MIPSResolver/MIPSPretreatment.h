//
// Created by mufengjun260 on 18-1-25.
//

#ifndef ICESHAVER_MIPSPRETREATMENT_H
#define ICESHAVER_MIPSPRETREATMENT_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class MIPSPretreatment {

public:
	string getSection(string filePath);

	string getTable(string filePath);

	string getDump(string filePath);
};


#endif //ICESHAVER_MIPSPRETREATMENT_H
