//
// Created by zhanggd on 18-1-25.
//

#ifndef BINARYSIMILARITYCOMPARISON_RABINKARPALGORITHM_H
#define BINARYSIMILARITYCOMPARISON_RABINKARPALGORITHM_H

#include <iostream>

using namespace std;
#define PROGRESSIVE 16    //整数串采用的进制
#define STEP 3            //一个助记符特征对应的整数数目
#define FINGERSIZE 256    //指纹库大小

int getFingerprint(int *stringInt, int windowSize);

int cmpStringIntExact(int *stringInt1, int *stringInt2, int windowSize);

int cmpStringInt(int *stringInt1, int *stringInt2, int windowSize);

#endif //BINARYSIMILARITYCOMPARISON_RABINKARPALGORITHM_H
