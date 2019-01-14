//
// Created by mufengjun260 on 17-10-13.
//

#include "MatrixSaver.h"

MatrixSaver::MatrixSaver() {

}

/**
 * 添加bool到本类实例化的对象的vector中
 * @param isSame
 * @return 无
 */
int MatrixSaver::push_back(bool isSame) {
    vector.push_back(isSame);
}


bool MatrixSaver::getLocation(int i, int j, int m, int n) {
    int x;
    x = i * n + j;
    return vector.at(x);
}

/**
 * 格式化输出本类的实例
 * @param m 所要输出的行数
 * @param n 所要输出的列数
 * @return
 */

int MatrixSaver::output(int m, int n) {
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            //std::cout << this->getLocation(i, j, m, n + 1);
        }
        //std::cout << std::endl;
    }
    return 0;
}

int MatrixSaver::fileOutput(int m, int n, std::string filePath) {
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            //std::cout << this->getLocation(i, j, m, n + 1);
        }
        //std::cout << std::endl;
    }
    return 0;
}