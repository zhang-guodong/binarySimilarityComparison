//
// Created by mufengjun260 on 17-10-18.
//

#ifndef ICESHAVER_TONGRAMTOKEN_H
#define ICESHAVER_TONGRAMTOKEN_H


#include <vector>
#include <map>


using namespace std;

class ToNGramToken {
public:
    std::vector<int>
    toNGramToken(vector<int> normalTokenVector, map<vector<int>, int> &correspondence, int gramSize);
};


#endif //ICESHAVER_TONGRAMTOKEN_H
