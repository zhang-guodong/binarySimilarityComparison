//
// Created by mufengjun260 on 17-10-29.
//

#ifndef ICESHAVER_COMMANDFINDER_H
#define ICESHAVER_COMMANDFINDER_H

#include <string>
#include <vector>
#include <fstream>


using namespace std;

class CommandFinder {
public:
	int getCommandOffset(string filePath);

private:
	int contentCommand(string tmpLine);
};


#endif //ICESHAVER_COMMANDFINDER_H
