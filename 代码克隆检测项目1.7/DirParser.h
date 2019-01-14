//
// Created by mufengjun260 on 17-10-26.
//

#ifndef ICESHAVER_DIRTRAVERSAL_H
#define ICESHAVER_DIRTRAVERSAL_H

#include <string>
#include <vector>
#include <unistd.h>
#include <algorithm>
#include <dirent.h>
#include <cstring>
#include <iostream>
#include <map>
#include "AnalyzeBetweenMIPSFiles.h"

using namespace std;

class DirParser {
public:
    vector<string> getFiles(string dirPath);
};


#endif //ICESHAVER_DIRTRAVERSAL_H
