//
// Created by zhanggd on 18-1-24.
//

#ifndef BINARYSIMILARITYCOMPARISON_MAPOFMIPSINSTRUCTIONSET_H
#define BINARYSIMILARITYCOMPARISON_MAPOFMIPSINSTRUCTIONSET_H

#include <map>
#include <iostream>

using namespace std;

extern map<string, int> MIPSMnemonic;

int mnemonic2Num(string mnemonic);

#endif //BINARYSIMILARITYCOMPARISON_MAPOFMIPSINSTRUCTIONSET_H
