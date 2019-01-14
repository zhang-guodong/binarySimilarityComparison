//
// Created by mufengjun260 on 17-10-27.
//

#ifndef ICESHAVER_SYMBOLTABLEPARSER_H
#define ICESHAVER_SYMBOLTABLEPARSER_H

#include <string>
#include <fstream>
#include <vector>
#include "CommandFinder.h"
#include <sys/stat.h>
#include <sys/types.h>


using namespace std;

class TextPartParser {
public:
    vector<string> parse(string textPath);
};


#endif //ICESHAVER_SYMBOLTABLEPARSER_H
