//
// Created by mufengjun260 on 17-10-24.
//

#include "SimilarPortion.h"

using namespace std;

/**
 * 根据矩阵得出相似度
 * @param resultSaver 存储矩阵
 * @param m 共有m行，为被测样本
 * @param n 矩阵共有n列，为样本库
 * @return  相似度，被测样本中在样本库中检索到的token数/被测样本中总token数
 */
double SimilarPortion::similarPortion(MatrixSaver *matrixSaver, int m, int n) {
    int totalSimilarLine;
    totalSimilarLine = 0;
    int totalLine;
    totalLine = 0;

    for (int i = 0; i <= m; i++) {
        totalLine++;
        for (int j = 0; j <= n; j++) {
            //std::cout << resultSaver->getLocation(i, j, m, n + 1);
            if (matrixSaver->getLocation(i, j, m, n + 1) == 1) {
                totalSimilarLine++;
                break;
            }
        }
    }

    return totalLine == 0 ? -1 : (double) totalSimilarLine / totalLine;
}
