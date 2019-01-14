//
// Created by mufengjun260 on 17-10-27.
//

#ifndef ICESHAVER_PRETREATMENT_H
#define ICESHAVER_PRETREATMENT_H

#include <string>
#include "TextPartParser.h"

using namespace std;

class Pretreatment {
public:
	vector<string> pretreatMIPSBinaryFile(string binaryPath);

	vector<string> pretreatX86BinaryFile(string binaryPath);

};


#endif //ICESHAVER_PRETREATMENT_H
