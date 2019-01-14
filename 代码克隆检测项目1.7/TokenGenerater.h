//
// Created by mufengjun260 on 17-10-7.
//

#ifndef ICESHAVER_TOKENGENERATER_H
#define ICESHAVER_TOKENGENERATER_H


#include <fstream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class TokenGenerater {
public:
    vector<int> tokenGenerater(string file,map<std::string,int > &correspondence);
};


#endif //ICESHAVER_TOKENGENERATER_H
