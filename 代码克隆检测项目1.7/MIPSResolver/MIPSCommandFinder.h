//
// Created by mufengjun260 on 4/8/18.
//

#ifndef ICESHAVER_MIPSCOMMANDFINDER_H
#define ICESHAVER_MIPSCOMMANDFINDER_H

#include <iostream>
#include "MIPSCommandFinder.h"

using namespace std;

class MIPSCommandFinder {
public:
	int getCommandOffset(string tmpLine);

	int contentCommand(string tmpLine);
};


#endif //ICESHAVER_MIPSCOMMANDFINDER_H
