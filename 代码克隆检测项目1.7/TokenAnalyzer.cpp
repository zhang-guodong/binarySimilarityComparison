//
// Created by mufengjun260 on 17-10-13.
//

#include "TokenAnalyzer.h"

/**
 * 输入两个vector，进行比较后生成matrix，存储后返回
 * @param fileVector1 列所在的vector
 * @param fileVector2 行所在的vector
 * @return 比较后的结果存储器
 */
MatrixSaver TokenAnalyzer::tokenAnalyzer(std::vector<int> fileVector1, std::vector<int> fileVector2) {
    MatrixSaver matrixSaver;

    //递归生成位比对结果，压入vector
    for (int i = 0; i < fileVector1.size(); i++) {
        int x = fileVector1.size();
        for (int j = 0; j < fileVector2.size(); j++) {
            bool tmpBool = fileVector1[i] == fileVector2[j];
            matrixSaver.push_back(tmpBool);
        }
    }

    return matrixSaver;
}
