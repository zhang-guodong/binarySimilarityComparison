//
// Created by mufengjun260 on 17-11-14.
//

#ifndef ICESHAVER_FILENAMEGENERATOR_H
#define ICESHAVER_FILENAMEGENERATOR_H

#include <string>
#include <vector>

using namespace std;

class FileNameGenerator {
public:
    static vector<string> getCorrespondFileName(string thisFileName, vector<string> binaryVector);
};


#endif //ICESHAVER_FILENAMEGENERATOR_H
